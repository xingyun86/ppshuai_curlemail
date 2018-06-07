// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "aboutdlg.h"
#include "MainDlg.h"
#include "LoginUserDlg.h"

BOOL CMainDlg::PreTranslateMessage(MSG* pMsg)
{
	return CWindow::IsDialogMessage(pMsg);
}

BOOL CMainDlg::OnIdle()
{
	UIUpdateChildWindows();
	return FALSE;
}
HGLOBAL CMainDlg::OpenResource(LPVOID & lpData, DWORD & dwSize, LPCTSTR lpName, LPCTSTR lpType, HMODULE hModule/* = ::GetModuleHandle(NULL)*/)
{
	BOOL bResult = FALSE;
	HRSRC hRsrcRes = NULL;// handle/ptr. to res. info. in hSource 
	HGLOBAL hGLOBAL = NULL;// handle to loaded resource

	// Locate the resource in the source image file. 
	hRsrcRes = ::FindResource(hModule, lpName, lpType);
	if (hRsrcRes == NULL)
	{
		goto __LEAVE_CLEAN__;
	}

	////////////////////////////////////////////////////////////////////////////////////////////
	// See:https://msdn.microsoft.com/en-us/library/windows/desktop/ms648047(v=vs.85).aspx
	// A handle to the resource to be accessed. The LoadResource function returns this handle. 
	//Note that this parameter is listed as an HGLOBAL variable only for backward compatibility. 
	//Do not pass any value as a parameter other than a successful return value 
	//from the LoadResource function.

	// Load the resource into global memory. 
	hGLOBAL = ::LoadResource(hModule, hRsrcRes);
	if (hGLOBAL == NULL)
	{
		goto __LEAVE_CLEAN__;
	}

	// Lock the resource into global memory. 
	lpData = ::LockResource(hGLOBAL);
	if (lpData == NULL)
	{
		FreeResource(hGLOBAL);
		hGLOBAL = NULL;
		goto __LEAVE_CLEAN__;
	}

	dwSize = ::SizeofResource(hModule, hRsrcRes);

__LEAVE_CLEAN__:

	return hGLOBAL;
}
BOOL CMainDlg::ParseResrc(LPCTSTR ptszFileName, UINT uResourceID, LPCTSTR ptszTypeName, HMODULE hModule/* = ::GetModuleHandle(NULL)*/)
{
	DWORD dwSize = 0;
	HANDLE hFile = NULL;
	BOOL bResult = FALSE;
	LPVOID lpData = NULL;
	HGLOBAL hGlobal = NULL;
	DWORD dwNumberOfBytesWritten = 0;

	hGlobal = OpenResource(lpData, dwSize, MAKEINTRESOURCE(uResourceID), ptszTypeName, hModule);

	//我们用刚才得到的pBuffer和dwSize来做一些需要的事情。可以直接在内存中使
	//用，也可以写入到硬盘文件。这里我们简单的写入到硬盘文件，如果我们的自定
	//义资源是作为嵌入DLL来应用，情况可能要复杂一些。
	hFile = CreateFile(ptszFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile && hGlobal && dwSize > 0)
	{
		WriteFile(hFile, hGlobal, dwSize, &dwNumberOfBytesWritten, NULL);
		CloseHandle(hFile);

		bResult = TRUE;
	}

	return bResult;
}

LRESULT CMainDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	ParseResrc(_T(CACERTPEM_FILENAME), IDR_CACERTPEM, _T(CACERTPEM_FILENAME));
	ParseResrc(_T(PASSWORDDIC_FILENAME), IDR_PASSWORDDIC, _T(PASSWORDDIC_FILENAME));
	
	ReadPasswordDic();

	// center the dialog on the screen
	CenterWindow();

	// set icons
	HICON hIcon = AtlLoadIconImage(IDR_MAINFRAME, LR_DEFAULTCOLOR, ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON));
	SetIcon(hIcon, TRUE);
	HICON hIconSmall = AtlLoadIconImage(IDR_MAINFRAME, LR_DEFAULTCOLOR, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON));
	SetIcon(hIconSmall, FALSE);

	// register object for message filtering and idle updates
	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != NULL);
	pLoop->AddMessageFilter(this);
	pLoop->AddIdleHandler(this);

	UIAddChildWindowContainer(m_hWnd);

	LV_COLUMN lvc = { 0 };
	lvc.mask = LVCF_TEXT | LVCF_WIDTH;
	lvc.cx = 100;
	lvc.pszText = _T("用户账号");
	lvc.iSubItem = ((CListViewCtrl)GetDlgItem(IDC_LIST_LOGINUSER)).GetHeader().GetItemCount();
	((CListViewCtrl)GetDlgItem(IDC_LIST_LOGINUSER)).InsertColumn(lvc.iSubItem, &lvc);
	lvc.cx = 260;
	lvc.pszText = _T("邮箱地址");
	lvc.iSubItem = ((CListViewCtrl)GetDlgItem(IDC_LIST_LOGINUSER)).GetHeader().GetItemCount();
	((CListViewCtrl)GetDlgItem(IDC_LIST_LOGINUSER)).InsertColumn(lvc.iSubItem, &lvc);
	lvc.cx = 80;
	lvc.pszText = _T("状态");
	lvc.iSubItem = ((CListViewCtrl)GetDlgItem(IDC_LIST_LOGINUSER)).GetHeader().GetItemCount();
	((CListViewCtrl)GetDlgItem(IDC_LIST_LOGINUSER)).InsertColumn(lvc.iSubItem, &lvc);

	GetDlgItem(IDC_BUTTON_ADDLOGINUSR).SetWindowText(_T("新增账号"));
	GetDlgItem(IDOK).SetWindowText(_T("开始检测"));
	GetDlgItem(IDCANCEL).SetWindowText(_T("关闭程序"));
	GetDlgItem(ID_APP_ABOUT).SetWindowText(_T("关于"));
	SetWindowText(_T("邮件账户检测工具"));

	return TRUE;
}

