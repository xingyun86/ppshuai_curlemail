// LoginUserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "MainDlg.h"
#include "LoginUserDlg.h"

LRESULT CLoginUserDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	CenterWindow(GetParent());
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.yeah.net/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.yeah.net/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.163.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.163.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.126.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.126.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop3.aliyun.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.aliyun.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.exmail.qq.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.exmail.qq.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("hwpop.exmail.qq.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("hwimap.exmail.qq.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.qq.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.qq.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.263.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.263.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.x263.net/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.x263.net/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.x263.net.cn/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.x263.net.cn/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.21cn.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.21cn.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop3.sina.com.cn/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.sina.com.cn/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.sina.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.sina.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop3.vip.sina.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.vip.sina.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.tom.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.tom.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop3.elong.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.elong.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.china.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.china.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop3.sohu.com"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.sohu.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.etang.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.etang.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.mail.yahoo.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.mail.yahoo.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.mail.yahoo.com.cn/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.mail.yahoo.com.cn/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.139.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.139.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.189.cn/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.189.cn/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.vip.163.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.vip.163.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.gmail.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.gmail.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop3.live.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.live.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop3.mail.sogou.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.mail.sogou.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("pop.netease.com/"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), _T("imap.netease.com/INBOX/;UID="));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).SetCurSel(0);
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILTYPE)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILTYPE)).GetCount(), _T("pop3"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILTYPE)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILTYPE)).GetCount(), _T("pop3s"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILTYPE)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILTYPE)).GetCount(), _T("imap"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILTYPE)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILTYPE)).GetCount(), _T("imaps"));
	((CComboBox)GetDlgItem(IDC_COMBO_EMAILTYPE)).SetCurSel(0);
	GetDlgItem(IDC_EDIT_USERNAME).SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT_PASSWORD).SetWindowText(_T(""));
	GetDlgItem(IDOK).SetWindowText(_T("添加"));
	GetDlgItem(IDCANCEL).SetWindowText(_T("关闭"));
	SetWindowText(_T("新增登录账户信息"));

	return TRUE;
}

LRESULT CLoginUserDlg::OnOkCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CEmailLoginParam elp;
	bool bExistEmailType = false;
	bool bExistLoginUser = false;
	_TCHAR tzPrefixAddr[MAXCHAR] = { 0 };
	_TCHAR tzContentAddr[MAXCHAR] = { 0 };

	USES_CONVERSION;
	memset(&elp, 0, sizeof(elp));

	GetDlgItem(IDC_COMBO_EMAILADDR).GetWindowText(tzContentAddr, sizeof(tzContentAddr) / sizeof(*tzContentAddr));
	GetDlgItem(IDC_COMBO_EMAILTYPE).GetWindowText(tzPrefixAddr, sizeof(tzPrefixAddr) / sizeof(*tzPrefixAddr));
	
	sprintf(elp.szEmailUrl, ("%s://%s"), W2A(tzPrefixAddr), W2A(tzContentAddr));
	
	for (int n = 0; n < ((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(); n++)
	{
		_TCHAR tzTmp[MAXCHAR] = { 0 };
		((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetLBText(n, tzTmp);
		if (!strcmp(elp.szEmailUrl, W2A(tzTmp)))
		{
			bExistEmailType = true;
			break;
		}
	}
	
	if (!bExistEmailType)
	{
		((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).InsertString(((CComboBox)GetDlgItem(IDC_COMBO_EMAILADDR)).GetCount(), tzContentAddr);
	}

	GetDlgItemTextA(m_hWnd, IDC_EDIT_USERNAME, elp.szUserName, sizeof(elp.szUserName) / sizeof(*elp.szUserName));
	GetDlgItemTextA(m_hWnd, IDC_EDIT_PASSWORD, elp.szPassWord, sizeof(elp.szPassWord) / sizeof(*elp.szPassWord));
	if (!(*elp.szUserName) || !(*elp.szPassWord))
	{
		MessageBox(_T("账号和密码不能为空"), _T("提示信息"), MB_ICONINFORMATION);
		return 0;
	}
	elp.nParamIndex = ((CListViewCtrl)(m_pMainDlg->GetDlgItem(IDC_LIST_LOGINUSER))).GetItemCount();
	
	for (int n = 0; n < ((CListViewCtrl)(m_pMainDlg->GetDlgItem(IDC_LIST_LOGINUSER))).GetItemCount(); n++)
	{
		_TCHAR tzUserName[MAXCHAR] = { 0 };
		_TCHAR tzEmailUrl[MAXCHAR] = { 0 };
		((CListViewCtrl)(m_pMainDlg->GetDlgItem(IDC_LIST_LOGINUSER))).GetItemText(n, 0, tzUserName, sizeof(tzUserName) / sizeof(*tzUserName));
		((CListViewCtrl)(m_pMainDlg->GetDlgItem(IDC_LIST_LOGINUSER))).GetItemText(n, 1, tzEmailUrl, sizeof(tzEmailUrl) / sizeof(*tzEmailUrl));
		if (!strcmp(elp.szUserName, W2A(tzUserName)) && (!strcmp(elp.szEmailUrl, W2A(tzEmailUrl))))
		{
			bExistLoginUser = true;
			break;
		}
	}
	if (bExistLoginUser)
	{
		MessageBox(_T("账号已存在, 无需重复添加!"), _T("提示信息"), MB_ICONINFORMATION);
	}
	else
	{
		LVITEM lvi = { 0 };
		lvi.mask = LVIF_TEXT;

		lvi.iSubItem = 0;
		lvi.iItem = elp.nParamIndex;
		lvi.pszText = A2W(elp.szUserName);
		((CListViewCtrl)(m_pMainDlg->GetDlgItem(IDC_LIST_LOGINUSER))).InsertItem(&lvi);
		lvi.iSubItem++;
		lvi.pszText = A2W(elp.szEmailUrl);
		((CListViewCtrl)(m_pMainDlg->GetDlgItem(IDC_LIST_LOGINUSER))).SetItem(&lvi);
		lvi.iSubItem++;
		lvi.pszText = _T("未验证");
		((CListViewCtrl)(m_pMainDlg->GetDlgItem(IDC_LIST_LOGINUSER))).SetItem(&lvi);
		m_pMainDlg->m_elpQueue.push(elp);
	}
	
	//操作完成，清空输入
	GetDlgItem(IDC_EDIT_USERNAME).SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT_PASSWORD).SetWindowText(_T(""));

	//EndDialog(wID);
	return 0;
}

LRESULT CLoginUserDlg::OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	EndDialog(wID);
	return 0;
}

