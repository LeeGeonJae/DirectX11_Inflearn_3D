#pragma once
#include "IExecute.h"
#include "Geometry.h"

class MeshDemo : public IExecute
{
public:
	void Init() override; 
	void Update() override;
	void Render() override;

private:
	shared_ptr<Shader>		_shader;

	// Object
	shared_ptr<GameObject>	_object;
	shared_ptr<GameObject>	_camera;
};