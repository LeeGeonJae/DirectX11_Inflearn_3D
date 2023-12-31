#include "pch.h"
#include "Main.h"
#include "Engine/Game.h"
#include "01. TriangleDemo.h"
#include "02. QuadDemo.h"
#include "03. ConstantBuffer.h"
#include "04. CameraDemo.h"
#include "05. TextureDemo.h"
#include "06. SamplerDemo.h"
#include "07. HeightMap.h"
#include "08. NormalDemo.h"
#include "09. MeshDemo.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nShowCmd)
{
	GameDesc desc;
	desc.appName = L"GameCoding";
	desc.hInstance = hInstance;
	desc.vsync = false;
	desc.hWnd = NULL;
	desc.width = 800;
	desc.height = 600;
	desc.clearColor = Color(0.5f, 0.5f, 0.5f, 0.5);
	desc.app = make_shared<HeightMapDemo>();

	GAME->Run(desc);

	return 0;
}