#include "feather.h"
#include "util.h"
using namespace std;

void Feather::Init(const char* texPath)
{
	InitLight();
	int width, height;
	_textureID = Util::LoadTexture(texPath, width, height, _idx, _idx2, _Xval, _Xval2);
	_width = width;
	_height = height;
	_center = 40;
	_center2 = 42;
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	GenSingleList();
    glFlush();
}

void Feather::Render(FType type)
{
	glBindTexture(GL_TEXTURE_2D, _textureID);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	switch (type)
	{
	case SINGLE:
		RenderSingle(false);
		break;
	case SINGLE_TEX:
		RenderSingle(true);
		break;
	case WINGS:
		RenderWings();
		break;
	default:
		break;
	}
}

void Feather::RenderSingle(bool isTex)
{
	if (isTex)
	    glEnable(GL_TEXTURE_2D);
	else 
		glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glCallList(_listName);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	//glFlush();
}

void Feather::RenderWings()
{
	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	glTranslatef(0.0, -0.2, 0.0);// calc the root
	glRotatef((GLfloat)-2,0.0,0.0,1.0);
	glPushMatrix();
	glScalef(1.0, 1.7, 1.0);// scale feather
	glCallList(_listName); 
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.22, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-8, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.65, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.24, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-15, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.6, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.26, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-23, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.5, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.28, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-30, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.4, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.30, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-37, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.35, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.32, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-42, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.3, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.34, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-47, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.25, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.36, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-54, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.2, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.38, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-61, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.15, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.2, -0.8, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-65, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.17, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3, -1.6, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-65, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.20, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2, -2.3, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-65, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.17, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8, -3.1, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-65, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.13, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, -3.9, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-65, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.13, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.2, -4.7, 0.0);
		glPushMatrix();
		glRotatef((GLfloat)-65, 0.0, 0.0, 1.0);
		glPushMatrix();
		glScalef(1.0, 1.13, 1.0);
		glCallList(_listName);
		glPopMatrix();
		glPopMatrix();
		//glTranslatef(1.4, -5.2, 0.0);
		//glPushMatrix();
		//glRotatef((GLfloat)-90, 0.0, 0.0, 1.0);
		//glPushMatrix();
		//glScalef(1.0, 1.12, 1.0);
		//glCallList(listName);
		//glPopMatrix();
		//glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, -5.5, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-74, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1.0, 1.11, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.4, -5.9, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-78, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(0.9, 1.1, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, -6.7, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-85, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(0.9, 1.08, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, -7.3, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-90, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(0.9, 1.07, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8, -7.9, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-91, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(0.85, 1.07, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.65, -8.6, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-93, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(0.85, 1.06, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.55, -9.3, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-95, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(0.85, 1.05, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.45, -10.0, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)-97, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(0.85, 1.04, 1.0);
	glCallList(_listName);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	//glFlush();
}

