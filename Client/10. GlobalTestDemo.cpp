#include "pch.h"
#include "10. GlobalTestDemo.h"
#include "GeometryHelper.h"
#include "Camera.h"
#include "CameraScript.h"
#include "MeshRenderer.h"

void GlobalTestDemo::Init()
{
	auto shader = make_shared<Shader>(L"09. GlobalTest.fx");

	// Camera
	_camera = make_shared<GameObject>();
	_camera->GetOrAddTransform();
	_camera->AddComponent(make_shared<Camera>());
	_camera->AddComponent(make_shared<CameraScript>());
	_camera->GetTransform()->SetPosition(Vec3(0.f, 5.f, -20.f));

	// Object
	_object = make_shared<GameObject>();
	_object->GetOrAddTransform();
	_object->AddComponent(make_shared<MeshRenderer>());
	{
		_object->GetMeshRenderer()->SetShader(shader);
	}
	{
		RESOURCES->Init();
		auto mesh = RESOURCES->Get<Mesh>(L"Sphere");
		_object->GetMeshRenderer()->SetMesh(mesh);
	}
	{
		auto texture = RESOURCES->Load<Texture>(L"Veigar", L"../Resources/Textures/veigar.jpg");
		_object->GetMeshRenderer()->SetTexture(texture);
	}
}

void GlobalTestDemo::Update()
{
	_camera->Update();
	_object->Update();
}

void GlobalTestDemo::Render()
{

}
