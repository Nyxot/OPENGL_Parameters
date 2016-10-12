#include "gamewindow.h"


void GameWindow::setRunning(bool newRunning)
{
	_running = newRunning;
}

bool GameWindow::getRunning()
{
	return _running;
}

GameWindow::GameWindow(bool running, GLFWwindow* window): _running(running)
{
	_window = window;
	/* glClearColor - specify clear values for the color buffers
	   void glClearColor(GLfloat red, GLfloat green, GLfloat blue,
			     GLfloat alpha); */
	glClearColor(0.003f, 0.66f, 0.85f, 1.0f);

	/* This function retrieves the size, in pixels, of the framebuffer of
	 * the specified window. */
	glfwGetFramebufferSize(window, &_width, &_height);
	glViewport(0, 0, _width, _height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* void glOrtho(GLdouble left, GLdouble right, GLdouble bottom,
			GLdouble top, GLdouble nearVal, GLdouble farVal); */
	glOrtho(0.0, _width, 0.0, _height, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

}

void GameWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f);
/*	glBegin(GL_QUADS);
		glVertex2f(   0.0f,   0.0f);
		glVertex2f( 100.0f,   0.0f);
		glVertex2f( 100.0f, 100.0f);
		glVertex2f(   0.0f, 100.0f);
	glEnd();*/
	glBegin(GL_POINTS);//x, y
	for(float i=0.0; i< 10; i++){
		glVertex2f(i*10.0f, 10.0f);
		glVertex2f(i*10.0f, 11.0f);
	}
	glEnd();

	glBegin(GL_LINES);
		glVertex2f(100.0f, 10.0f);
		glVertex2f(200.0f, 10.0f);
	glEnd();

	glBegin(GL_LINE_STRIP);
		glVertex2f(250.0f, 10.0f);
		glVertex2f(300.0f, 10.0f);
		glVertex2f(275.0f, 20.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(350.0f, 10.0f);
		glVertex2f(400.0f, 10.0f);
		glVertex2f(375.0f, 20.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(450.0f, 10.0f);
		glVertex2f(500.0f, 10.0f);
		glVertex2f(450.0f, 50.0f);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(550.0f, 10.0f);
		glVertex2f(600.0f, 10.0f);
		glVertex2f(550.0f, 50.0f);

		glColor3f(0.0f,1.0f,0.0f);
		glVertex2f(610.0f, 10.0f);
		glVertex2f(650.0f, 10.0f);
		glVertex2f(610.0f, 50.0f);
	glEnd();

	glColor3f(1.0f,0.0f,0.0f);

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(0.0f, 100.0f);
		glVertex2f(100.0f, 100.0f);
		glVertex2f(50.0f, 150.0f);

		glColor3f(0.0f,1.0f,0.0f);
		glVertex2f(110.0f, 100.0f);
		glVertex2f(150.0f, 100.0f);
		glVertex2f(110.0f, 150.0f);
	glEnd();

	glColor3f(1.0f,0.0f,0.0f);

	glBegin(GL_QUADS);
		glVertex2f(200.0f, 100.0f);
		glVertex2f(300.0f, 100.0f);
		glVertex2f(300.0f, 200.0f);
		glVertex2f(200.0f, 200.0f);
	glEnd();

	glBegin(GL_QUAD_STRIP);
		glVertex2f(400.0f, 100.0f);
		glVertex2f(500.0f, 100.0f);
		glVertex2f(500.0f, 200.0f);
		glVertex2f(400.0f, 200.0f);

	glColor3f(0.0f,1.0f,0.0f);
		glVertex2f(600.0f, 100.0f);
		glVertex2f(700.0f, 100.0f);
		glVertex2f(700.0f, 200.0f);
		glVertex2f(600.0f, 200.0f);
	glEnd();

	glColor3f(1.0f,0.0f,0.0f);

	glBegin(GL_POLYGON);
		glVertex2f(220.0f, 400.0f);
		glVertex2f(380.0f, 400.0f);
		glVertex2f(425.0f, 475.0f);
		glVertex2f(300.0f, 550.0f);
		glVertex2f(175.0f, 475.0f);
	glEnd();
	/* Swap front and back buffers */
	glfwSwapBuffers(_window);
}

void GameWindow::update()
{
}