void Feather::InitLight()
{
	GLfloat mat_ambient[] = { 0.3, 0.3, 0.3, 1.0 }; // define light and material
	GLfloat mat_diffuse[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat mat_specular[] = { 0.6, 0.6, 0.6, 1.0 };
	GLfloat mat_shininess[] = { 80.0 };
	GLfloat model_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat light_position[] = { 1.0, 0.0, 5.0, 0.0 };
	GLfloat light_am[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	GLfloat light_ame[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_am);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, sourceLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_ame);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_BLEND);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

void Feather::GenSingleList()
{
	_listName = glGenLists(1);
	glNewList(_listName, GL_COMPILE);
	float x1 = 0.0;
	for (float t = 0.01; t < 0.73; t = t + 0.01)
	{
		int number1;
		number1 = (int)(t / 0.01);
		float x = 4.0 * t * t * t - 5.0 * t * t + t;
		float y = 5.0 * t * t * t - 9.0 * t * t - 3.0 * t + 4.0;
		x1 = 1.0 / 6.0 - sqrt((1.0 / 12.0 + 4.0 - y - x) / 3.0);
		float y1 = y + x - x1 + t * 0.1;
		float d = sqrt(2 * (x1 - x) * (x1 - x));
		float p[2][3] = { {x,y,0.0},{x1,y1,0.0} };
		float r[2][3] = { {-1.0 * d,0.5 * d,-0.5},{-1.0 * d,2.0 * d,0.0} };
		DrawCubicHermiteCurveBarb(p, r, 10, number1);
	}

	for (float t1 = 0.73; t1 < 0.82; t1 = t1 + 0.01)
	{
		int number2;
		number2 = (int)(t1 / 0.01);
		float xx = 4.0 * t1 * t1 * t1 - 5.0 * t1 * t1 + t1;
		float yy = 5.0 * t1 * t1 * t1 - 9.0 * t1 * t1 - 3.0 * t1 + 4.0;
		float xx1 = x1 + 0.008 + 20.0 * (t1 - 0.715) * (t1 - 0.715);
		float yy1 = yy + xx - xx1 + t1 * 0.1 - (t1 - 0.715) * 1.8;
		float d = sqrt(2 * (xx1 - xx) * (xx1 - xx));
		float p2[2][3] = { {xx,yy,0.0},{xx1,yy1,0.0} };
		float r2[2][3] = { {-1.0 * d,0.5 * d,-0.5},{-1.0 * d,2.0 * d,0.0} };
		DrawCubicHermiteCurveBarb(p2, r2, 10, number2);
	}
	float j1 = 0.0;
	for (float n = 0.01; n < 0.73; n = n + 0.01)
	{
		int number3;
		number3 = (int)(n / 0.01);
		float j = 4.0 * n * n * n - 5.0 * n * n + n;
		float k = 5.0 * n * n * n - 9.0 * n * n - 3.0 * n + 4.0;
		j1 = sqrt((36.0 - 36.0 / 37.0 * (2.0 * k - 2 - j) * (2.0 * k - 2 - j)) / 37.0) - (2.0 * k - 2 - j) / 37.0;
		float k1 = k + 1.0 / 2.0 * (j1 - j) - 0.12 * (int)(n + 0.4);
		float s = sqrt(sqrt(5.0) / 2.0 * (j1 - j) * (j1 - j));
		float p3[2][3] = { {j,k,0.0},{j1,k1,0.0} };
		float r3[2][3] = { {1.0 * s,0.3 * s,0.5},{1.0 * s,1.5 * s,0.0} };
		DrawCubicHermiteCurveBarb(p3, r3, 10, number3);
	}
	for (float n1 = 0.73; n1 < 0.82; n1 = n1 + 0.01)
	{
		int number4;
		number4 = (int)(n1 / 0.01);
		float jj = 4.0 * n1 * n1 * n1 - 5.0 * n1 * n1 + n1;
		float kk = 5.0 * n1 * n1 * n1 - 9.0 * n1 * n1 - 3.0 * n1 + 4.0;
		float jj1 = j1 - 0.008 - 29.0 * (n1 - 0.715) * (n1 - 0.715);
		float kk1 = kk + 1.0 / 2.0 * (jj1 - jj) - 0.12;
		float s = sqrt(sqrt(5.0) / 2.0 * (jj1 - jj) * (jj1 - jj));
		float p3[2][3] = { {jj,kk,0.0},{jj1,kk1,0.0} };
		float r3[2][3] = { {1.0 * s,0.3 * s,0.5},{1.0 * s,1.5 * s,0.0} };
		DrawCubicHermiteCurveBarb(p3, r3, 10, number4);
	}
	float p1[2][3] = { {0.0,4.0,0.0},{0.0,-3.0,0.0} };// draw scape
	float r1[2][3] = { {1.0,-3.0,0.0},{3.0,-6.0,0.0} };

	DrawCubicHermiteCurveScape(p1, r1, 40);
	glEndList();
}

void Feather::DrawCubicHermiteCurveBarb(float P[2][3], float R[2][3], int count, int number)
{
	float c[3][4], t, deltat; // draw left feather
	float V[3], newV[3];
	float s = 0.037;
	int i, j;
	for (j = 0; j < 3; j++)
	{
		c[j][0] = P[0][j];
		c[j][1] = R[0][j];
		c[j][2] = (-3) * P[0][j] + 3 * P[1][j] - 2 * R[0][j] - R[1][j];
		c[j][3] = 2 * P[0][j] - 2 * P[1][j] + R[0][j] + R[1][j];
	}

	V[0] = P[0][0];
	V[1] = P[0][1];
	V[2] = P[0][2];

	t = 0.0;
	deltat = 1.0 / count;

	for (i = 1; i < count; i++) {
		t += deltat;
		newV[0] = c[0][0] + t * (c[0][1] + t * (c[0][2] + t * c[0][3]));
		newV[1] = c[1][0] + t * (c[1][1] + t * (c[1][2] + t * c[1][3]));
		newV[2] = c[2][0] + t * (c[2][1] + t * (c[2][2] + t * c[2][3]));
		float side = sqrt((newV[0] - V[0]) * (newV[0] - V[0]) + (newV[1] - V[1]) * (newV[1] - V[1]));
		glLineWidth(1.0);

		glBegin(GL_QUADS);
		glTexCoord2f((float)(_center - (_center - _Xval[number + 1]) / 10 * i) / _width,
			(float)(6 + 4 * number) / _height);
		glNormal3f(0.0f, 0.0f, 1.0f); // vertex vector
		glVertex3f(newV[0], newV[1], newV[2] + s);
		glTexCoord2f((float)(_center - (_center - _Xval[number + 1]) / 10 * i) / _width,
			(float)(5 + 4 * number) / _height);
		glNormal3f(sin(PI / 5) * ((newV[0] - V[0]) / side),
			sin(PI / 5) * (-(newV[1] - V[1]) / side), cos(PI / 5));
		glVertex3f(newV[0], newV[1] - sin(PI / 5) * s, newV[2] + cos(PI / 5) * s);
		glTexCoord2f((float)(_center - (_center - _Xval[number + 1]) / 10 * (i - 1)) / _width,
			(float)(5 + 4 * number) / _height);
		glNormal3f(sin(PI / 5) * ((newV[0] - V[0]) / side),
			sin(PI / 5) * (-(newV[1] - V[1]) / side), cos(PI / 5));
		glVertex3f(V[0], V[1] - sin(PI / 5) * s, V[2] + cos(PI / 5) * s);
		glTexCoord2f((float)(_center - (_center - _Xval[number + 1]) / 10 * (i - 1)) / _width,
			(float)(6 + 4 * number) / _height);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(V[0], V[1], V[2] + s);
		glTexCoord2f((float)(_center - (_center - _Xval[number]) / 10.0 * i) / _width,
			(float)(5 + 4 * number) / _height);
		glNormal3f(sin(PI / 5) * ((newV[0] - V[0]) / side),
			sin(PI / 5) * (-(newV[1] - V[1]) / side), cos(PI / 5));
		glVertex3f(newV[0], newV[1] - sin(PI / 5) * s, newV[2] + cos(PI / 5) * s);
		glTexCoord2f((float)(_center - (_center - _Xval[number]) / 10.0 * i) / _width,
			(float)(4 + 4 * number) / _height);
		glNormal3f(sin(2 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(2 * PI / 5) * (-(newV[1] - V[1]) / side), cos(2 * PI / 5));
		glVertex3f(newV[0], newV[1] - sin(2 * PI / 5) * s, newV[2] + cos(2 * PI / 5) * s);
		glTexCoord2f((float)(_center - (_center - _Xval[number]) / 10.0 * (i - 1)) / _width,
			(float)(4 + 4 * number) / _height);
		glNormal3f(sin(2 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(2 * PI / 5) * (-(newV[1] - V[1]) / side), cos(2 * PI / 5));
		glVertex3f(V[0], V[1] - sin(2 * PI / 5) * s, V[2] + cos(2 * PI / 5) * s);
		glTexCoord2f((float)(_center - (_center - _Xval[number]) / 10.0 * (i - 1)) / _width,
			(float)(5 + 4 * number) / _height);
		glNormal3f(sin(PI / 5) * ((newV[0] - V[0]) / side),
			sin(PI / 5) * (-(newV[1] - V[1]) / side), cos(PI / 5));
		glVertex3f(V[0], V[1] - sin(PI / 5) * s, V[2] + cos(PI / 5) * s);
		glTexCoord2f((float)(_center - (_center - _Xval[number - 1]) / 10.0 * i) / _width,
			(float)(4 + 4 * number) / _height);
		glNormal3f(sin(2 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(2 * PI / 5) * (-(newV[1] - V[1]) / side), cos(2 * PI / 5));
		glVertex3f(newV[0], newV[1] - sin(2 * PI / 5) * s, newV[2] + cos(2 * PI / 5) * s);

		glTexCoord2f((float)(_center - (_center - _Xval[number - 1]) / 10.0 * i) / _width,
			(float)(3 + 4 * number) / _height);
		glNormal3f(sin(3 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(3 * PI / 5) * (-(newV[1] - V[1]) / side), cos(3 * PI / 5));
		glVertex3f(newV[0], newV[1] - sin(3 * PI / 5) * s, newV[2] + cos(3 * PI / 5) * s);
		glTexCoord2f((float)(_center - (_center - _Xval[number - 1]) / 10 * (i - 1)) / _width,
			(float)(3 + 4 * number) / _height);
		glNormal3f(sin(3 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(3 * PI / 5) * (-(newV[1] - V[1]) / side), cos(3 * PI / 5));
		glVertex3f(V[0], V[1] - sin(3 * PI / 5) * s, V[2] + cos(3 * PI / 5) * s);
		glTexCoord2f((float)(_center - (_center - _Xval[number - 1]) / 10 * (i - 1)) / _width,
			(float)(4 + 4 * number) / _height);
		glNormal3f(sin(2 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(2 * PI / 5) * (-(newV[1] - V[1]) / side), cos(2 * PI / 5));
		glVertex3f(V[0], V[1] - sin(2 * PI / 5) * s, V[2] + cos(2 * PI / 5) * s);
		glNormal3f(sin(3 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(3 * PI / 5) * (-(newV[1] - V[1]) / side), cos(3 * PI / 5));
		glVertex3f(newV[0], newV[1] - sin(3 * PI / 5) * s, newV[2] + cos(3 * PI / 5) * s);
		glNormal3f(sin(4 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(4 * PI / 5) * (-(newV[1] - V[1]) / side), cos(4 * PI / 5));
		glVertex3f(newV[0], newV[1] - sin(4 * PI / 5) * s, newV[2] + cos(4 * PI / 5) * s);
		glNormal3f(sin(4 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(4 * PI / 5) * (-(newV[1] - V[1]) / side), cos(4 * PI / 5));
		glVertex3f(V[0], V[1] - sin(4 * PI / 5) * s, V[2] + cos(4 * PI / 5) * s);
		glNormal3f(sin(3 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(3 * PI / 5) * (-(newV[1] - V[1]) / side), cos(3 * PI / 5));
		glVertex3f(V[0], V[1] - sin(3 * PI / 5) * s, V[2] + cos(3 * PI / 5) * s);
		glNormal3f(sin(4 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(4 * PI / 5) * (-(newV[1] - V[1]) / side), cos(4 * PI / 5));
		glVertex3f(newV[0], newV[1] - sin(4 * PI / 5) * s, newV[2] + cos(4 * PI / 5) * s);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(newV[0], newV[1], newV[2] - s);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(V[0], V[1], V[2] - s);
		glNormal3f(sin(4 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(4 * PI / 5) * (-(newV[1] - V[1]) / side), cos(4 * PI / 5));
		glVertex3f(V[0], V[1] - sin(4 * PI / 5) * s, V[2] + cos(4 * PI / 5) * s);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(newV[0], newV[1], newV[2] - s);
		glNormal3f(sin(6 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(6 * PI / 5) * (-(newV[1] - V[1]) / side), cos(6 * PI / 5));



		glVertex3f(newV[0], newV[1] - sin(6 * PI / 5) * s, newV[2] + cos(6 * PI / 5) * s);
		glNormal3f(sin(6 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(6 * PI / 5) * (-(newV[1] - V[1]) / side), cos(6 * PI / 5));
		glVertex3f(V[0], V[1] - sin(6 * PI / 5) * s, V[2] + cos(6 * PI / 5) * s);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(V[0], V[1], V[2] - s);
		glNormal3f(sin(6 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(6 * PI / 5) * (-(newV[1] - V[1]) / side), cos(6 * PI / 5));
		glVertex3f(newV[0], newV[1] - sin(6 * PI / 5) * s, newV[2] + cos(6 * PI / 5) * s);
		glNormal3f(sin(7 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(7 * PI / 5) * (-(newV[1] - V[1]) / side), cos(7 * PI / 5));
		glVertex3f(newV[0], newV[1] - sin(7 * PI / 5) * s, newV[2] + cos(7 * PI / 5) * s);
		glNormal3f(sin(7 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(7 * PI / 5) * (-(newV[1] - V[1]) / side), cos(7 * PI / 5));
		glVertex3f(V[0], V[1] - sin(7 * PI / 5) * s, V[2] + cos(7 * PI / 5) * s);
		glNormal3f(sin(6 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(6 * PI / 5) * (-(newV[1] - V[1]) / side), cos(6 * PI / 5));
		glVertex3f(V[0], V[1] - sin(6 * PI / 5) * s, V[2] + cos(6 * PI / 5) * s);
		glNormal3f(sin(7 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(7 * PI / 5) * (-(newV[1] - V[1]) / side), cos(7 * PI / 5));
		glVertex3f(newV[0], newV[1] - sin(7 * PI / 5) * s, newV[2] + cos(7 * PI / 5) * s);
		glNormal3f(sin(8 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(8 * PI / 5) * (-(newV[1] - V[1]) / side), cos(8 * PI / 5));
		glVertex3f(newV[0], newV[1] - sin(8 * PI / 5) * s, newV[2] + cos(8 * PI / 5) * s);
		glNormal3f(sin(8 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(8 * PI / 5) * (-(newV[1] - V[1]) / side), cos(8 * PI / 5));
		glVertex3f(V[0], V[1] - sin(8 * PI / 5) * s, V[2] + cos(8 * PI / 5) * s);
		glNormal3f(sin(7 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(7 * PI / 5) * (-(newV[1] - V[1]) / side), cos(7 * PI / 5));
		glVertex3f(V[0], V[1] - sin(7 * PI / 5) * s, V[2] + cos(7 * PI / 5) * s);
		glTexCoord2f((float)(_center - (_center - _Xval[number + 3]) / 10.0 * i) / _width,
			(float)(8 + 4 * number) / _height);
		glNormal3f(sin(8 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(8 * PI / 5) * (-(newV[1] - V[1]) / side), cos(8 * PI / 5));
		glVertex3f(newV[0], newV[1] - sin(8 * PI / 5) * s, newV[2] + cos(8 * PI / 5) * s);
		glTexCoord2f((float)(_center - (_center - _Xval[number + 3]) / 10.0 * i) / _width,
			(float)(7 + 4 * number) / _height);
		glNormal3f(sin(9 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(9 * PI / 5) * (-(newV[1] - V[1]) / side), cos(9 * PI / 5));
		glVertex3f(newV[0], newV[1] - sin(9 * PI / 5) * s, newV[2] + cos(9 * PI / 5) * s);
		glTexCoord2f((float)(_center - (_center - _Xval[number + 3]) / 10 * i) / _width,
			(float)(7 + 4 * number) / _height);
		glNormal3f(sin(9 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(9 * PI / 5) * (-(newV[1] - V[1]) / side), cos(9 * PI / 5));
		glVertex3f(V[0], V[1] - sin(9 * PI / 5) * s, V[2] + cos(9 * PI / 5) * s);
		glTexCoord2f((float)(_center - (_center - _Xval[number + 3]) / 10 * i) / _width,
			(float)(8 + 4 * number) / _height);
		glNormal3f(sin(8 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(8 * PI / 5) * (-(newV[1] - V[1]) / side), cos(8 * PI / 5));
		glVertex3f(V[0], V[1] - sin(8 * PI / 5) * s, V[2] + cos(8 * PI / 5) * s);
		glTexCoord2f((float)(_center - (_center - _Xval[number + 2]) / 10 * i) / _width,
			(float)(7 + 4 * number) / _height);
		glNormal3f(sin(9 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(9 * PI / 5) * (-(newV[1] - V[1]) / side), cos(9 * PI / 5));
		glVertex3f(newV[0], newV[1] - sin(9 * PI / 5) * s, newV[2] + cos(9 * PI / 5) * s);
		glTexCoord2f((float)(_center - (_center - _Xval[number + 2]) / 10 * i) / _width,
			(float)(6 + 4 * number) / _height);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(newV[0], newV[1], newV[2] + s);
		glTexCoord2f((float)(_center - (_center - _Xval[number + 2]) / 10 * i) / _width,
			(float)(6 + 4 * number) / _height);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(V[0], V[1], V[2] + s);
		glTexCoord2f((float)(_center - (_center - _Xval[number + 2]) / 10 * i) / _width,
			(float)(7 + 4 * number) / _height);
		glNormal3f(sin(9 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(9 * PI / 5) * (-(newV[1] - V[1]) / side), cos(9 * PI / 5));
		glVertex3f(V[0], V[1] - sin(9 * PI / 5) * s, V[2] + cos(9 * PI / 5) * s);
		glEnd();


		V[0] = newV[0], V[1] = newV[1], V[2] = newV[2];
	}
	glFlush();
}
void Feather::DrawCubicHermiteCurveBarb2(float P[2][3], float R[2][3], int count, int number)
{
	float c[3][4], t, deltat; // draw left barb
	float V[3], newV[3];
	float s = 0.037;
	float ss = 0.03;
	int i, j;
	for (j = 0; j < 3; j++) {
		c[j][0] = P[0][j];
		c[j][1] = R[0][j];
		c[j][2] = (-3) * P[0][j] + 3 * P[1][j] - 2 * R[0][j] - R[1][j];
		c[j][3] = 2 * P[0][j] - 2 * P[1][j] + R[0][j] + R[1][j];
	}

	V[0] = P[0][0], V[1] = P[0][1], V[2] = P[0][2];
	t = 0.0;
	deltat = 1.0 / count;
	for (i = 1; i <= count; i++)
	{
		t += deltat;
		newV[0] = c[0][0] + t * (c[0][1] + t * (c[0][2] + t * c[0][3]));
		newV[1] = c[1][0] + t * (c[1][1] + t * (c[1][2] + t * c[1][3]));
		newV[2] = c[2][0] + t * (c[2][1] + t * (c[2][2] + t * c[2][3]));
		float side = sqrt((newV[0] - V[0]) * (newV[0] - V[0]) + (newV[1] - V[1]) * (newV[1] - V[1]));
		glLineWidth(1.0);
		glBegin(GL_QUADS);
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number + 1]) / 10 * (i - 1)) / _width,
			(float)(6 + 4 * number) / _height);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(V[0] + ss, V[1], V[2] + s);
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number + 1]) / 10 * (i - 1)) / _width,
			(float)(5 + 4 * number) / _height);
		glNormal3f(sin(PI / 5) * ((newV[0] - V[0]) / side),
			sin(PI / 5) * (-(newV[1] - V[1]) / side), cos(PI / 5));
		glVertex3f(V[0] + ss, V[1] - sin(PI / 5) * s, V[2] + cos(PI / 5) * s);
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number + 1]) / 10.0 * i) / _width,
			(float)(5 + 4 * number) / _height);
		glNormal3f(sin(PI / 5) * ((newV[0] - V[0]) / side),
			sin(PI / 5) * (-(newV[1] - V[1]) / side), cos(PI / 5));
		glVertex3f(newV[0] + ss, newV[1] - sin(PI / 5) * s, newV[2] + cos(PI / 5) * s);
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number + 1]) / 10.0 * i) / _width,
			(float)(6 + 4 * number) / _height);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(newV[0] + ss, newV[1], newV[2] + s);
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number]) / 10.0 * (i - 1)) / _width,
			(float)(5 + 4 * number) / _height);
		glNormal3f(sin(PI / 5) * ((newV[0] - V[0]) / side),
			sin(PI / 5) * (-(newV[1] - V[1]) / side), cos(PI / 5));
		glVertex3f(V[0] + ss, V[1] - sin(PI / 5) * s, V[2] + cos(PI / 5) * s);
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number]) / 10.0 * (i - 1)) / _width,
			(float)(4 + 4 * number) / _height);
		glNormal3f(sin(2 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(2 * PI / 5) * (-(newV[1] - V[1]) / side), cos(2 * PI / 5));
		glVertex3f(V[0] + ss, V[1] - sin(2 * PI / 5) * s, V[2] + cos(2 * PI / 5) * s);

		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number]) / 10.0 * i) / _width,
			(float)(4 + 4 * number) / _height);
		glNormal3f(sin(2 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(2 * PI / 5) * (-(newV[1] - V[1]) / side), cos(2 * PI / 5));
		glVertex3f(newV[0] + ss, newV[1] - sin(2 * PI / 5) * s, newV[2] + cos(2 * PI / 5) * s);
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number]) / 10.0 * i) / _width,
			(float)(5 + 4 * number) / _height);
		glNormal3f(sin(PI / 5) * ((newV[0] - V[0]) / side),
			sin(PI / 5) * (-(newV[1] - V[1]) / side), cos(PI / 5));
		glVertex3f(newV[0] + ss, newV[1] - sin(PI / 5) * s, newV[2] + cos(PI / 5) * s);
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number - 1]) / 10 * (i - 1)) / _width,
			(float)(4 + 4 * number) / _height);
		glNormal3f(sin(2 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(2 * PI / 5) * (-(newV[1] - V[1]) / side), cos(2 * PI / 5));
		glVertex3f(V[0] + ss, V[1] - sin(2 * PI / 5) * s, V[2] + cos(2 * PI / 5) * s);
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number - 1]) / 10 * (i - 1)) / _width,
			(float)(3 + 4 * number) / _height);
		glNormal3f(sin(3 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(3 * PI / 5) * (-(newV[1] - V[1]) / side), cos(3 * PI / 5));
		glVertex3f(V[0] + ss, V[1] - sin(3 * PI / 5) * s, V[2] + cos(3 * PI / 5) * s);
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number - 1]) / 10.0 * i) / _width,
			(float)(3 + 4 * number) / _height);
		glNormal3f(sin(3 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(3 * PI / 5) * (-(newV[1] - V[1]) / side), cos(3 * PI / 5));
		glVertex3f(newV[0] + ss, newV[1] - sin(3 * PI / 5) * s, newV[2] + cos(3 * PI / 5) * s);
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number - 1]) / 10.0 * i) / _width,
			(float)(4 + 4 * number) / _height);
		glNormal3f(sin(2 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(2 * PI / 5) * (-(newV[1] - V[1]) / side), cos(2 * PI / 5));
		glVertex3f(newV[0] + ss, newV[1] - sin(2 * PI / 5) * s, newV[2] + cos(2 * PI / 5) * s);
		glNormal3f(sin(3 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(3 * PI / 5) * (-(newV[1] - V[1]) / side), cos(3 * PI / 5));
		glVertex3f(newV[0] + ss, newV[1] - sin(3 * PI / 5) * s, newV[2] + cos(3 * PI / 5) * s);
		glNormal3f(sin(4 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(4 * PI / 5) * (-(newV[1] - V[1]) / side), cos(4 * PI / 5));
		glVertex3f(newV[0] + ss, newV[1] - sin(4 * PI / 5) * s, newV[2] + cos(4 * PI / 5) * s);
		glNormal3f(sin(4 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(4 * PI / 5) * (-(newV[1] - V[1]) / side), cos(4 * PI / 5));
		glVertex3f(V[0] + ss, V[1] - sin(4 * PI / 5) * s, V[2] + cos(4 * PI / 5) * s);
		glNormal3f(sin(3 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(3 * PI / 5) * (-(newV[1] - V[1]) / side), cos(3 * PI / 5));
		glVertex3f(V[0] + ss, V[1] - sin(3 * PI / 5) * s, V[2] + cos(3 * PI / 5) * s);
		glNormal3f(sin(4 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(4 * PI / 5) * (-(newV[1] - V[1]) / side), cos(4 * PI / 5));
		glVertex3f(newV[0] + ss, newV[1] - sin(4 * PI / 5) * s, newV[2] + cos(4 * PI / 5) * s);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(newV[0] + ss, newV[1], newV[2] - s);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(V[0] + ss, V[1], V[2] - s);
		glNormal3f(sin(4 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(4 * PI / 5) * (-(newV[1] - V[1]) / side), cos(4 * PI / 5));
		glVertex3f(V[0] + ss, V[1] - sin(4 * PI / 5) * s, V[2] + cos(4 * PI / 5) * s);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(newV[0] + ss, newV[1], newV[2] - s);
		glNormal3f(sin(6 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(6 * PI / 5) * (-(newV[1] - V[1]) / side), cos(6 * PI / 5));
		glVertex3f(newV[0] + ss, newV[1] - sin(6 * PI / 5) * s, newV[2] + cos(6 * PI / 5) * s);
		glNormal3f(sin(6 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(6 * PI / 5) * (-(newV[1] - V[1]) / side), cos(6 * PI / 5));
		glVertex3f(V[0] + ss, V[1] - sin(6 * PI / 5) * s, V[2] + cos(6 * PI / 5) * s);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(V[0] + ss, V[1], V[2] - s);
		glNormal3f(sin(6 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(6 * PI / 5) * (-(newV[1] - V[1]) / side), cos(6 * PI / 5));
		glVertex3f(newV[0] + ss, newV[1] - sin(6 * PI / 5) * s, newV[2] + cos(6 * PI / 5) * s);
		glNormal3f(sin(7 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(7 * PI / 5) * (-(newV[1] - V[1]) / side), cos(7 * PI / 5));
		glVertex3f(newV[0] + ss, newV[1] - sin(7 * PI / 5) * s, newV[2] + cos(7 * PI / 5) * s);
		glNormal3f(sin(7 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(7 * PI / 5) * (-(newV[1] - V[1]) / side), cos(7 * PI / 5));
		glVertex3f(V[0] + ss, V[1] - sin(7 * PI / 5) * s, V[2] + cos(7 * PI / 5) * s);
		glNormal3f(sin(6 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(6 * PI / 5) * (-(newV[1] - V[1]) / side), cos(6 * PI / 5));
		glVertex3f(V[0] + ss, V[1] - sin(6 * PI / 5) * s, V[2] + cos(6 * PI / 5) * s);
		glNormal3f(sin(7 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(7 * PI / 5) * (-(newV[1] - V[1]) / side), cos(7 * PI / 5));
		glVertex3f(newV[0] + ss, newV[1] - sin(7 * PI / 5) * s, newV[2] + cos(7 * PI / 5) * s);
		glNormal3f(sin(8 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(8 * PI / 5) * (-(newV[1] - V[1]) / side), cos(8 * PI / 5));
		glVertex3f(newV[0] + ss, newV[1] - sin(8 * PI / 5) * s, newV[2] + cos(8 * PI / 5) * s);
		glNormal3f(sin(8 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(8 * PI / 5) * (-(newV[1] - V[1]) / side), cos(8 * PI / 5));
		glVertex3f(V[0] + ss, V[1] - sin(8 * PI / 5) * s, V[2] + cos(8 * PI / 5) * s);
		glNormal3f(sin(7 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(7 * PI / 5) * (-(newV[1] - V[1]) / side), cos(7 * PI / 5));
		glVertex3f(V[0] + ss, V[1] - sin(7 * PI / 5) * s, V[2] + cos(7 * PI / 5) * s);
		glNormal3f(sin(8 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(8 * PI / 5) * (-(newV[1] - V[1]) / side), cos(8 * PI / 5));
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number + 3]) / 10 * (i - 1)) / _width,
			(float)(8 + 4 * number) / _height);
		glVertex3f(V[0] + ss, V[1] - sin(8 * PI / 5) * s, V[2] + cos(8 * PI / 5) * s);
		glNormal3f(sin(9 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(9 * PI / 5) * (-(newV[1] - V[1]) / side), cos(9 * PI / 5));
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number + 3]) / 10 * (i - 1)) / _width,
			(float)(7 + 4 * number) / _height);
		glVertex3f(V[0] + ss, V[1] - sin(9 * PI / 5) * s, V[2] + cos(9 * PI / 5) * s);
		glNormal3f(sin(9 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(9 * PI / 5) * (-(newV[1] - V[1]) / side), cos(9 * PI / 5));
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number + 3]) / 10.0 * i) / _width,
			(float)(7 + 4 * number) / _height);
		glVertex3f(newV[0] + ss, newV[1] - sin(9 * PI / 5) * s, newV[2] + cos(9 * PI / 5) * s);
		glNormal3f(sin(8 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(8 * PI / 5) * (-(newV[1] - V[1]) / side), cos(8 * PI / 5));
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number + 3]) / 10.0 * i) / _width,
			(float)(8 + 4 * number) / _height);
		glVertex3f(newV[0] + ss, newV[1] - sin(8 * PI / 5) * s, newV[2] + cos(8 * PI / 5) * s);
		glNormal3f(sin(9 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(9 * PI / 5) * (-(newV[1] - V[1]) / side), cos(9 * PI / 5));
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number + 2]) / 10 * (i - 1)) / _width,
			(float)(7 + 4 * number) / _height);
		glVertex3f(V[0] + ss, V[1] - sin(9 * PI / 5) * s, V[2] + cos(9 * PI / 5) * s);
		glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number + 2]) / 10 * (i - 1)) / _width,
			(float)(6 + 4 * number) / _height);
		glVertex3f(V[0] + ss, V[1], V[2] + s);
		glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number + 2]) / 10.0 * i) / _width,
			(float)(6 + 4 * number) / _height);
		glVertex3f(newV[0] + ss, newV[1], newV[2] + s);
		glNormal3f(sin(9 * PI / 5) * ((newV[0] - V[0]) / side),
			sin(9 * PI / 5) * (-(newV[1] - V[1]) / side), cos(9 * PI / 5));
		glTexCoord2f((float)(_center2 - (_center2 - _Xval2[number + 2]) / 10.0 * i) / _width,
			(float)(7 + 4 * number) / _height);
		glVertex3f(newV[0] + ss, newV[1] - sin(9 * PI / 5) * s, newV[2] + cos(9 * PI / 5) * s);
		glEnd();
		V[0] = newV[0], V[1] = newV[1], V[2] = newV[2];
	}
}
void Feather::DrawCubicHermiteCurveScape(float P[2][3], float R[2][3], int count)
{
	float c[3][4], t, deltat; //draw scape
	float V[3], newV[3];
	int i, j;
	for (j = 0; j < 3; j++)
	{
		c[j][0] = P[0][j];
		c[j][1] = R[0][j];
		c[j][2] = (-3) * P[0][j] + 3 * P[1][j] - 2 * R[0][j] - R[1][j];
		c[j][3] = 2 * P[0][j] - 2 * P[1][j] + R[0][j] + R[1][j];
	}
	V[0] = P[0][0], V[1] = P[0][1], V[2] = P[0][2];
	t = 0.0;
	deltat = 1.0 / count;
	for (i = 1; i <= count; i++)
	{
		float s = 0.036 + 0.0002 * i;
		t += deltat;
		newV[0] = c[0][0] + t * (c[0][1] + t * (c[0][2] + t * c[0][3]));
		newV[1] = c[1][0] + t * (c[1][1] + t * (c[1][2] + t * c[1][3]));
		newV[2] = c[2][0] + t * (c[2][1] + t * (c[2][2] + t * c[2][3]));
		float side = sqrt((newV[0] - V[0]) * (newV[0] - V[0]) + (newV[1] - V[1]) * (newV[1] - V[1]));
		glLineWidth(1.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(newV[0], newV[1], newV[2] + s);
		glNormal3f(sin(PI / 5) * (-(newV[0] - V[0]) / side),
			sin(PI / 5) * (-(newV[1] - V[1]) / side), cos(PI / 5));
		glVertex3f(newV[0] - sin(PI / 5) * s, newV[1], newV[2] + cos(PI / 5) * s);
		glNormal3f(sin(PI / 5) * (-(newV[0] - V[0]) / side),
			sin(PI / 5) * (-(newV[1] - V[1]) / side), cos(PI / 5));
		glVertex3f(V[0] - sin(PI / 5) * s, V[1], V[2] + cos(PI / 5) * s);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(V[0], V[1], V[2] + s);
		glNormal3f(sin(PI / 5) * (-(newV[0] - V[0]) / side),
			sin(PI / 5) * (-(newV[1] - V[1]) / side), cos(PI / 5));
		glVertex3f(newV[0] - sin(PI / 5) * s, newV[1], newV[2] + cos(PI / 5) * s);
		glNormal3f(sin(2 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(2 * PI / 5) * (-(newV[1] - V[1]) / side), cos(2 * PI / 5));


		glVertex3f(newV[0] - sin(2 * PI / 5) * s, newV[1], newV[2] + cos(2 * PI / 5) * s);
		glNormal3f(sin(2 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(2 * PI / 5) * (-(newV[1] - V[1]) / side), cos(2 * PI / 5));
		glVertex3f(V[0] - sin(2 * PI / 5) * s, V[1], V[2] + cos(2 * PI / 5) * s);
		glNormal3f(sin(PI / 5) * (-(newV[0] - V[0]) / side),
			sin(PI / 5) * (-(newV[1] - V[1]) / side), cos(PI / 5));
		glVertex3f(V[0] - sin(PI / 5) * s, V[1], V[2] + cos(PI / 5) * s);
		glNormal3f(sin(2 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(2 * PI / 5) * (-(newV[1] - V[1]) / side), cos(2 * PI / 5));
		glVertex3f(newV[0] - sin(2 * PI / 5) * s, newV[1], newV[2] + cos(2 * PI / 5) * s);
		glNormal3f(sin(3 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(3 * PI / 5) * (-(newV[1] - V[1]) / side), cos(3 * PI / 5));
		glVertex3f(newV[0] - sin(3 * PI / 5) * s, newV[1], newV[2] + cos(3 * PI / 5) * s);
		glNormal3f(sin(3 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(3 * PI / 5) * (-(newV[1] - V[1]) / side), cos(3 * PI / 5));
		glVertex3f(V[0] - sin(3 * PI / 5) * s, V[1], V[2] + cos(3 * PI / 5) * s);
		glNormal3f(sin(2 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(2 * PI / 5) * (-(newV[1] - V[1]) / side), cos(2 * PI / 5));
		glVertex3f(V[0] - sin(2 * PI / 5) * s, V[1], V[2] + cos(2 * PI / 5) * s);
		glNormal3f(sin(3 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(3 * PI / 5) * (-(newV[1] - V[1]) / side), cos(3 * PI / 5));
		glVertex3f(newV[0] - sin(3 * PI / 5) * s, newV[1], newV[2] + cos(3 * PI / 5) * s);
		glNormal3f(sin(4 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(4 * PI / 5) * (-(newV[1] - V[1]) / side), cos(4 * PI / 5));
		glVertex3f(newV[0] - sin(4 * PI / 5) * s, newV[1], newV[2] + cos(4 * PI / 5) * s);
		glNormal3f(sin(4 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(4 * PI / 5) * (-(newV[1] - V[1]) / side), cos(4 * PI / 5));
		glVertex3f(V[0] - sin(4 * PI / 5) * s, V[1], V[2] + cos(4 * PI / 5) * s);
		glNormal3f(sin(3 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(3 * PI / 5) * (-(newV[1] - V[1]) / side), cos(3 * PI / 5));
		glVertex3f(V[0] - sin(3 * PI / 5) * s, V[1], V[2] + cos(3 * PI / 5) * s);
		glNormal3f(sin(4 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(4 * PI / 5) * (-(newV[1] - V[1]) / side), cos(4 * PI / 5));
		glVertex3f(newV[0] - sin(4 * PI / 5) * s, newV[1], newV[2] + cos(4 * PI / 5) * s);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(newV[0], newV[1], newV[2] - s);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(V[0], V[1], V[2] - s);
		glNormal3f(sin(4 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(4 * PI / 5) * (-(newV[1] - V[1]) / side), cos(4 * PI / 5));
		glVertex3f(V[0] - sin(4 * PI / 5) * s, V[1], V[2] + cos(4 * PI / 5) * s);
		glNormal3f(0.0, 0.0, -1.0);


		glVertex3f(newV[0], newV[1], newV[2] - s);
		glNormal3f(sin(6 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(6 * PI / 5) * (-(newV[1] - V[1]) / side), cos(6 * PI / 5));
		glVertex3f(newV[0] - sin(6 * PI / 5) * s, newV[1], newV[2] + cos(6 * PI / 5) * s);
		glNormal3f(sin(6 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(6 * PI / 5) * (-(newV[1] - V[1]) / side), cos(6 * PI / 5));
		glVertex3f(V[0] - sin(6 * PI / 5) * s, V[1], V[2] + cos(6 * PI / 5) * s);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(V[0], V[1], V[2] - s);
		glNormal3f(sin(6 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(6 * PI / 5) * (-(newV[1] - V[1]) / side), cos(6 * PI / 5));
		glVertex3f(newV[0] - sin(6 * PI / 5) * s, newV[1], newV[2] + cos(6 * PI / 5) * s);
		glNormal3f(sin(7 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(7 * PI / 5) * (-(newV[1] - V[1]) / side), cos(7 * PI / 5));
		glVertex3f(newV[0] - sin(7 * PI / 5) * s, newV[1], newV[2] + cos(7 * PI / 5) * s);
		glNormal3f(sin(7 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(7 * PI / 5) * (-(newV[1] - V[1]) / side), cos(7 * PI / 5));
		glVertex3f(V[0] - sin(7 * PI / 5) * s, V[1], V[2] + cos(7 * PI / 5) * s);
		glNormal3f(sin(6 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(6 * PI / 5) * (-(newV[1] - V[1]) / side), cos(6 * PI / 5));
		glVertex3f(V[0] - sin(6 * PI / 5) * s, V[1], V[2] + cos(6 * PI / 5) * s);
		glNormal3f(sin(7 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(7 * PI / 5) * (-(newV[1] - V[1]) / side), cos(7 * PI / 5));
		glVertex3f(newV[0] - sin(7 * PI / 5) * s, newV[1], newV[2] + cos(7 * PI / 5) * s);
		glNormal3f(sin(8 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(8 * PI / 5) * (-(newV[1] - V[1]) / side), cos(8 * PI / 5));
		glVertex3f(newV[0] - sin(8 * PI / 5) * s, newV[1], newV[2] + cos(8 * PI / 5) * s);
		glNormal3f(sin(8 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(8 * PI / 5) * (-(newV[1] - V[1]) / side), cos(8 * PI / 5));
		glVertex3f(V[0] - sin(8 * PI / 5) * s, V[1], V[2] + cos(8 * PI / 5) * s);
		glNormal3f(sin(7 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(7 * PI / 5) * (-(newV[1] - V[1]) / side), cos(7 * PI / 5));
		glVertex3f(V[0] - sin(7 * PI / 5) * s, V[1], V[2] + cos(7 * PI / 5) * s);
		glNormal3f(sin(8 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(8 * PI / 5) * (-(newV[1] - V[1]) / side), cos(8 * PI / 5));
		glVertex3f(newV[0] - sin(8 * PI / 5) * s, newV[1], newV[2] + cos(8 * PI / 5) * s);
		glNormal3f(sin(9 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(9 * PI / 5) * (-(newV[1] - V[1]) / side), cos(9 * PI / 5));
		glVertex3f(newV[0] - sin(9 * PI / 5) * s, newV[1], newV[2] + cos(9 * PI / 5) * s);
		glNormal3f(sin(9 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(9 * PI / 5) * (-(newV[1] - V[1]) / side), cos(9 * PI / 5));
		glVertex3f(V[0] - sin(9 * PI / 5) * s, V[1], V[2] + cos(9 * PI / 5) * s);
		glNormal3f(sin(8 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(8 * PI / 5) * (-(newV[1] - V[1]) / side), cos(8 * PI / 5));
		glVertex3f(V[0] - sin(8 * PI / 5) * s, V[1], V[2] + cos(8 * PI / 5) * s);
		glNormal3f(sin(9 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(9 * PI / 5) * (-(newV[1] - V[1]) / side), cos(9 * PI / 5));
		glVertex3f(newV[0] - sin(9 * PI / 5) * s, newV[1], newV[2] + cos(9 * PI / 5) * s);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(newV[0], newV[1], newV[2] + s);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(V[0], V[1], V[2] + s);
		glNormal3f(sin(9 * PI / 5) * (-(newV[0] - V[0]) / side),
			sin(9 * PI / 5) * (-(newV[1] - V[1]) / side), cos(9 * PI / 5));
		glVertex3f(V[0] - sin(9 * PI / 5) * s, V[1], V[2] + cos(9 * PI / 5) * s);
		glEnd();
		V[0] = newV[0], V[1] = newV[1], V[2] = newV[2];
	}
	glFlush();
}
