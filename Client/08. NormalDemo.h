#pragma once
#include "IExecute.h"
#include "Geometry.h"

class NormalDemo : public IExecute
{
public:
	void Init() override; 
	void Update() override;
	void Render() override;

private:
	shared_ptr<Shader>			_shader;
	shared_ptr<Geometry<VertexTextureNormalData>>	_geometry;
	shared_ptr<VertexBuffer>	_vertexBuffer;
	shared_ptr<IndexBuffer>		_indexBuffer;

	Matrix _world = Matrix::Identity;

	// Camera
	shared_ptr<GameObject> _camera;
	shared_ptr<Texture> _texture;

	Vec3 _lightDir = Vec3(0.5f, -1.f, 0.5f);
};