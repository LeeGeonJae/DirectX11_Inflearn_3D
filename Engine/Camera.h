#pragma once

enum class ProjectionType
{
	Perspective,		// 원근 투영
	Orthographic,		// 직교 투영
};

class Camera : public Component
{
	using Super = Component;
public:
	Camera();
	virtual ~Camera();

	virtual void Update() override;

	void SetProjectionType(ProjectionType type) { _type = type; }
	ProjectionType GetProjectionType() { return _type; }

	void UpdateMatrix();

	inline void SetNear(float value);
	inline void Setfar(float value);
	inline void SetFOV(float value);
	inline void SetWidth(float value);
	inline void SetHeight(float value);

	inline Matrix& GetViewMatrix();
	inline Matrix& GetProjectionMatrix();

private:
	ProjectionType _type = ProjectionType::Orthographic;

private:
	Matrix _matView = Matrix::Identity;
	Matrix _matProjection = Matrix::Identity;

	float _near = 1.f;
	float _far = 1000.f;
	float _fov = XM_PI / 4.f;
	float _width = 0.f;
	float _height = 0.f;

public:
	static Matrix S_MatView;
	static Matrix S_MatProjection;
};

void Camera::SetNear(float value)
{
	_near = value;
}
void Camera::Setfar(float value)
{
	_far = value;
}
void Camera::SetFOV(float value)
{
	_fov = value;
}
void Camera::SetWidth(float value)
{
	_width = value;
}
void Camera::SetHeight(float value)
{
	_height = value;
}

Matrix& Camera::GetViewMatrix()
{
	return _matView;
}
Matrix& Camera::GetProjectionMatrix()
{
	return _matProjection;
}