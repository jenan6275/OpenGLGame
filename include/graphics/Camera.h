#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "Shader.h"
#include <GLFW\glfw3.h>

class Camera
{
private:
	glm::mat4  _projection = glm::mat4(1.0f);
	glm::mat4  _view = glm::mat4(1.0f);

public:
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	bool firsClick = true;
	
	int width;
	int height;

	float yaw;
	float pitch;
	float FOVdeg;

	float speed = 0.01f;
	float sensitivity = 0.01f;

	Camera(int width, int height, glm::vec3 postition);
	void Matrix(float NearPlane, float FarPlane, Shader& shader, const char* uniform);

	void Input(GLFWwindow* window);
	void SetProjection(glm::mat4 proj);
	void SetView(glm::mat4 view);
};