#pragma once
#include "Vertex.h"
#include "Matrix.h"
#include <cmath>

class Camera
{
public:
	Camera();
	~Camera();
	Camera(float xRotation, float yRotation, float zRotation, Vertex _position);
	Matrix ViewingTransformation();

	float GetRotationX(void) const;
	void SetRotationX(const float x);
	float GetRotationY(void) const;
	void SetRotationY(const float y);
	float GetRotationZ(void) const;
	void SetRotationZ(const float z);
	
	/*float GetPositionX(void) const;
	void SetPositionX(float positionX);
	float GetPositionY(void) const;
	void SetPositionY(float positionY);
	float GetPositionZ(void)const;
	void SetPositionZ(float positionZ);*/
	Vertex GetPosition(void)const;
	void SetPosition(float positionX, float positionY, float positionZ);

private:
	float _xRotation = 0;
	float _yRotation = 0;
	float _zRotation = 0;

	Vertex _position{ 0, 0, -50 };
	Vertex _rotation;
	

};

