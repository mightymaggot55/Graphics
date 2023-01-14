#pragma once
#include<math.h>


class Vector3D
{
public:	
	Vector3D(void);	
	Vector3D(float x, float y, float z);
	Vector3D(const Vector3D& v);

	//Accessors
	void SetX(const float x);
	float GetX() const;

	void SetY(const float y);
	float GetY() const;

	void SetZ(const float z);
	float GetZ() const;
		
	
	static Vector3D CrossProduct(Vector3D &p, Vector3D &q);
	static float DotProduct(Vector3D &p, Vector3D &q);
	static Vector3D Normalise(Vector3D &v);
	void Init(float x, float y, float z);
	

private:
	float _x;
	float _y;
	float _z;
	float _w;
	
	
};

