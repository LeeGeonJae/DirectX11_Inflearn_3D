#include "pch.h"
#include "Main.h"
#include "Engine/Game.h"
#include "TriangleDemo_01.h"
#include "QuadDemo_02.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nShowCmd)
{
	GameDesc desc;
	desc.appName = L"GameCoding";
	desc.hInstance = hInstance;
	desc.vsync = false;
	desc.hWnd = NULL;
	desc.width = 800;
	desc.height = 600;
	desc.clearColor = Color(0.5, 0.5, 0.5, 0.5);
	desc.app = make_shared<QuadDemo>();

	GAME->Run(desc);

	return 0;
}