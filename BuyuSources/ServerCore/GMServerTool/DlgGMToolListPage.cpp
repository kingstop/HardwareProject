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
	DDX_Control(pDX, IDC_COMBO_FIND_TYPE, _CBFindType);
}


BEGIN_MESSAGE_MAP(DlgGMToolListPage, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST_CMD, &DlgGMToolListPage::OnLbnSelchangeListCmd)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &DlgGMToolListPage::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BTN_FIND, &DlgGMToolListPage::OnBnClickedBtnFind)
END_MESSAGE_MAP()


// DlgGMToolListPage 消息处理程序


void DlgGMToolListPage::OnLbnSelchangeListCmd()
{

	_CMD_LIST.GetCurSel();
	// TODO: 在此添加控件通知处理程序代码
}


void DlgGMToolListPage::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


BOOL DlgGMToolListPage::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_ListCtrlRoles.InsertColumn(0, TEXT("user_id"), LVCFMT_CENTER, 140, 50);
	m_ListCtrlRoles.InsertColumn(1, TEXT("nick_name"), LVCFMT_CENTER, 140, 50);
	m_ListCtrlRoles.InsertColumn(2, TEXT("level"), LVCFMT_CENTER, 140, 50);
	m_ListCtrlRoles.InsertColumn(3, TEXT("gender"), LVCFMT_CENTER, 140, 50);
	m_ListCtrlRoles.InsertColumn(4, TEXT("vip_level"), LVCFMT_CENTER, 140, 50);
	m_ListCtrlRoles.InsertColumn(5, TEXT("month_card"), LVCFMT_CENTER, 140, 50);
	m_ListCtrlRoles.InsertColumn(6, TEXT("is_online"), LVCFMT_CENTER, 140, 50);
	m_ListCtrlRoles.InsertColumn(7, TEXT("particular_state"), LVCFMT_CENTER, 140, 50);
	m_ListCtrlRoles.InsertColumn(8, TEXT("game_id"), LVCFMT_CENTER, 140, 50);
	RefrashRoleList();
	return TRUE;
}

void DlgGMToolListPage::RefrashRoleList()
{
	const std::map<DWORD, tagCenterRoleInfo>* roles = g_GMToolManager.GetRoleList();
	m_ListCtrlRoles.DeleteAllItems();
	std::map<DWORD, tagCenterRoleInfo>::const_iterator it = roles->begin();
	char sz[512];
	for (int i = 0; it != roles->end(); it++, i++)
	{

		const tagCenterRoleInfo& role = it->second;
		m_ListCtrlRoles.InsertItem(i, role.NickName);
		sprintf_s(sz, "%u", role.dwUserID);
		m_ListCtrlRoles.SetItemText(i, 0, (LPCTSTR)sz);
		m_ListCtrlRoles.SetItemText(i, 1, role.NickName);

		sprintf_s(sz, "%u", role.wLevel);
		m_ListCtrlRoles.SetItemText(i, 2, (LPCTSTR)sz);
		if (role.bGender)
		{
			sprintf_s(sz, "Male");
		}
		else
		{
			sprintf_s(sz, "Female");
		}
		m_ListCtrlRoles.SetItemText(i, 3, (LPCTSTR)sz);
		sprintf_s(sz, "%u", role.VipLevel);
		m_ListCtrlRoles.SetItemText(i, 4, (LPCTSTR)sz);
		if (role.IsInMonthCard)
		{
			sprintf_s(sz, "true");
		}
		else
		{
			sprintf_s(sz, "false");
		}
		m_ListCtrlRoles.SetItemText(i, 5, (LPCTSTR)sz);
		if (role.IsOnline)
		{
			sprintf_s(sz, "true");
		}
		else
		{
			sprintf_s(sz, "false");
		}
		m_ListCtrlRoles.SetItemText(i, 6, (LPCTSTR)sz);

		sprintf_s(sz, "%u", role.ParticularStates);
		m_ListCtrlRoles.SetItemText(i, 7, (LPCTSTR)sz);

		sprintf_s(sz, "%u", role.GameID);
		m_ListCtrlRoles.SetItemText(i, 8, (LPCTSTR)sz);
	}
}

void DlgGMToolListPage::OnBnClickedBtnFind()
{
	// TODO: 在此添加控件通知处理程序代码
}
