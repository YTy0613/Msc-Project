#pragma once
#include <iostream>
#if _WIN32
#   include <Windows.h>
#endif
//#include <GL/glew.h>
#if __APPLE__
#   include <OpenGL/gl.h>
#   include <OpenGL/glu.h>
#   include <GLUT/glut.h>
#else
#   include <GL/gl.h>
#   include <GL/glu.h>
#   include <GL/glut.h>
#endif
class Util {
public:
	static GLuint LoadTexture(const char* filename, int& w, int& h, int& k, int& k1, int* Xvalue, int* Xvalue2);

	static void Invert(GLfloat in[16], GLfloat out[16]);
	static void Multiply(GLfloat vecIn[3], GLfloat m[16], GLfloat vecOut[3]);

};