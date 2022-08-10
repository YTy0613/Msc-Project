#include "imgui.h"
#include "imgui_impl_glut.h"
#include "imgui_impl_opengl2.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "feather.h"
#include "util.h"

#ifdef _MSC_VER
#pragma warning (disable: 4505) // unreferenced local function has been removed
#endif

using namespace std;

static int mouseLeftDown = 0;
static int mouseLeftX = 0;
static int mouseLeftY = 0;

GLfloat clipNear = 0.001;
GLfloat clipFar = 700.0;
GLfloat zoom = -10;
GLfloat viewMatrix[16] = { 1.0f, 0.0f, 0.0f, 0.0f,
						  0.0f, 1.0f, 0.0f, 0.0f,
						  0.0f, 0.0f, 1.0f, 0.0f,
						  0.0f, 0.0f, 0.0f, 1.0f };

Feather feather;

static ImVec4 clearColor = ImVec4(0.35f, 0.37f, 0.4f, 1.00f);
static int renderType;

void reshape(GLsizei w, GLsizei h)
{
	ImGui_ImplGLUT_ReshapeFunc(w, h);
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, (GLfloat)w / (GLfloat)h, clipNear, clipFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void handleMotion(int x, int y) //left button to move camera direction
{
	ImGui_ImplGLUT_MotionFunc(x, y);
	//changes modelview matrix
	if (mouseLeftDown)
	{
		glMatrixMode(GL_MODELVIEW);
		GLfloat m[16];
		Util::Invert(viewMatrix, m);
		GLfloat v[3]{ (y - mouseLeftY) * 0.3f,(x - mouseLeftX) * 0.3f, 0.0f };
		GLfloat o[3];
		Util::Multiply(v, m, o);
		glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(viewMatrix);
		glRotatef(o[0], 1.0f, 0.0f, 0.0f);
		glRotatef(o[1], 0.0f, 1.0f, 0.0f);
		glRotatef(o[2], 0.0f, 0.0f, 1.0f);
		glGetFloatv(GL_MODELVIEW_MATRIX, viewMatrix);
		glPopMatrix();
		mouseLeftX = x;
		mouseLeftY = y;
	}
	glutPostRedisplay();
	return;
}

void handleMouseClick(int button, int state, int x, int y)
{
	ImGui_ImplGLUT_MouseFunc(button, state, x, y);
	//change camera angle
	if (button == GLUT_LEFT_BUTTON)
	{
		switch (state)
		{
		case GLUT_DOWN:
			mouseLeftDown = 1;
			mouseLeftX = x;
			mouseLeftY = y;
			break;
		case GLUT_UP:
			mouseLeftDown = 0;
			break;
		}
	}
	glutPostRedisplay();
	return;
}

#ifdef __FREEGLUT_EXT_H__
void handleMouseWheel(int button, int dir, int x, int y)
{
	ImGui_ImplGLUT_MouseWheelFunc(button, dir, x, y);
	if (dir > 0) {  // zoom in
		if (zoom < -1)
			zoom += 1;
	}
	else {  // zoom out
		if (zoom > -40)
			zoom -= 1;
	}
	glutPostRedisplay();
	return;
}
#endif

void display(void)
{
	// Start the Dear ImGui frame
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplGLUT_NewFrame();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(clearColor.x * clearColor.w, clearColor.y * clearColor.w, clearColor.z * clearColor.w, clearColor.w);

	// Render UI
	{
		ImGui::Begin("Feather Controller"); 
		ImGui::Text("Render Option");
		ImGui::Separator();
		ImGui::RadioButton("Single Feather", &renderType, 0);
		ImGui::RadioButton("Single Feather with Texture", &renderType, 1);
		ImGui::RadioButton("Wings", &renderType, 2);
		ImGui::Separator();
		ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
	}

	// Render Feather
	{
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(0.0, 0.0, zoom);
		glPushMatrix();
		glMultMatrixf(viewMatrix);
		feather.Render(static_cast<FType>(renderType));
		glPopMatrix();
		glPopMatrix();
	}
	
	ImGui::Render();
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

	glutSwapBuffers();
	glutPostRedisplay();
}

void initImgui()
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	// Setup Platform/Renderer backends
	ImGui_ImplGLUT_Init();
	//ImGui_ImplGLUT_InstallFuncs();
	ImGui_ImplOpenGL2_Init();
	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
}

void cleanImgui()
{
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGLUT_Shutdown();
	ImGui::DestroyContext();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
#ifdef __FREEGLUT_EXT_H__
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
#endif
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_MULTISAMPLE);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("feather");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMotionFunc(handleMotion);
	glutMouseFunc(handleMouseClick);
#ifdef __FREEGLUT_EXT_H__
	glutMouseWheelFunc(handleMouseWheel);
#endif

	feather.Init("feather.jpeg");
	initImgui();
	glutMainLoop();
	cleanImgui();
	return 0;
}
