#pragma once
#include <GL/glew.h>

namespace Geometry {
	namespace Tringles {
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
	namespace Polygon {
		GLfloat polygon[][6] = {

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
		unsigned int ploygonIndx[][3] = {
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
	namespace Cube {
		GLfloat box[][6] = {
			{-0.5f, -0.5f, -0.5f, 1.0f, 1.0f ,1.0f }, // 0
			{ 0.5f, -0.5f, -0.5f, 1.0f, 1.0f ,0.0f }, // 1
			{ 0.5f,  0.5f, -0.5f, 0.0f, 1.0f ,0.0f },// 2
			{-0.5f,  0.5f, -0.5f, 0.0f, 1.0f ,1.0f }, // 3
			{-0.5f, -0.5f,  0.5f, 1.0f, 1.0f ,0.0f }, // 4
			{ 0.5f, -0.5f,  0.5f, 1.0f, 0.0f ,1.0f }, // 5
			{ 0.5f,  0.5f,  0.5f, 1.0f, 0.0f ,1.0f }, // 6
			{-0.5f,  0.5f,  0.5f, 1.0f, 0.0f ,1.0f } // 7

		};
		GLuint cubeIndx[][3] = {
		
			{ 0, 1, 2, },
			{ 2, 3, 0, }, // Back face
			{ 4, 5, 6, },
			{ 6, 7, 4, },  // Front face
			{ 0, 4, 7, }, 
			{ 7, 3, 0, },   // Left face
			{ 1, 5, 6  }, 
			{ 6, 2, 1, },  // Right face
			{ 0, 1, 5, }, 
			{ 5, 4, 0, },  // Bottom face
			{ 3, 2, 6, }, 
			{ 6, 7, 3  }   // Top face
		};
	}
}
