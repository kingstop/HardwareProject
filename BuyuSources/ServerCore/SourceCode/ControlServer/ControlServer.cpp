
#include "stdafx.h"
#include "FishServer.h"
bool strlHandler(DWORD fdwctrltype)
{
	switch (fdwctrltype)
	{
	case CTRL_CLOSE_EVENT://直接关闭程序
		g_FishServer.SetServerClose();
		return true;
	}
	return true;
}

DWORD WINAPI MainUpdate(LPVOID pParam)
{
	g_FishServer.MainUpdate();
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	locale::global(locale(""));
	//setlocale(LC_CTYPE, "");    // MinGW gcc.
	wcout.imbue(locale(""));
	if (argc == 1)
	{
#ifdef _DEBUG
		printf("Debug模式下 按任意键继续...");
		// std::cout << "Debug模式下 按任意键继续...";
		getchar();
#endif
	}

	//std::wcout << "test asasa 试试 \n";
	//std::cout << psa;
	//std::cout << w2c(TEXT("test asasa 试试"), sizeof(TEXT("test asasa 试试")));
	if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)strlHandler, true))
	{
		ASSERT(false);
		return 0;
	}
	if (!g_FishServer.InitServer())
	{
		ASSERT(false);
		return 0;
	}
	DWORD nThreadID;
	CreateThread(0, 0, &MainUpdate, NULL, 0, &nThreadID);
	//等待输入 如果输入的为 "exit"  就执行退出操作 并且关闭线程
	std::string str;
	do
	{
		printf("控制台 命令输入 exit 为 退出命令 :\n");
		//std::cout << "控制台 命令输入 exit 为 退出命令 :\n";
		std::cin >> str;
		if (str.compare("exit") == 0)
		{
			g_FishServer.SetServerClose();//用于关闭线程
			return 0;
		}
		else if (str.compare("reloadconfig") == 0)
		{
			g_FishServer.SetReloadConfig();
		}
		else
		{
			printf("未知的控制台命令 无法进行处理\n");
			//std::cout << "未知的控制台命令 无法进行处理\n";
		}

	} while (true);
	return 0;
}

