#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include "Shader.h"

class RenderManager
{
public:
	void SetUp(GLFWwindow* window);
	void RenderFrame(std::vector<GameObject> Objects);
	RenderManager();
	~RenderManager();
	
private:
	GLFWwindow* window;
};



