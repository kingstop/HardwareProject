// DlgFrozenUser.cpp : 实现文件
//

#include "stdafx.h"
#include "GMServerTool.h"
#include "DlgFrozenUser.h"
#include "afxdialogex.h"


// DlgFrozenUser 对话框

IMPLEMENT_DYNAMIC(DlgFrozenUser, CDialogEx)

DlgFrozenUser::DlgFrozenUser(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_FROZEN_USER, pParent)
{

}

DlgFrozenUser::~DlgFrozenUser()
{
}

void DlgFrozenUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BOOL DlgFrozenUser::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetDlgItemInt(IDC_EDIT_FROZEN_TIME, 0);
	return TRUE;
}

BEGIN_MESSAGE_MAP(DlgFrozenUser, CDialogEx)
END_MESSAGE_MAP()


// DlgFrozenUser 消息处理程序
