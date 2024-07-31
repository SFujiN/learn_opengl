#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stb/stb_image.h>

#include <shader/shader_m.h>
#include <camera/camera.h>

#include <iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);

// camera stuff
glm::vec3 cameraPos	= glm::vec3(0.0f, 0.0f, 3.0f);
Camera camera(cameraPos);

bool firstMouse = true;
// time stuff
float deltaTime = 0.0f;
float lastFrame = 0.0f;
// mouse stuff
float lastX = (float)SCR_WIDTH / 2, lastY = (float)SCR_HEIGHT / 2;

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Basic Lighting", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	Shader ourShader("../shaders/basic_lighting_ex3.vs", "../shaders/basic_lighting_ex3.fs");
  Shader lightCubeShader("../shaders/colors_scene.vs", "../shaders/light_cube.fs");

	float vertices[] = {
    		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	    	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
    		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 

    		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 
     		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 
     		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
     		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
    		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
    		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

	    	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

     		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

    		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
     		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

    		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
     		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	    	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	    	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
	};

	unsigned int VBO, VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(VAO);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) 0);
	glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) (3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  unsigned int lightVAO;
  glGenVertexArrays(1, &lightVAO);
  glBindVertexArray(lightVAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) 0);
  glEnableVertexAttribArray(0);

  glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

	glEnable(GL_DEPTH_TEST);

	while(!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		processInput(window);

		// activate shader
    ourShader.use();
    ourShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    ourShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);

		// create transformations
		// model matrix
		// view & projection matrix
		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		ourShader.setMat4("projection", projection);
		ourShader.setMat4("view", view);

		// render boxes
    glm::mat4 model = glm::mat4(1.0f);
    ourShader.setMat4("model", model);
    ourShader.setVec3("lightPos", lightPos);
    ourShader.setVec3("viewPos", camera.Position);
		glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    lightCubeShader.use();
    lightCubeShader.setMat4("projection", projection);
    lightCubeShader.setMat4("view", view);
    lightCubeShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
    model = glm::mat4(1.0f);
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.2f));
    lightCubeShader.setMat4("model", model);

    glBindVertexArray(lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// de-allocate resources
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    camera.ProcessKeyboard(RIGHT, deltaTime);
}

void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	GLint toggle[2];
	if(key == GLFW_KEY_V && action == GLFW_PRESS)
	{
		glGetIntegerv(GL_POLYGON_MODE, toggle);
		if(toggle[0] == GL_FILL)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		else
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
	}	
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if(firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}
	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reverse since y-coordinates range from bottom to top
	lastX = xpos;
	lastY = ypos;
  camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
  camera.ProcessMouseScroll(yoffset);
}