LRESULT CMainDlg::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// unregister message filtering and idle updates
	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != NULL);
	pLoop->RemoveMessageFilter(this);
	pLoop->RemoveIdleHandler(this);

	// if UI is the last thread, no need to wait
	if(_Module.GetLockCount() == 1)
	{
		_Module.m_dwTimeOut = 0L;
		_Module.m_dwPause = 0L;
	}
	_Module.Unlock();

	return 0;
}

LRESULT CMainDlg::OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CAboutDlg dlg;
	dlg.DoModal();
	return 0;
}

/* This is a simple example using libcurl's POP3 capabilities to list the
* contents of a mailbox.
*
* Note that this example requires libcurl 7.20.0 or above.
*/

int CMainDlg::email_login(void * p)
{
	LV_ITEM lvi = { 0 };
	CURL * p_curl = NULL;
	size_t stPasswordIndex = 0;
	CEmailLoginParam elp = { 0 };
	CURLcode curl_result = CURLE_OK;
	CMainDlg * pThis = (CMainDlg*)p;
	_TCHAR tzResult[MAXCHAR] = { 0 };

	if (pThis)
	{
		pThis->m_mutex.lock();
		memcpy(&elp, &pThis->m_elpQueue.front(), sizeof(CEmailLoginParam));
		pThis->m_elpQueue.pop();
		pThis->m_mutex.unlock();

		//设置结果显示
		lvi.iItem = elp.nParamIndex;
		lvi.iSubItem = 2;
		lvi.mask = LVIF_TEXT;
		lvi.pszText = _T("验证中...");
		((CListViewCtrl)(pThis->GetDlgItem(IDC_LIST_LOGINUSER))).SetItem(&lvi);

		while (true)
		{
			p_curl = curl_easy_init();
			if (p_curl) {
				/* Set username and password */
				curl_easy_setopt(p_curl, CURLOPT_USERNAME, elp.szUserName);
				curl_easy_setopt(p_curl, CURLOPT_PASSWORD, elp.szPassWord);

				/* This will list every message of the given mailbox */
				//curl_easy_setopt(p_curl, CURLOPT_URL, "pop3s://pop.yeah.net");
				if (*elp.szEmailUrl)
				{
					*(elp.szEmailUrl + strlen(elp.szEmailUrl)) = '\x31';
					curl_easy_setopt(p_curl, CURLOPT_URL, elp.szEmailUrl);
					*(elp.szEmailUrl + strlen(elp.szEmailUrl) - 1) = '\x00';
				}

				/* If you want to connect to a site who isn't using a certificate that is
				* signed by one of the certs in the CA bundle you have, you can skip the
				* verification of the server's certificate. This makes the connection
				* A LOT LESS SECURE.
				*
				* If you have a CA cert for the server stored someplace else than in the
				* default bundle, then the CURLOPT_CAPATH option might come handy for
				* you. */
#ifdef SKIP_PEER_VERIFICATION
				curl_easy_setopt(p_curl, CURLOPT_SSL_VERIFYPEER, (0L));
#endif

				/* If the site you're connecting to uses a different host name that what
				* they have mentioned in their server certificate's commonName (or
				* subjectAltName) fields, libcurl will refuse to connect. You can skip
				* this check, but this will make the connection less secure. */
#ifdef SKIP_HOSTNAME_VERIFICATION
				curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, (0L));
#endif
				if (strstr(elp.szEmailUrl, ("s://")))
				{
					// we use a self-signed test server, skip verification during debugging
					curl_easy_setopt(p_curl, CURLOPT_SSL_VERIFYPEER, (1L));
					curl_easy_setopt(p_curl, CURLOPT_CAINFO, CACERTPEM_FILENAME);
				}

				/* Function that will be called to store the output (instead of fwrite). The
				* parameters will use fwrite() syntax, make sure to follow them. */
				//curl_easy_setopt(p_curl, CURLOPT_WRITEFUNCTION, [](void * p_data, size_t n_size, size_t n_menb, void * p_argv){});
				curl_easy_setopt(p_curl, CURLOPT_WRITEFUNCTION, [](){return 0; });

				/* Function that will be called to read the input (instead of fread). The
				* parameters will use fread() syntax, make sure to follow them. */
				//curl_easy_setopt(p_curl, CURLOPT_READFUNCTION, [](void * p_data, size_t n_size, size_t n_menb, void * p_argv){});
				curl_easy_setopt(p_curl, CURLOPT_READFUNCTION, []() {return 0; });

#if defined(_DEBUG) || defined(DEBUG)
				/* Since the traffic will be encrypted, it is very useful to turn on debug
				* information within libcurl to see what is happening during the
				* transfer */
				curl_easy_setopt(p_curl, CURLOPT_VERBOSE, (1L));
#else
				/* Same as TIMEOUT and CONNECTTIMEOUT, but with ms resolution */
				curl_easy_setopt(p_curl, CURLOPT_TIMEOUT_MS, (10000L));
				curl_easy_setopt(p_curl, CURLOPT_CONNECTTIMEOUT_MS, (10000L));
#endif				

				/* Perform the list */
				curl_result = curl_easy_perform(p_curl);
				
#if defined(_DEBUG) || defined(DEBUG)
				/* Check for errors */
				if (curl_result != CURLE_OK)
				{
					fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(curl_result));
				}
				else
				{
					printf("Success! Username:%s\n", elp.szUserName);
				}
#endif

				/* Always cleanup */
				curl_easy_cleanup(p_curl);

				/* Check for errors */
				if (curl_result != CURLE_OK)
				{
					elp.nVerifyStatus--;
					wsprintf(tzResult, _T("验证失败\x00"));
					lvi.pszText = tzResult;

					if (stPasswordIndex < pThis->m_strVector.size())
					{
						//更换下一个密码进行验证
						sprintf(elp.szPassWord, ("%s\x00"), pThis->m_strVector.at(stPasswordIndex++).c_str());
						Sleep(3000);
					}
					else
					{
						//没有密码字典,直接退出
						break;
					}
				}
				else
				{
					elp.nVerifyStatus++;
					USES_CONVERSION;
					wsprintf(tzResult, _T("验证通过.(密码为:%s)\x00"), A2W(elp.szPassWord));
					lvi.pszText = tzResult;
					break;
				}				
			}
			else
			{
#if defined(_DEBUG) || defined(DEBUG)
				/* Check for errors */
				printf("Curl init failed!\n");
#endif	
				break;
			}
		}

		//清空密码
		memset(elp.szPassWord, 0, sizeof(elp.szPassWord));

		//将结果更新到列表
		((CListViewCtrl)(pThis->GetDlgItem(IDC_LIST_LOGINUSER))).SetItem(&lvi);

		//将结果入队列
		pThis->m_elpQueueResult.push(elp);
	}
	
	return (int)curl_result;
}
LRESULT CMainDlg::OnAddLoginUser(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: Add validation code 
	//m_ELPQueue.push(CEmailLoginParam{ "", "pop3s://pop.yeah.net", "xingyun_ppshuai", "xingyun_1880", false });
	CLoginUserDlg elpdlg(this);
	elpdlg.DoModal();
	
	//CloseDialog(wID);
	return 0;
}
LRESULT CMainDlg::OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: Add validation code 
	//m_ELPQueue.push(CEmailLoginParam{ "", "pop3s://pop.yeah.net", "xingyun_ppshuai", "xingyun_1880", false });
	std::thread([](void * p) {
		size_t nSizeT = 0;
		CMainDlg * pThis = (CMainDlg*)p;
		
		while (pThis->m_elpQueue.size())
		{
			if (nSizeT != pThis->m_elpQueue.size())
			{
				nSizeT = pThis->m_elpQueue.size();
				std::thread(email_login, pThis).detach();
			}
			else
			{
				Sleep(300);
			}
		}
	}, this).detach();
	

	//CloseDialog(wID);
	return 0;
}
LRESULT CMainDlg::OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CloseDialog(wID);
	return 0;
}

void CMainDlg::CloseDialog(int nVal)
{
	m_strVector.clear();
	DestroyWindow();
	::PostQuitMessage(nVal);
}
