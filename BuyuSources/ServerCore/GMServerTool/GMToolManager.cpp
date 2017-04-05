#include "stdafx.h"
#include "GMToolManager.h"
#define MAX_STRINGLENGTH 1024

GMToolManager::GMToolManager()
{
	m_ControlIsConnect = false;
	_login_successful = false;
}


GMToolManager::~GMToolManager()
{
}

void GMToolManager::StringToChar(const CString s, char *Destination)
{
	int k = 0;
	wchar_t *inf = NULL;
	inf = new wchar_t[MAX_STRINGLENGTH];
	wcscpy(inf, s);
	k = WideCharToMultiByte(CP_ACP, 0, inf, -1, NULL, 0, NULL, 0);
	k = WideCharToMultiByte(CP_ACP, 0, inf, k, Destination, k, NULL, 0);
	if (inf != NULL)
	{
		delete[]inf;
		inf = NULL;
	}
}

bool GMToolManager::Init()
{
	WHXml pXml;
	if (pXml.LoadXMLFilePath(TEXT("GMToolConfig.xml")))
	{
		
		WHXmlNode* pFishGMToolConfig = pXml.GetChildNodeByName(TEXT("FishGMToolConfig"));

		if (!pFishGMToolConfig)
		{
			ASSERT(false);
			return false;
		}
		if (!pFishGMToolConfig->GetAttribute(TEXT("GMToolNetWorkID"), _GMToolNetWorkID))
		{
			return false;
		}

		WHXmlNode* pControlServer = pFishGMToolConfig->GetChildNodeByName(TEXT("ControlServer"));

		if (!pControlServer)
		{
			ASSERT(false);
			return false;
		}
		 
		if (!pControlServer->GetAttribute(TEXT("ControlID"), m_ControlServerConfig.ControlID))
			return false;


		if (!pControlServer->GetAttribute(TEXT("DBNetworkID"), m_ControlServerConfig.DBNetworkID))
			return false;

		{
			TCHAR IP[IP_MAX_LENGTH] = { 0 };
			if (!pControlServer->GetAttribute(TEXT("ControlServerIP"), IP, IP_MAX_LENGTH))
				return false;
			UINT Count = 0;
			char* pChar = WCharToChar(IP, Count);
			strncpy_s(m_ControlServerConfig.ControlServerListenIP, Count + 1, pChar, Count);
			free(pChar);
		}
		if (!pControlServer->GetAttribute(TEXT("ControlServerNetworkID"), m_ControlServerConfig.ControlServerNetworkID))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerPort"), m_ControlServerConfig.ControlServerListenPort))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerTimeOut"), m_ControlServerConfig.ControlServerTimeOut))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerBuffSize"), m_ControlServerConfig.ControlServerBuffSize))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerRecvBuffSize"), m_ControlServerConfig.ControlServerRecvBuffSize))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerSendBuffSize"), m_ControlServerConfig.ControlServerSendBuffSize))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerRecvThreadSum"), m_ControlServerConfig.ControlServerRecvThreadSum))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerSendThreadSum"), m_ControlServerConfig.ControlServerSendThreadSum))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerSleepTime"), m_ControlServerConfig.ControlServerSleepTime))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerAcceptSleepTime"), m_ControlServerConfig.ControlServerAcceptSleepTime))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerListenCount"), m_ControlServerConfig.ControlServerListenCount))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerMaxSendCountPerFrame"), m_ControlServerConfig.ControlServerMaxSendCountPerFrame))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerMaxAcceptNumPerFrame"), m_ControlServerConfig.ControlServerMaxAcceptNumPerFrame))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerMaxRecvCmdCount"), m_ControlServerConfig.ControlServerMaxRecvCmdCount))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerMaxSendCmdCount"), m_ControlServerConfig.ControlServerMaxSendCmdCount))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlServerSceneHearbeatTick"), m_ControlServerConfig.ControlServerSceneHearbeatTick))
			return false;


		{
			TCHAR IP[IP_MAX_LENGTH] = { 0 };
			if (!pControlServer->GetAttribute(TEXT("ControlClientIP"), IP, IP_MAX_LENGTH))
				return false;
			UINT Count = 0;
			char* pChar = WCharToChar(IP, Count);
			strncpy_s(m_ControlServerConfig.ControlClientListenIP, Count + 1, pChar, Count);
			free(pChar);
		}
		if (!pControlServer->GetAttribute(TEXT("ControlClientNetworkID"), m_ControlServerConfig.ControlClientNetworkID))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientPassword"), m_ControlServerConfig.ControlClientPassword))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientPort"), m_ControlServerConfig.ControlClientListenPort))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientTimeOut"), m_ControlServerConfig.ControlClientTimeOut))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientBuffSize"), m_ControlServerConfig.ControlClientBuffSize))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientRecvBuffSize"), m_ControlServerConfig.ControlClientRecvBuffSize))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientSendBuffSize"), m_ControlServerConfig.ControlClientSendBuffSize))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientRecvThreadSum"), m_ControlServerConfig.ControlClientRecvThreadSum))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientSendThreadSum"), m_ControlServerConfig.ControlClientSendThreadSum))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientSleepTime"), m_ControlServerConfig.ControlClientSleepTime))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientAcceptSleepTime"), m_ControlServerConfig.ControlClientAcceptSleepTime))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientListenCount"), m_ControlServerConfig.ControlClientListenCount))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientMaxSendCountPerFrame"), m_ControlServerConfig.ControlClientMaxSendCountPerFrame))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientMaxAcceptNumPerFrame"), m_ControlServerConfig.ControlClientMaxAcceptNumPerFrame))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientMaxRecvCmdCount"), m_ControlServerConfig.ControlClientMaxRecvCmdCount))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientMaxSendCmdCount"), m_ControlServerConfig.ControlClientMaxSendCmdCount))
			return false;
		if (!pControlServer->GetAttribute(TEXT("ControlClientSceneHearbeatTick"), m_ControlServerConfig.ControlClientSceneHearbeatTick))
			return false;
		if (!pControlServer->GetAttribute(TEXT("LogDBID"), m_ControlServerConfig.LogDBID))
			return false;		
	}
	else
	{
		return false;
	}
	ConnectControl();


	return true;
}


