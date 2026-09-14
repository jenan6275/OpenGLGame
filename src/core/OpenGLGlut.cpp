// OpenGLGlut.cpp : This file contains the 'main' function. Program execution begins and ends there.
///////////////////////////////////////////////////////////////////////
//
// triangles.cpp
//
///////////////////////////////////////////////////////////////////////


//
//#include "core/LoadShaders.h"
//#include <GL/freeglut.h>
//#include <GL/glew.h>
//#include "core/vgl.h"
//#include <iostream>
//
//
//using namespace std;


#include <GL/glew.h>
#include <GL/freeglut.h>
#include "core/LoadShaders.h"
#include "core/vgl.h"
#include <iostream>
using namespace std;

//#include "core/LoadShaders.h"
//
//
//#include <GL/glew.h>
//#include <GL/freeglut.h>
//#include "core/vgl.h"
//#include "core/game.h"



enum VAO_IDs { Triangles, Polygons, NumVAOs };
enum Buffer_IDs { Tringlebuffer,PolyGonbuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0 , vColor = 1 };
GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];
const GLuint NumVertices = 6;
const GLuint NumTringles = 2;
enum Indx_IDs { TringleIndx, PolygonIndx, NumIndx };
GLuint IndxBuffers[NumIndx];
//int timeD;
GLuint program;


//GLfloat vertices[NumVertices][2] = {
//	{ -0.90, -0.90 }, // Triangle 1
//	{ 0.85, -0.90 },
//	{ -0.90, 0.85 },
//	{ 0.90, -0.85 }, // Triangle 2
//	{ 0.90, 0.90 },
//	{ -0.85, 0.90 }
//};


//GLfloat vertices[NumVertices][6] = {
//	{ -0.50, -0.50, 0.0 , 1.0f, 0.0f, 0.0f }, // Triangle 1
//	{  0.50, -0.50, 0.0 , 0.0f, 1.0f, 0.0f },
//	{  0.00,  0.50, 0.0 , 0.0f, 0.0f, 1.0f }
//	
//};

namespace Geometry {
	namespace Tringles{
		GLfloat tringle[][6] = {
			{  0.0f,  0.5f, 0.0f , 1.0f, 1.0f ,0.0f }, // Triangle 1
			{ -0.5f, -0.2f, 0.0f , 0.0f, 1.0f ,1.0f },
			{  0.5f, -0.2f, 0.0f , 1.0f, 0.0f ,1.0f },

			{ -0.5f,  0.2f, 0.0f , 0.0f, 1.0f ,0.0f } , // Triangle 1
			{  0.0f, -0.5f, 0.0f , 1.0f, 1.0f ,0.0f } ,
			{  0.5f,  0.2f, 0.0f , 1.0f, 0.0f ,1.0f }

		};
		unsigned int tringleIndx[][3] = {
			{ 0, 1, 2 },
			{ 3, 4, 5 }
		
		};
	}

	

	namespace Polygon{
		GLfloat polygon[][6] = {
			//{ -0.5f,  0.2f,  0.0f , 1.0f, 1.0f ,0.0f }, // Triangle 1
			//{ -0.7f,  0.0f,  0.0f , 0.0f, 1.0f ,1.0f },
			//{ -0.5f, 0.2f,  0.0f , 1.0f, 0.0f ,1.0f },
			//{  0.5f, -0.2f,  0.0f , 0.0f, 1.0f ,0.0f } , // Triangle 1
			//{  0.7f,  0.0f,  0.0f , 1.0f, 1.0f ,0.0f } ,
			//{  0.5f,  0.2f,  0.0f , 1.0f, 1.0f ,0.0f } ,

			{  0.0f,   0.0f, 0.0f , 1.0f, 1.0f ,1.0f }, // v0 center
			{ -0.5f,  -0.5f, 0.0f , 1.0f, 1.0f ,0.0f }, // Triangle 1
			{  0.0f,  -0.7f, 0.0f , 0.0f, 1.0f ,0.0f }, // Triangle 1
			{  0.5f,  -0.5f, 0.0f , 0.0f, 1.0f ,1.0f },
			{  0.7f,   0.0f, 0.0f , 1.0f, 1.0f ,0.0f },
			{  0.5f,   0.5f, 0.0f , 1.0f, 0.0f ,1.0f },
			{  0.0f,   0.7f, 0.0f , 1.0f, 0.0f ,1.0f },
			{  -0.5f,  0.5f, 0.0f , 1.0f, 0.0f ,1.0f },
			{  -0.7f,  0.0f, 0.0f , 1.0f, 0.0f ,1.0f },
			

		};
		unsigned int ploygonindx[][3] = {
			{ 0, 1, 2 },
			{ 0, 2, 3 },
			{ 0, 3, 4 },
			{ 0, 4, 5 },
			{ 0, 5, 6 },
			{ 0, 6, 7 },
			{ 0, 7, 8 },
			{ 0, 8, 1 }
			
		};

	}
}


