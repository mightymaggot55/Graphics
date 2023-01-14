#pragma once


class Polygon3D
{
public:
		
	Polygon3D();
	Polygon3D(int index0, int index1, int index2);
	~Polygon3D();
	Polygon3D(const Polygon3D& p);
	// Accessor to return index of specified vertex
	int GetIndex(int) const;
	Polygon3D& operator= (const Polygon3D &rhs);
	float average();	
	
	void SetCulling(bool cull);
	bool GetCulling();

private:
	int _indices[3];
	void Polygon3D::Copy(const Polygon3D & other);
	void Init(int index0, int index1, int index2);
	bool Culling;
	
	
	
	
	

};
