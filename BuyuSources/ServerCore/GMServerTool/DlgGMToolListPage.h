#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// DlgGMToolListPage 对话框

class DlgGMToolListPage : public CDialogEx
{
	DECLARE_DYNAMIC(DlgGMToolListPage)

public:
	DlgGMToolListPage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DlgGMToolListPage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CMD_LIST };
#endif

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	std::map<std::string, CDialogEx*> _CMD_Dlgs;
	DECLARE_MESSAGE_MAP()
public:
	CListBox _CMD_LIST;
	afx_msg void OnLbnSelchangeListCmd();
	CListCtrl m_ListCtrlRoles;
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	void RefrashRoleList();
};
