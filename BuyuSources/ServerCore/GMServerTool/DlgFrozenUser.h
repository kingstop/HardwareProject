#pragma once


// DlgFrozenUser 对话框

class DlgFrozenUser : public CDialogEx
{
	DECLARE_DYNAMIC(DlgFrozenUser)

public:
	DlgFrozenUser(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DlgFrozenUser();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_FROZEN_USER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

protected:
	DWORD _UserID;
	int FrozenTime;

	DECLARE_MESSAGE_MAP()
};