void GMToolManager::ConnectControl()
{
	ClientInitData pControlData;
	pControlData.BuffSize = m_ControlServerConfig.ControlServerBuffSize;
	pControlData.Port = m_ControlServerConfig.ControlServerListenPort;
	pControlData.SleepTime = m_ControlServerConfig.ControlServerSleepTime;
	pControlData.SocketRecvSize = m_ControlServerConfig.ControlServerRecvBuffSize;
	pControlData.SocketSendSize = m_ControlServerConfig.ControlServerSendBuffSize;
	pControlData.ThreadNum = 1;
	pControlData.Timeout = m_ControlServerConfig.ControlServerTimeOut;
	pControlData.CmdHearbeat = 0;
	pControlData.SendArraySize = m_ControlServerConfig.ControlServerMaxSendCmdCount;
	pControlData.RecvArraySize = m_ControlServerConfig.ControlServerMaxRecvCmdCount;

	if (!_ControlTcp.Init(m_ControlServerConfig.ControlServerListenIP, pControlData, (void*)&_GMToolNetWorkID, sizeof(BYTE)))
	{

		return;
	}
	OnTcpClientConnect(&_ControlTcp);
}

void GMToolManager::SendNetCmdToControl(NetCmd*pCmd)
{
	if (!pCmd)
	{
		ASSERT(false);
		return;
	}
	if (!_ControlTcp.Send(pCmd, false))
	{
		ASSERT(false);
	}
}


void GMToolManager::Update()
{
	if (_ControlTcp.IsConnected())
	{
		if (!m_ControlIsConnect)
			OnTcpClientConnect(&_ControlTcp);
		NetCmd* pCmd = _ControlTcp.GetCmd();
		int Sum = 0;
		while (pCmd && Sum < Msg_OnceSum)
		{
			HandleControlMsg(pCmd);
			free(pCmd);
			++Sum;
			pCmd = _ControlTcp.GetCmd();
		}
		if (pCmd)
		{
			HandleControlMsg(pCmd);
			free(pCmd);
		}
	}
	else
	{
		if (m_ControlIsConnect)
			OnTcpClientLeave(&_ControlTcp);

		//重新连接DB
		ConnectControl();
	}
}


bool GMToolManager::HandleControlMsg(NetCmd* pCmd)
{
	
	if (pCmd->CmdType == Main_Control)
	{
		if (pCmd->SubCmdType == CL_GM_CHECK_PASSWORD_ACK)
		{
			CL_GM_Cmd_CheckPassWordACK* msg = (CL_GM_Cmd_CheckPassWordACK*)pCmd;
			if (msg->ret == true)
			{
				_login_successful = true;
			}
		}

		if (_login_successful)
		{
			switch (pCmd->SubCmdType)
			{
			case CE_GM_QUERY_ALL_USER_ACK:
			{
				CE_GM_QueryAllUserACK* msg = (CE_GM_QueryAllUserACK*)pCmd;
				for (int i = 0; i < msg->count; i ++)
				{
					_RoleList[msg->CenterRole[i].dwUserID] = msg->CenterRole[i];
				}
				
				if (msg->end)
				{
					g_dlg->GetGMTool()->RefrashRoleList();

				}
			}
			break;
			default:
				break;
			}
		}

	}
	return true;
}


void GMToolManager::OnTcpClientLeave(TCPClient* pClient)
{
	if (!pClient)
	{
		ASSERT(false);
		return;
	}
	if (pClient == &_ControlTcp)
	{
		m_ControlIsConnect = false;
		_ControlTcp.Shutdown();
	}
}

void GMToolManager::SendLoginReq(const char* Account, const char* PassWord)
{
	GM_CL_Cmd_CheckPassWordReq msg;
	SetMsgInfo(msg, GetMsgType(Main_Control, GM_CL_CHECK_PASSWORD_REQ), sizeof(GM_CL_Cmd_CheckPassWordReq));
	sprintf_s(msg.Account, "%s", Account);
	sprintf_s(msg.PassWord, "%s", PassWord);
	_ControlTcp.Send(&msg, false);	
}

void GMToolManager::OnTcpClientConnect(TCPClient* pClient)
{
	if (!pClient)
	{
		ASSERT(false);
		return;
	}
	if (pClient == &_ControlTcp)
	{
		m_ControlIsConnect = true;
	}
	else
	{
		ASSERT(false);
	}
	return;
}

const std::map<DWORD, tagCenterRoleInfo>* GMToolManager::GetRoleList()
{
	return &_RoleList;
}