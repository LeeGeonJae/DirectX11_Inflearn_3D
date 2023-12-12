#pragma once
#include "ConstantBuffer.h"

struct GlobalDesc
{
	Matrix View = Matrix::Identity;
	Matrix Projection = Matrix::Identity;
	Matrix ViewProjection = Matrix::Identity;
};

struct TransformDesc
{
	Matrix World = Matrix::Identity;
};

class RenderManager
{
	DECLARE_SINGLE(RenderManager);

public:
	void Init(shared_ptr<Shader> shader);

	void 

private:
	shared_ptr<Shader> _shader;

	GlobalDesc _desc;
	shared_ptr<ConstantBuffer<GlobalDesc>>		_globalBuffer;
	ComPtr<ID3DX11EffectConstantBuffer>			_globalEffectBuffer;

	TransformDesc _transformDesc;
	shared_ptr<ConstantBuffer<TransformDesc>>	_transformBuffer;
	ComPtr<ID3DX11EffectConstantBuffer>			_transformEffectBuffer;
};
