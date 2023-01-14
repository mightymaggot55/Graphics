#include "Vertex.h"

Vertex::Vertex(float x, float y, float z) //Sets elements to parameters x, y, z
{
	Init(x, y, z);
}

Vertex::Vertex(void) //initialises each element to 0
{
	Init(0.0f, 0.0f, 0.0f);
}

Vertex::Vertex(const Vertex & v)
{
	Copy(v);
}

//Accessors for the x, y, z coordinates
void Vertex::SetX(const float x)
{
	_x = x;
}

float Vertex::GetX() const
{
	return _x;
}

void Vertex::SetY(const float y)
{
	_y = y;
}

float Vertex::GetY() const
{
	return _y;
}

void Vertex::SetZ(const float z)
{
	_z = z;
}

float Vertex::GetZ() const
{
	return _z;
}

void Vertex::SetW(float w)
{
	_w = w;
}

float Vertex::GetW(void) const
{
	return _w;
}

Vertex& Vertex::operator=(const Vertex &rhs)
{
	if (this != &rhs)
	{
		Copy(rhs);
	}
	return *this;
}

void Vertex::Copy(const Vertex& v) //Copy is _X is equal to the other vertex's X coordinate example
{
	_x = v.GetX();
	_y = v.GetY();
	_z = v.GetZ();
	_w = v.GetW();
}

void Vertex::Init(float x, float y, float z) //sets x, y, z parameters to variables _x, _y, _z, and sets _w to 1
{
	_x = x;
	_y = y;
	_z = z;
	_w = 1;
}

void Vertex::Dehomogenize() //Dehomogenize method
{
	_x = _x / _w;
	_y = _y / _w;
	_z = _z / _w;
	_w = _w / _w;
}

Vector3D Vertex::SubtractVertex(Vertex p, Vertex q)//Method written to subtract two Vertexs, return a vector
{
	Vector3D newVector;
	Vertex newVertex;

	newVector.SetX(p.GetX() - q.GetX());
	newVector.SetY(p.GetY() - q.GetY());
	newVector.SetZ(p.GetZ() - q.GetZ());
		
	return newVector;
}