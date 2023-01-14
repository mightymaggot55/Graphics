#include "Vector3D.h"

Vector3D::Vector3D(float x, float y, float z) //Creates a Vector type. Sets the elements in Vector
{
	Init(x, y, z);
}

Vector3D::Vector3D(void) //initialises the elements of Vector to 0
{
	Init(0.0f, 0.0f, 0.0f);
}

Vector3D::Vector3D(const Vector3D & v) 
{
	_x = v.GetX();
	_y = v.GetY();
	_z = v.GetZ();
}

void Vector3D::Init(float x, float y, float z) //sets the x, y, z and w coordinates to private variables _x, _y, _z nd _w
{
	_x = x;
	_y = y;
	_z = z;
	_w = 1;
}


//These are the accessors for the coordinates. Use these to get the values and set the values
void Vector3D::SetX(const float x)
{
	_x = x;
}

float Vector3D::GetX() const
{
	return _x;
}

void Vector3D::SetY(const float y)
{
	_y = y;
}

float Vector3D::GetY() const
{
	return _y;
}

void Vector3D::SetZ(const float z)
{
	_z = z;
}

float Vector3D::GetZ() const
{
	return _z;
}

Vector3D Vector3D::CrossProduct(Vector3D &p, Vector3D &q) //Method used for the cross product. Parameters are the two Vectors you want to multiply. returns a vector
{	
	Vector3D newVector;

	newVector.SetX(p.GetY() * q.GetZ() - p.GetZ() * q.GetY());
	newVector.SetY(p.GetZ() * q.GetX() - p.GetX() * q.GetZ());
	newVector.SetZ(p.GetX() * q.GetY() - p.GetY() * q.GetX());	

	return newVector;
}

float Vector3D::DotProduct(Vector3D &p, Vector3D &q) //Method used for the dot product. Parameters are the two vectors you want to multiply. Returns a float value
{
		
	float dotProduct = (p.GetX() * q.GetX()) +(p.GetY() * q.GetY()) + (p.GetZ() * q.GetZ());

	return dotProduct;
	
}

//Vector3D Vector3D::Normalise(Vector3D &v)
//{	
//	float length;
//	float index[3];
//	v = { index[0], index[1], index[2] };
//	length = (sqrt(pow(index[0], 2) + pow(index[1], 2) + pow(index[2], 2)));
//	v = { index[0] / length, index[1] / length, index[2] / length };
//	return v;
//}




