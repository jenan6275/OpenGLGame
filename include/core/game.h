#pragma once
//#include <graphics/VAO.h>
//#include <graphics/VBO.h>
//#include <graphics/EBO.h>
//#include "core/LoadShaders.h"
//#include "core/game.h"

//#include <GL/glew.h>

//#include <glad/glad.h>



#include <graphics/VAO.h>
#include <graphics/VBO.h>
#include <graphics/EBO.h>
#include <core/Texture.h>
#include <graphics/Shader.h>
#include <core/ModelData.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

//class VAO;
//class VBO;
//class EBO;



#include <memory>
// This class connatinet all the funmcil;aity to set up the openGL for rendering

enum VAO_IDs { Triangles, Polygons, NumVAOs };
enum Buffer_IDs { Tringlebuffer, PolyGonbuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0, vColor = 1 };
GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];
const GLuint NumVertices = 6;
const GLuint NumTringles = 2;
enum Indx_IDs { TringleIndx, PolygonIndx, NumIndx };
GLuint IndxBuffers[NumIndx];
//int timeD;
GLuint program;

#define SCR_WIDTH 1200
#define SCR_HEIGHT 800


void keyDown(unsigned char key, int x, int y);
void keyUp(unsigned char key, int x, int y);
void processInput(unsigned char key);




class Game {

	unique_ptr<VAO> vao;
	unique_ptr<VBO> vbo;
	unique_ptr<EBO> ebo;
	unique_ptr<Shader> shader;
	unique_ptr<Texture_Cls> tex0;
	unique_ptr<Texture_Cls> tex1;
	//GLFWwindow* window;

	unique_ptr<glm::mat4> model;
	unique_ptr<glm::mat4> view;
	unique_ptr<glm::mat4> project;
	

public:	
	Game();
	static void Init(int , char** );
	void Update();
	void Model();
	void View();
	void Project();
	void updateDisplay();
	void Render();
	void Stop();
	//void Run();
	void Run(void(*)(), void(*)());
	~Game();
};