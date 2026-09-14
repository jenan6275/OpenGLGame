#pragma once
//#include <graphics/VAO.h>
//#include <graphics/VBO.h>
//#include <graphics/EBO.h>
//#include "core/LoadShaders.h"
//#include "core/game.h"

//#include <GL/glew.h>
//#include <glad/glad.h>

#include "graphics/VAO.h"
#include "graphics/VBO.h"
#include "graphics/EBO.h"

using namespace std;

//class VAO;
//class VBO;
//class EBO;


#include <graphics/Shader.h>
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

#include "ModelData.h"



class Game {

	unique_ptr<VAO> vao;
	unique_ptr<VBO> vbo;
	unique_ptr<EBO> ebo;
	unique_ptr<Shader> shader;


public:	
	Game();
	static void Init(int , char** );
	void Update();
	void updateDisplay();
	void Render();
	void Stop();
	//void Run();
	void Run(void(*)(), void(*)());
	~Game();
};