//GLfloat vertices1[NumVertices][6] = {
//	{-0.5f, -0.5f, 0.0f , 1.0f, 1.0f ,0.0f }, // Triangle 1
//	{ 0.5f, -0.5f, 0.0f , 0.0f, 1.0f ,1.0f },
//	{ 0.0f,  0.5f, 0.0f , 1.0f, 0.0f ,1.0f },
//
//	{ -0.5f, 0.5f, 0.0f , 0.0f, 1.0f ,0.0f } , // Triangle 1
//	{ 0.0f, -0.5f, 0.0f , 1.0f, 1.0f ,0.0f } ,
//	{  0.5f,  0.5f, 0.0f ,  1.0f, 0.0f ,1.0f }
//
//};
//
//
//GLfloat vertices2[NumVertices][6] = {
//	{  0.0f, 0.5f, 0.0f , 1.0f, 1.0f ,0.0f }, // Triangle 1
//	{ -0.5f, -0.2f, 0.0f , 0.0f, 1.0f ,1.0f },
//	{  0.5f, -0.2f, 0.0f , 1.0f, 0.0f ,1.0f },
//
//	{ -0.5f, 0.2f, 0.0f , 0.0f, 1.0f ,0.0f } , // Triangle 1
//	{ 0.0f, -0.5f, 0.0f , 1.0f, 1.0f ,0.0f } ,
//	{  0.5f,  0.2f, 0.0f ,  1.0f, 0.0f ,1.0f }
//
//};
//
GLfloat vertices[] = {
	0.0f,  0.7f,   // top
   -0.7f,  0.2f,   // mid-left
   -0.5f, -0.5f,   // bottom-left
	0.5f, -0.5f,   // bottom-right
	0.7f,  0.2f    // mid-right
};
//
//GLfloat polygon[NumVertices][6] = {
//	{  0.0f, 0.7f, 0.0f , 1.0f, 1.0f ,0.0f }, // Triangle 1
//	{ -0.7f, 0.2f, 0.0f , 0.0f, 1.0f ,1.0f },
//	{ -0.5f, -0.5f, 0.0f , 1.0f, 0.0f ,1.0f },
//	{ 0.5f, -0.5f, 0.0f , 0.0f, 1.0f ,0.0f } , // Triangle 1
//	{ 0.7f, 0.2f, 0.0f , 1.0f, 1.0f ,0.0f } ,
//
//};
//
//
//unsigned int Ploygonindices[][3] = {
//	{ 0, 1, 2 },
//	{ 1, 2, 3 },
//	{ 2, 3, 4 },
//	{ 3, 4, 0 }
//};
//---------------------------------------------------------------------
//
// init
//
void init(void)
{
	glGenVertexArrays(NumVAOs, VAOs);
	glGenBuffers(NumBuffers, Buffers);
	glGenBuffers(NumIndx, IndxBuffers);
	//glBindVertexArray(VAOs[Triangles]);
	//
	//glGenBuffers(NumBuffers, Buffers);
	//glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2),vertices2, GL_STATIC_DRAW);

	//glGenBuffers(1, &EBO);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	////printf("Size of vertices : %d\n", sizeof(vertices));
	//ShaderInfo shaders[] = {
	//{ GL_VERTEX_SHADER, "triangles.vert" },
	//{ GL_FRAGMENT_SHADER, "triangles.frag" },
	//{ GL_NONE, NULL }
	//};
	//program = LoadShaders(shaders);
	//
	//glVertexAttribPointer(vPosition, 3, GL_FLOAT,
	//	GL_FALSE,6 * sizeof(GLfloat) , BUFFER_OFFSET(0));
	//glEnableVertexAttribArray(vPosition);

	//glVertexAttribPointer(vColor, 3, GL_FLOAT,
	//	GL_FALSE, 6* sizeof(float) , BUFFER_OFFSET(3 * sizeof(float) ));
	//glEnableVertexAttribArray(vColor);
	////glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);
	//glUseProgram(program);
}

