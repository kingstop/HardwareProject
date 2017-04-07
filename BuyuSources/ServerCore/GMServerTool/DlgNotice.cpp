// DlgNotice.cpp : 实现文件
//

#include "stdafx.h"
#include "GMServerTool.h"
#include "DlgNotice.h"
#include "afxdialogex.h"


// DlgNotice 对话框

IMPLEMENT_DYNAMIC(DlgNotice, CDialogEx)

DlgNotice::DlgNotice(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_SEND_MSG, pParent)
{

}

DlgNotice::~DlgNotice()
{
}

void DlgNotice::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgNotice, CDialogEx)
	ON_BN_CLICKED(IDOK, &DlgNotice::OnBnClickedOk)
END_MESSAGE_MAP()


// DlgNotice 消息处理程序


void DlgNotice::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
