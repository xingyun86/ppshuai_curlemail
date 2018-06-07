// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
class CEmailLoginParam {
public:
	char szEmailUrl[MAXCHAR];
	char szUserName[MAXCHAR];
	char szPassWord[MAXCHAR];
	long nVerifyStatus;//(-1)-验证失败,(0)-未验证,(1)-验证成功
	long nParamIndex;//所在行索引
};
class CMainDlg : public CAxDialogImpl<CMainDlg>, public CUpdateUI<CMainDlg>,
		public CMessageFilter, public CIdleHandler
{
public:
	enum { IDD = IDD_MAINDLG };

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnIdle();

	BEGIN_UPDATE_UI_MAP(CMainDlg)
	END_UPDATE_UI_MAP()

	BEGIN_MSG_MAP(CMainDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		COMMAND_ID_HANDLER(IDC_BUTTON_ADDLOGINUSR, OnAddLoginUser)
		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnAddLoginUser(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	void CloseDialog(int nVal);

private:
	HGLOBAL OpenResource(LPVOID & lpData, DWORD & dwSize, LPCTSTR lpName, LPCTSTR lpType, HMODULE hModule = ::GetModuleHandle(NULL));
	BOOL ParseResrc(LPCTSTR ptszFileName, UINT uResourceID, LPCTSTR ptszTypeName, HMODULE hModule = ::GetModuleHandle(NULL));

	void ReadPasswordDic()
	{
		int nIndex = 0;
		char szLineData[MAXBYTE] = { 0 };
		FILE * pFile = fopen(PASSWORDDIC_FILENAME, "rb");
		if (pFile)
		{
			while (fgets(szLineData, sizeof(szLineData) / sizeof(*szLineData), pFile))
			{
				nIndex = strlen(szLineData) - 1;
				while (*(szLineData + nIndex) == '\r' || *(szLineData + nIndex) == '\n')
				{
					*(szLineData + (nIndex--)) = '\0';
				}
				if (*szLineData)
				{
					m_strVector.push_back(szLineData);
				}
				memset(szLineData, 0, sizeof(szLineData));
			}
			fclose(pFile);
		}
	}
public:
	static int email_login(void * p);

public:
	std::mutex m_mutex;
	std::vector<std::string> m_strVector;
	std::queue<CEmailLoginParam> m_elpQueue;
	std::queue<CEmailLoginParam> m_elpQueueResult;
};