void initTringle(void)
{
	//init(); // craeted the no of VAO and Buffers
	glBindVertexArray(VAOs[Triangles]);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[Tringlebuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Geometry::Tringles::tringle), Geometry::Tringles::tringle, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndxBuffers[TringleIndx]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Geometry::Tringles::tringleIndx), Geometry::Tringles::tringleIndx, GL_STATIC_DRAW);

	ShaderInfo shaders[] = {
	{ GL_VERTEX_SHADER, "./assets/shaders/triangles.vert" },
	{ GL_FRAGMENT_SHADER, "./assets/shaders/triangles.frag" },
	{ GL_NONE, NULL }
	};
	program = LoadShaders(shaders);

	glVertexAttribPointer(vPosition, 3, GL_FLOAT,
		GL_FALSE, 6 * sizeof(GLfloat), BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vColor, 3, GL_FLOAT,
		GL_FALSE, 6 * sizeof(float), BUFFER_OFFSET(3 * sizeof(float)));
	glEnableVertexAttribArray(vColor);
	glBindVertexArray(0);
}

void initPolygon(void)
{
	//init(); // glGenVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Polygons]);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[PolyGonbuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Geometry::Polygon::polygon), Geometry::Polygon::polygon, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndxBuffers[PolygonIndx]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Geometry::Polygon::ploygonindx), Geometry::Polygon::ploygonindx, GL_STATIC_DRAW);

	ShaderInfo shaders[] = {
	{ GL_VERTEX_SHADER, "./assets/shaders/triangles.vert" },
	{ GL_FRAGMENT_SHADER, "./assets/shaders/triangles.frag" },
	{ GL_NONE, NULL }
	};
	program = LoadShaders(shaders);
	glVertexAttribPointer(vPosition, 3, GL_FLOAT,
		GL_FALSE, 6 * sizeof(GLfloat), BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vColor, 3, GL_FLOAT,
		GL_FALSE, 6 * sizeof(float), BUFFER_OFFSET(3 * sizeof(float)));
	glEnableVertexAttribArray(vColor);
	glBindVertexArray(0);
}

//---------------------------------------------------------------------
//
// display
// FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
// FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
// FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
	//std::cout << "display successfully!" << std::endl;
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);  // teal background

	glUseProgram(program);

	//glBindVertexArray(VAOs[Triangles]);
	glBindVertexArray(VAOs[Polygons]);
	//glDrawArrays(GL_TRIANGLES, 0, NumVertices);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	float timeD = glutGet(GLUT_ELAPSED_TIME);
	float greenValue = (sin(timeD) / 2.0f) + 0.5f;
	int vertexColorLocation = glGetUniformLocation(program, "ourClr");
	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
	
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, NumVertices);

	glFlush();
	glutSwapBuffers();
	//printf("calling display\n");
}

void updateDisplay() 
{ 
	glutPostRedisplay(); 
}



int
main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_RGBA);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(700, 300);
	glutInitWindowSize(512, 512);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(argv[0]);
	std::cout << "OpenGL initialized successfully!" << std::endl;

	if (glewInit()) {
		cerr << "Unable to initialize GLEW ... exiting" << endl;
		exit(EXIT_FAILURE);
	}
	init();
	//initTringle();
	initPolygon();
	glutDisplayFunc(display);
	glutIdleFunc(updateDisplay);
	glutMainLoop();
}


//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//
//int main123() {
//	if (!glfwInit()) return -1;
//	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
//	glfwMakeContextCurrent(window);
//
//	if (glewInit() != GLEW_OK) {
//		std::cerr << "GLEW init failed\n";
//		return -1;
//	}
//
//	glViewport(0, 0, 800, 600);
//	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//	std::cout << "OpenGL initialized successfully!" << std::endl;
//
//	while (!glfwWindowShouldClose(window)) {
//		glClear(GL_COLOR_BUFFER_BIT);
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//	return 0;
//}