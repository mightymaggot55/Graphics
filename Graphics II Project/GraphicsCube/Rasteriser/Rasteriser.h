#pragma once
#include <vector>
#include "Framework.h"
#include "Matrix.h"
#include "Vertex.h"
#include "Model.h"
#include "MD2Loader.h"
#include "Camera.h"
#include "Polygon3D.h"
#include <iostream>    

class Rasteriser : public Framework
{
public:
	Polygon3D _Polygon;
	
	bool Initialise();
	void Update(Bitmap &bitmap);
	void Render(Bitmap & bitmap);
	
	void GeneratePerspectiveMatrix(float d, float aspectRatio);
	void GenerateViewMatrix(float d, float width, float height);
	void DrawString(Bitmap & bitmap, LPCTSTR text);
	
	void DrawWireFrame(Bitmap & bitmap);
	
private:
	float _x;
	float _y;
	float _z;
	
	Matrix transform;
	Matrix YRotationtransform;
	Matrix XRotationtransform;
	Matrix ZRotationtransform;
	
	Matrix Translation;
	Matrix Scaling;

	Matrix YRotation;
	Matrix _perspective;
	Matrix _view;
	Model _model;
	Camera _camera;
	Vertex _vertex;
	Polygon3D _polygons;
};

