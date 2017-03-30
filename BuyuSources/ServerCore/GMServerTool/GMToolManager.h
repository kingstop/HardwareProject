#pragma once

class GMToolManager
{
public:
	GMToolManager();
	virtual ~GMToolManager();

public:
	TCPClient _ControlTcp;
	int _GMToolNetWorkID;
};



