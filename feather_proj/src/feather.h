#pragma once
#include <GL/glut.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <iostream>

#define PI 3.141592653
enum FType {
	SINGLE,
	SINGLE_TEX,
	WINGS
};
class Feather {

public:
	void Init(const char* texPath);
	void Render(FType type);

protected:
	void RenderSingle(bool isTex = true);
	void RenderWings();

private:
	void InitLight();
	void GenSingleList();

	void DrawCubicHermiteCurveScape(float P[2][3], float R[2][3], int count);
	void DrawCubicHermiteCurveBarb(float P[2][3], float R[2][3], int count, int number);
	void DrawCubicHermiteCurveBarb2(float P[2][3], float R[2][3], int count, int number);

private:
	GLuint _listName;
	int _Xval[400];
	int _Xval2[400];
	int _idx;
	int _idx2;

	GLuint _textureID;
	GLuint _width;
	GLuint _height;

	GLuint _center;
	GLuint _center2;
};