// LoginUserDlg.h : interface of the CLoginUserDlg class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once


// CLoginUserDlg dialog
class CMainDlg;
class CLoginUserDlg : public CDialogImpl<CLoginUserDlg>
{
public:
	CLoginUserDlg(CMainDlg * pMainDlg = NULL) { m_pMainDlg = pMainDlg; }
public:
	enum { IDD = IDD_DIALOG_LOGINUSER };

	BEGIN_MSG_MAP(CLoginUserDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(IDOK, OnOkCmd)
		COMMAND_ID_HANDLER(IDCANCEL, OnCloseCmd)
	END_MSG_MAP()

	// Handler prototypes (uncomment arguments if needed):
	//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnOkCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
private:
	CMainDlg * m_pMainDlg;
};
