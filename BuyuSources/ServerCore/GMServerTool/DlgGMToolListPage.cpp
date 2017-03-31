// DlgGMToolListPage.cpp : 实现文件
//

#include "stdafx.h"
#include "GMServerTool.h"
#include "DlgGMToolListPage.h"
#include "afxdialogex.h"


// DlgGMToolListPage 对话框

IMPLEMENT_DYNAMIC(DlgGMToolListPage, CDialogEx)

DlgGMToolListPage::DlgGMToolListPage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CMD_LIST, pParent)
{

}

DlgGMToolListPage::~DlgGMToolListPage()
{
}

void DlgGMToolListPage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CMD, _CMD_LIST);
	DDX_Control(pDX, IDC_LIST2, m_ListCtrlRoles);
}


BEGIN_MESSAGE_MAP(DlgGMToolListPage, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST_CMD, &DlgGMToolListPage::OnLbnSelchangeListCmd)
END_MESSAGE_MAP()


// DlgGMToolListPage 消息处理程序


void DlgGMToolListPage::OnLbnSelchangeListCmd()
{

	_CMD_LIST.GetCurSel();
	// TODO: 在此添加控件通知处理程序代码
}
