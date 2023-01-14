#pragma once
#include "Vertex.h"
#include "Polygon3D.h"
#include "Matrix.h"
#include <vector>
#include "Vector3D.h"
#include "Camera.h"
#include <algorithm>
using std::vector;

class Model
{
public:
	Model();
	~Model();
	// Accessors
	
	Vertex _vertex;
	Vector3D _vector3D;
	Camera _camera;
	Polygon3D _polygon;
	
	vector<Polygon3D>& GetPolygons(); //access to polygons - gets polygons
	vector<Vertex>& GetVertices(); // access to vertices - gets vertices
	vector<Vertex>& GetTransformedVertices();

	size_t GetPolygonCount() const; 
	size_t GetVertexCount() const;
	
	void AddVertex(float x, float y, float z);
	void AddPolygon(int i0, int i1, int i2);

	void ApplyTransformToLocalVertices(const Matrix & transform);
	void ApplyTransformToTransformedVertices(const Matrix & transform);

	void Dehomogenize();

	void CalculateBackfaces();
	
	vector<Vertex> transformedVertices; //collection/list of transformed vertices

	void Sort(void);
private:
	vector<Polygon3D> _polygons; //list of polygons
	vector<Vertex> _vertices; //list of vertices
	float _x;
	float _y;
	float _z;
	float _w;
};