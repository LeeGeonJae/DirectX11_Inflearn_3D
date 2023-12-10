#include "pch.h"
#include "Main.h"
#include "Engine/Game.h"
#include "TriangleDemo_01.h"
#include "QuadDemo_02.h"
#include "ConstantBuffer_03.h"
#include "CameraDemo_04.h"
#include "TextureDemo_05.h"

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
	desc.app = make_shared<TextureDemo>();

	GAME->Run(desc);

	return 0;
}