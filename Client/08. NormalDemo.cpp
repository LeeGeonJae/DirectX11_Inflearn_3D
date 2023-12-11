#include "pch.h"
#include "08. NormalDemo.h"
#include "GeometryHelper.h"
#include "Camera.h"
#include "CameraScript.h"

void NormalDemo::Init()
{
	_shader = make_shared<Shader>(L"07. Normal.fx");

	// Object
	_geometry = make_shared<Geometry<VertexTextureNormalData>>();
	GeometryHelper::CreateSphere(_geometry);

	// Texture
	_texture = RESOURCES->Load<Texture>(L"Veigar", L"../Resources/Textures/veigar.jpg");

	_vertexBuffer = make_shared<VertexBuffer>();
	_vertexBuffer->Create(_geometry->GetVertices());
	_indexBuffer = make_shared<IndexBuffer>();
	_indexBuffer->Create(_geometry->GetIndices());

	// Camera
	_camera = make_shared<GameObject>();
	_camera->GetOrAddTransform();
	_camera->AddComponent(make_shared<Camera>());
	_camera->AddComponent(make_shared<CameraScript>());

	_camera->GetTransform()->SetPosition(Vec3(0.f, 5.f, -20.f));
}

void NormalDemo::Update()
{
	_camera->Update();
}

void NormalDemo::Render()
{
	// ConstnatBuffer
	_shader->GetMatrix("World")->SetMatrix((float*)&_world);
	_shader->GetMatrix("View")->SetMatrix((float*)&Camera::S_MatView);
	_shader->GetMatrix("Projection")->SetMatrix((float*)&Camera::S_MatProjection);
	_shader->GetSRV("Texture0")->SetResource(_texture->GetComPtr().Get());
	_shader->GetVector("LightDir")->SetFloatVector((float*)&_lightDir);

	uint32 stride = _vertexBuffer->GetStride();
	uint32 offset = _vertexBuffer->GetOffset();

	Graphics::GetInstance()->GetDeviceContext()->IASetVertexBuffers(0, 1, _vertexBuffer->GetComPtr().GetAddressOf(), &stride, &offset);
	Graphics::GetInstance()->GetDeviceContext()->IASetIndexBuffer(_indexBuffer->GetComPtr().Get(), DXGI_FORMAT_R32_UINT, 0);

	//_shader->Draw(0, 0, _vertexBuffer->GetCount());
	_shader->DrawIndexed(0, 0, _indexBuffer->GetCount());
}
