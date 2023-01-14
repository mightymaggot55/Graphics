#include "Camera.h"



Camera::Camera()
{
	//add code
}


Camera::~Camera()
{
}

Camera::Camera(float xRotation, float yRotation, float zRotation, Vertex _position) //xRotation, yRotation, zRotation specify the initial rotation of the camera. Position specifies the position of the camera
{
	//Add methods that create and store the viewing matrix and provide the accessors to retrieve them	
}

Matrix Camera::ViewingTransformation()
{
	return (Matrix().CameraXRotation(_xRotation) * Matrix().CameraYRotation(_yRotation) * Matrix().CameraZRotation(_zRotation) * Matrix().CameraTranslation(_position.GetX(), _position.GetY(), _position.GetZ()));
}


float Camera::GetRotationX(void) const
{
	return 0.0f;
}
void Camera::SetRotationX(const float xRotation)
{
	_xRotation = xRotation;
}

float Camera::GetRotationY(void) const
{
	return 0.0f;
}
void Camera::SetRotationY(const float yRotation)
{
	_yRotation = yRotation;
}

float Camera::GetRotationZ(void) const
{
	return 0.0f;
}
void Camera::SetRotationZ(const float zRotation)
{
	_zRotation = zRotation;
}






Vertex Camera::GetPosition(void) const
{
	return _position;
}

void Camera::SetPosition(float positionX, float positionY, float positionZ)
{
	_position = Vertex{ positionX, positionY, positionZ};
}

//float Camera::GetPositionX(void) const
//{
//		return _positionX;
//}
//void Camera::SetPositionX(float positionX)
//{
//	_positionX = positionX;
//}
//
//float Camera::GetPositionY(void) const
//{
//	return _positionY;
//}
//
//void Camera::SetPositionY(float positionY)
//{
//	_positionY = positionY;
//}
//
//float Camera::GetPositionZ(void) const
//{
//	return _positionZ;
//}
//void Camera::SetPositionZ(float positionZ)
//{
//	_positionZ = positionZ;
//}
