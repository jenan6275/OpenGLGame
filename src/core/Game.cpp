

#include <iostream>
//#include "core/LoadShaders.h"
//#include "graphics/VAO.h"
//#include <GL/glew.h>
//#include <glad/glad.h>
#include <glad/glad.h>
//#include <GLFW/glfw3.h>
#include <GL/freeglut.h>  // or keep <GL/freeglut.h> if using freeglut
#include <core/game.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



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

	vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	vao->LinkAttrib(*vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	vao->LinkAttrib(*vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	vao->LinkAttrib(*ebo, 3, 3, GL_FLOAT, 3 * sizeof(float), (void*)(0 * sizeof(float)));

	shader = make_unique<Shader>("./assets/shaders/triangles.vert", "./assets/shaders/triangles.frag");

	tex0 = make_unique<Texture_Cls>("./assets/images/container.jpg", GL_TEXTURE0);
	tex1 = make_unique<Texture_Cls>("./assets/images/awesomeface.png", GL_TEXTURE1);

	model = make_unique<glm::mat4>(1.0f);
	view = make_unique<glm::mat4>(1.0f);
	project = make_unique<glm::mat4>(1.0f);
	


	
}

void Game::Init(int argc, char** argv){

	/*glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window =
		glfwCreateWindow(800, 600, "Test", nullptr, nullptr);

	if (!window)
	{
		std::cout << "Window creation failed\n";
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD initialization failed\n";
		exit(EXIT_FAILURE);
	}

	std::cout << "OpenGL Version: "
		<< glGetString(GL_VERSION)
		<< std::endl;*/


	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_RGBA);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(700, 300);
	glutInitWindowSize(800, 600);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(argv[0]);
	/*if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cerr << "Unable to initialize GLAD ... exiting" << endl;
		exit(EXIT_FAILURE);
	}*/
	/*if (glewInit()) {
		cerr << "Unable to initialize GLEW ... exiting" << endl;
		exit(EXIT_FAILURE);
	}*/
	/*if(!gladLoadGLLoader((GLADloadproc)glutGetProcAddress)) {
		cerr << "Failed to initialize GLAD" << endl;
		exit(EXIT_FAILURE);
	}*/



	// Initialize GLAD
	if (!gladLoadGL())
	{
		std::cerr << "Failed to initialize GLAD\n";
		exit(EXIT_FAILURE);
	}

}

void Game::Model() {
	static float rot = 0.0f;
	*model = glm::mat4(1.0f);
	*model = glm::rotate(*model, glm::radians(rot++), glm::vec3(0.0f, 1.0f, 1.0f));
	shader->setMat4("uModel", *model);
	Sleep(100);

}
void Game::View() {

	*view = glm::mat4(1.0f);
	*view = glm::translate(*view, glm::vec3(0.0f, 0.0f, -4.0f));
	shader->setMat4("uView", *view);

}

void Game::Project() {

	*project = glm::mat4(1.0f);
	*project = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	shader->setMat4("uProject", *project);

}


//Update the game state
void Game::Update(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//std::cout << "display successfully!" << std::endl;
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);  // teal background

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);      // Remove back faces
	glFrontFace(GL_CCW);      // Counter-clockwise = front face

	//glUseProgram(program);
	shader->Activate();
	//glBindVertexArray(VAOs[Triangles]);
	//glBindVertexArray(VAOs[Polygons]);
	vao->Bind();
	//glDrawArrays(GL_TRIANGLES, 0, NumVertices);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	shader->setInt("tex0", 0);
	shader->setInt("tex1", 1);


	//activate the texture
	tex0->Bind();
	tex1->Bind();

	//Set the projection
	Model();
	View();
	Project();

	//float timeD = glutGet(GLUT_ELAPSED_TIME);
	//float greenValue = (sin(timeD) / 2.0f) + 0.5f;
	//shader->setFloat("ourClr", greenValue);
	//int vertexColorLocation = glGetUniformLocation(program, "ourClr");
	//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
	glDrawElements(GL_TRIANGLES,36, GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, NumVertices);

	glFlush();
	//glfwSwapBuffers(window);
	//glfwPollEvents();
	glutSwapBuffers();

}

void Game::updateDisplay()
{
	//glfwPollEvents();
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


//#include <iostream>
//
//#include <glad/glad.h>
//#include <GL/freeglut.h>
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glutSwapBuffers();
//}
//
//int main123(int argc, char** argv)
//{
//	// Initialize FreeGLUT
//	glutInit(&argc, argv);
//
//	// Request OpenGL 3.3 Core Profile
//	glutInitContextVersion(3, 3);
//	glutInitContextProfile(GLUT_CORE_PROFILE);
//
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowSize(800, 600);
//
//	glutCreateWindow("FreeGLUT + GLAD");
//
//	// Initialize GLAD
//	if (!gladLoadGL())
//	{
//		std::cerr << "Failed to initialize GLAD\n";
//		return -1;
//	}
//
//	std::cout << "OpenGL Version: "
//		<< glGetString(GL_VERSION)
//		<< std::endl;
//
//	// Set clear color
//	glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
//
//	glutDisplayFunc(display);
//
//	glutMainLoop();
//
//	return 0;
//}
//


