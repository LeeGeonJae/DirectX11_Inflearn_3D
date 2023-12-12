#pragma once
#include "IExecute.h"
#include "Geometry.h"

class GlobalTestDemo : public IExecute
{
public:
	void Init() override; 
	void Update() override;
	void Render() override;

private:
	// Object
	shared_ptr<GameObject>	_object;
	shared_ptr<GameObject>	_camera;
};