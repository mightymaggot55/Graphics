#pragma once
#include "Vector3D.h"

class Vertex
{
public:
	
	Vertex(void);
	Vertex(float x, float y, float z);
	Vertex(const Vertex& v);
	
	// Accessors
	float GetX() const;
	void SetX(float x);
	
	float GetY(void) const;
	void SetY(float y);
	
	float GetZ(void) const;
	void SetZ(float z);
	
	float GetW(void) const;
	void SetW(float w);

	void Dehomogenize();
	// Assignment operator
	Vertex& operator= (const Vertex& rhs);
	Vector3D Vertex::SubtractVertex(Vertex p, Vertex q);
	
private:
	float _x;
	float _y;
	float _z;
	float _w;
	
	void Init(float x, float y, float z);	
	void Copy(const Vertex& v);
};

