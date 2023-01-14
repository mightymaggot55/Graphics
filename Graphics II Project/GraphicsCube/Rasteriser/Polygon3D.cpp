#include "Polygon3D.h"
#include "Model.h"


Polygon3D::Polygon3D(int index0, int index1, int index2) //initialises polygon3D with 3 indexes
{
	Init(index0, index1, index2);
}

Polygon3D::Polygon3D(void) //initialises values in Polygon3D to 0
{
	Init(0, 0, 0);
}

Polygon3D::~Polygon3D()
{
}

Polygon3D::Polygon3D(const Polygon3D & p)
{
	Copy(p);
}

int Polygon3D::GetIndex(int index) const //a way to get the indices of the polygon as they are a private variable
{
	return _indices[index];
}

Polygon3D & Polygon3D::operator=(const Polygon3D & rhs)
{
	// TODO: insert return statement here
	if (this != &rhs)
	{
		Copy(rhs);
	}
	return *this;
}

void Polygon3D::SetCulling(bool cull)
{
	Culling = cull;	
}

bool Polygon3D::GetCulling(void)
{
	return Culling;
}

void Polygon3D::Copy(const Polygon3D & other) //copy is set so indices is equal to the other polygons indices
{
	for (int i = 0; i < 3; i++)
	{
		_indices[i] = other.GetIndex(i);
	}
}

void Polygon3D::Init(int index0, int index1, int index2) //initialises the 3 indices to the 3 indexes of the polygon
{	
	_indices[0] = index0;
	_indices[1] = index1;
	_indices[2] = index2;	
}


//float Polygon3D::average(Vertex p, VE)
//{	
//	return 0.0f;
//}





