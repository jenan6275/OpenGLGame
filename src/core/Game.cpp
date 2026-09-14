#pragma once

#include <iostream>
//#include "core/LoadShaders.h"
//#include "graphics/VAO.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "core/game.h"


//#include "core/vgl.h"



//using namespace std;
// Intialized the game and do the OpenGL setup


Game::Game()
{
	vao = make_unique<VAO>();
	//vbo = make_unique<VBO>((GLfloat*)Geometry::Tringles::tringle, sizeof(Geometry::Tringles::tringle));
	//ebo = make_unique<EBO>((GLuint*)Geometry::Tringles::tringleIndx, sizeof(Geometry::Tringles::tringleIndx));


	vbo = make_unique<VBO>((GLfloat*)Geometry::Cube::box, sizeof(Geometry::Cube::box));
	ebo = make_unique<EBO>((GLuint*)Geometry::Cube::cubeIndx, sizeof(Geometry::Cube::cubeIndx));

	vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	vao->LinkAttrib(*ebo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	shader = make_unique<Shader>("./assets/shaders/triangles.vert", "./assets/shaders/triangles.frag");

	
}

void Game::Init(int argc, char** argv){
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_RGBA);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(700, 300);
	glutInitWindowSize(512, 512);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(argv[0]);
	if (glewInit()) {
		cerr << "Unable to initialize GLEW ... exiting" << endl;
		exit(EXIT_FAILURE);
	}
	/*if(!gladLoadGLLoader((GLADloadproc)glutGetProcAddress)) {
		cerr << "Failed to initialize GLAD" << endl;
		exit(EXIT_FAILURE);
	}*/
}


//Update the game state
void Game::Update(){
	glClear(GL_COLOR_BUFFER_BIT);
	//std::cout << "display successfully!" << std::endl;
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);  // teal background

	//glUseProgram(program);
	shader->Activate();
	//glBindVertexArray(VAOs[Triangles]);
	//glBindVertexArray(VAOs[Polygons]);
	vao->Bind();
	//glDrawArrays(GL_TRIANGLES, 0, NumVertices);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	float timeD = glutGet(GLUT_ELAPSED_TIME);
	float greenValue = (sin(timeD) / 2.0f) + 0.5f;
	shader->setFloat("ourClr", greenValue);
	//int vertexColorLocation = glGetUniformLocation(program, "ourClr");
	//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, NumVertices);

	glFlush();
	glutSwapBuffers();

}

void Game::updateDisplay()
{
	glutPostRedisplay();
}


//Render the scene
void Game::Render(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(VAOs[Triangles]);
	//glDrawArrays(GL_TRIANGLES, 0, NumVertices);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//timeD = glutGet(GLUT_ELAPSED_TIME);
	//float greenValue = (sin(timeD) / 2.0f) + 0.5f;
	int vertexColorLocation = glGetUniformLocation(program, "ourClr");
	//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, NumVertices);

	glFlush();
	glutSwapBuffers();
	//printf("calling display\n");


}

//Stop the game and clean up resources
void Game::Stop(){

}

// Fake C API
extern "C" {

	//Update callback
	static void* g_ctx_update = nullptr;

	void register_update(void* ctx) {
		//g_cb = cb;
		g_ctx_update = ctx;
	}

	void trigger_update() {
		//if (g_cb) g_cb( g_ctx);
		Game* obj = static_cast<Game*>(g_ctx_update);
		obj->Update();
	}
	//--------------------------------------------------------------------------
	// UpdateDisplay callback
	static void* g_ctx_updateDisplay = nullptr;

	void register_updateDisplay(void* ctx) {
		//g_cb = cb;
		g_ctx_updateDisplay = ctx;
	}

	void trigger_updateDisplay() {
		//if (g_cb) g_cb( g_ctx);
		Game* obj = static_cast<Game*>(g_ctx_updateDisplay);
		obj->updateDisplay();
	}
}


void Game::Run( void(*f1)(), void(*f2)()){
	//Init();
	glutDisplayFunc(f1);
	glutIdleFunc(f2);
	glutMainLoop();
}

Game::~Game()
{
}


int main(int argc, char **argv) {

	Game::Init(argc, argv);
	Game game;
//	void (*f)();

	register_update(&game);
	register_updateDisplay(&game);

//	game.Init(argc, argv);
	game.Run(trigger_update, trigger_updateDisplay);
	return 0;
}	


