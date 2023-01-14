#include "Model.h"

Model::Model()
{
	//Add code here
}

Model::~Model()
{

}

vector<Polygon3D>& Model::GetPolygons() //access to private variable polygons - call this method for access
{
	return _polygons;
}

vector<Vertex>& Model::GetVertices()//access to private variable Vertices - call this method for access
{
	return _vertices;
}

vector<Vertex>& Model::GetTransformedVertices() //access to private variable transformedVertices - call this method for access
{
	return transformedVertices;
}


size_t Model::GetPolygonCount() const //returns the size of the polygons collection
{
	return _polygons.size();
}

size_t Model::GetVertexCount() const //returns the size of the vertices collection 
{
	return _vertices.size();
}

void Model::AddVertex(float x, float y, float z) //adds a vertex to the vertices collection
{
	_vertices.push_back(Vertex(x, y, z)); 
}

void Model::AddPolygon(int i0, int i1, int i2) //adds a polygon to the polygon collection
{
	_polygons.push_back(Polygon3D(i0, i1, i2));
}

//applies transformation Matrix to each vertex in the original collection and stores the result in the transformed vertices
void Model:: ApplyTransformToLocalVertices(const Matrix &transform) //NOTE: ORIGINAL VERTICES COLLECTION IS NEVER MODIFIED
{
		
	transformedVertices.clear();
	for (int i = 0; i < _vertices.size() ; i++)
	{
		Vertex temp = transform * _vertices[i];
		transformedVertices.push_back(temp);
	}	
}

void Model::ApplyTransformToTransformedVertices(const Matrix &transform) //applies the transformation matrix to each vertex in the transformed vertices collection
{
	
	for (int i = 0; i < transformedVertices.size(); i++) 
	{
		transformedVertices[i] = transform * transformedVertices[i];
	}
}

void Model::Dehomogenize() //Dehomogenizes the transformed Vertices (divides all coordinates by the W component)
{
	for (int i = 0; i < transformedVertices.size(); i++)
	{
		transformedVertices[i].Dehomogenize();
	}
}

void Model::CalculateBackfaces() //Used for calculating back face culling, and determining which faces are back facing
{
	Vertex newIndex[3];
	vector<Polygon3D>& polygons = GetPolygons(); //used to return the polygons 
	Vector3D a, b, eyeVector, normalVector;
	float backfacing;
	for (int i = 0; i < GetPolygonCount(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			newIndex[j] = _vertices[polygons[i].GetIndex(j)]; 
		}

		a = _vertex.SubtractVertex(newIndex[1], newIndex[0]); //subtract Vertex subtracts the first element by the second element
		b = _vertex.SubtractVertex(newIndex[2], newIndex[0]);
		normalVector = _vector3D.CrossProduct(b, a); //The normal Vector is gained by getting the cross product of vectors a and b
		eyeVector = _vertex.SubtractVertex(newIndex[0], _camera.GetPosition()); 
		backfacing = _vector3D.DotProduct(normalVector, eyeVector); //the final backfacing - if this value is less than zero, then the face is to be culled

		if (backfacing < 0) //if statement to determine if polygon is backfacing
		{
			_polygons[i].SetCulling(true);
		}
	}	
}

void Model::Sort(void)
{
	int newIndex[3];
	vector<Polygon3D> polygons = GetPolygons();

	for (int i = 0; i < GetPolygonCount(); i++)
	{
		for (int j = 0; j < _polygon.GetIndex(j); j++)
		{
			newIndex[j] = _polygon.GetIndex(j);
			
		}
	}
}

