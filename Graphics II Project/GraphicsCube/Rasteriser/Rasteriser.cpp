#include "Rasteriser.h"


Rasteriser app;

bool Rasteriser::Initialise() //used to load the md2 model into the program - several files provided with the program, so change name to change the file.
							  //Beware the camera view though, this may need changing depending on the size of the model
{	
	if (!MD2Loader::LoadModel("cube.md2", _model,
		&Model::AddPolygon,
		&Model::AddVertex))
	{
		return false;
	}

	_x = 0.0f; //initialises x, y, z coordinates to 0
	_y = 0.0f;
	_z = 0.0f;


	return true;
}

void Rasteriser::Update(Bitmap &bitmap) //update is used to apply updates to the coordinates, enabling it to rotate, scale and translate
{

	float radiansY = (float)(_y * 3.14 / 180); //_y is used because of the rotation around the Y axis
	float radiansX = (float)(_x * 3.14 / 180); //_y is used because of the rotation around the Y axis
	float radiansZ = (float)(_z * 3.14 / 180); //_y is used because of the rotation around the Y axis
	
	_x += 1.0f; //Change this values to change rotation, translate and scaling
	_y += 1.0f;
	_z += 1.0f;
	//if we want to rotate on a different axis, we need to change the Y's to whatever axis we want to rotate on
	Matrix rotatingY  = rotatingY.YRotationMatrix(radiansY); //saves the Y rotation  Matrix to a local matrix
	YRotationtransform = rotatingY; //Sets it to a transform Vertex in the header, making it accessible from other points of the program
	
	Matrix rotatingX = rotatingX.XRotationMatrix(radiansX);
	XRotationtransform = rotatingX;

	Matrix rotatingZ = rotatingZ.CameraZRotation(radiansZ);
	ZRotationtransform = rotatingZ;

	Matrix translate = translate.TranslationMatrix(_x, _y, _z);

	Matrix scale = scale.ScalingMatrix(_x, _y, _z);

	Translation = translate;
	Scaling = scale;

	GeneratePerspectiveMatrix(1, (float)bitmap.GetWidth() / (float)bitmap.GetHeight()); //Sets perspective matrix to be used
	GenerateViewMatrix(1, (float)bitmap.GetWidth(), (float)bitmap.GetHeight()); //sets the view matrix to be used
}

void Rasteriser::Render(Bitmap &bitmap)
{	
	bitmap.Clear(RGB(0, 0, 0)); //Clears the bitmap to black
	_model.ApplyTransformToLocalVertices(YRotationtransform); //Apply the Y Rotation transform to the local vertices. Change this to Scaling or Translation to scale and transform
	_model.CalculateBackfaces(); //Method for calculating whether a polygon is backfacing
	_model.ApplyTransformToTransformedVertices(_camera.ViewingTransformation()); //applies the camera viewing transformation to the transformed vertices
	_model.ApplyTransformToTransformedVertices(_perspective); //Applies the perspective matrix to the transformed vertices
	_model.Dehomogenize(); //Dehomogenizes the transformed vertices
	_model.ApplyTransformToTransformedVertices(_view);	 //applies the view matrix to the transformed vertices
	DrawString(bitmap, L"This is displaying my cube rotating on the Y axis");
	DrawWireFrame(bitmap); //Draws the transformed Vertices onto the bitmap by calling the draw wire frame method	
}


void Rasteriser::DrawWireFrame(Bitmap& bitmap)
{
	HDC hdc = bitmap.GetDC();
	HPEN pen; //declare the pen
	pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 255)); //initialises and creates the pen to a purple colour
	HGDIOBJ oldPen = SelectObject(hdc, pen); //selectes the new pen as the pen to use

	vector<Vertex> vertices = _model.GetTransformedVertices();
	Vertex newIndex[3];
	vector<Polygon3D>& polygons = _model.GetPolygons(); //Gets the polygons
	
	
		for (int i = 0; i < _model.GetPolygonCount(); i++) //goes through the loop for the amount of polygons there are
		{
			for (int j = 0; j < 3; j++)
			{
				newIndex[j] = vertices[polygons[i].GetIndex(j)]; //gets the vertices from the polygon indexes
			}
			
			//if (polygons[i].GetCulling() == false) //if backface Culling is equal to false, draw the square. If its true (polygon at the back) it won't draw them
			//{
				MoveToEx(hdc, (int)newIndex[0].GetX(), (int)newIndex[0].GetY(), NULL);
				LineTo(hdc, (int)newIndex[1].GetX(), (int)newIndex[1].GetY());
				LineTo(hdc, (int)newIndex[2].GetX(), (int)newIndex[2].GetY());
				LineTo(hdc, (int)newIndex[0].GetX(), (int)newIndex[0].GetY());
			//}
		}
}


void Rasteriser::GeneratePerspectiveMatrix(float d, float aspectRatio) //Perspective Matrix
{	//Add code - Generates the perspective Matrix	

	_perspective = Matrix   { d / aspectRatio, 0, 0, 0,
										0, 1, 0, 0,
										0, 0, d, 0,
										0, 0, d, 0 };
}

void Rasteriser::GenerateViewMatrix(float d, float width, float height) //Perspective Matrix
{
	//Add code - Generates the screen (view) matrices
	_view = Matrix  { width / 2, 0, 0, width / 2,
				0, -height / 2, 0, height / 2,
				0, 0, d / 2, d / 2,
				0, 0, 0, 1 };
}

void Rasteriser::DrawString(Bitmap &bitmap, LPCTSTR text) //Used to draw a string onto the bitmap
{
	HDC hdc = bitmap.GetDC();
	HFONT hFont, hOldFont;

	// Retrieve a handle to the variable stock font.  
	hFont = hFont = CreateFont(48, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Myfont"));

	// Select the variable stock font into the specified device context. 
	if (hOldFont = (HFONT)SelectObject(hdc, hFont))
	{
		SetTextColor(hdc, RGB(255, 255, 255));
		SetBkColor(hdc, RGB(0, 0, 0));

		// Display the text string.  
		TextOut(hdc, 10, 10, text, lstrlen(text));

		// Restore the original font.        
		SelectObject(hdc, hOldFont);
	}
	DeleteObject(hFont);
}

