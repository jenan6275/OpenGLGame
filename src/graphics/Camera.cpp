#include "Camera.h"
#include <iostream>
using namespace  std;

Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;
	Camera::Position = position;
	//Camera::yaw = -90.0f;

	Camera::yaw = 0.0f;
	Camera::pitch = 0.0f;
	Camera::FOVdeg = 90.0f;
	Camera::Position = { 0,2000,0 };
}

void Camera::Matrix( float NearPlane, float FarPlane, Shader& shader, const char* uniform)
{
	const float radius = 3000.0f;
	
   /* float CamX = sin(glfwGetTime()) * radius;
   	float CamZ = cos(glfwGetTime()) * radius;
   	float CamY = 0.0f;*/
	
	float CamX =0;
	float CamY =0;
	float CamZ =0 ;

	CamX += Position.x;
	CamY += Position.y;
	CamZ += Position.z;

	//cout << "Postion: " << Position.x  <<" "<< Position.y <<" " <<  Position.z <<  endl;

	//_view = glm::lookAt(glm::vec3(CamX,CamY,CamZ) ,glm::vec3(0.0f, 0.0f, 0.0f), Up);
	//Orientation = { 0.0,0.0,-100.0f };

	_view = glm::lookAt(glm::vec3(CamX, CamY, CamZ), Position+ Orientation , Up);
	_projection = glm::perspective(glm::radians(FOVdeg), (float)(width / height), NearPlane, FarPlane);
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(_projection * _view));
}

void Camera::SetProjection(glm::mat4 proj)
{
	Camera::_projection = proj;
}
void Camera::SetView(glm::mat4 view)
{
	Camera::_view = view;
}

void Camera::Input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		Position += speed * Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		Position += speed * -glm::normalize(glm::cross(Orientation, Up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Position += speed * -Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		Position += speed * glm::normalize(glm::cross(Orientation, Up));
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		Position += speed * Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		Position += speed * -Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		speed = 3.4f;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_RELEASE)
	{
		speed = 2.1f;
	}
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (firsClick)
		{
			glfwSetCursorPos(window, height / 2, width / 2);
			firsClick = false;
		}
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		firsClick = true;
	}
	//Arrow keys for moving around left and right and UP and down

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		yaw += 90.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		yaw -= 90.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		pitch += 90.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		pitch -= 90.0f;
	}

}
