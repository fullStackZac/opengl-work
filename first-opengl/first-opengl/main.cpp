#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//tell glfw core profile is being used
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//create glfw window object 800X800 with firstopenglwindow in title bar
	GLFWwindow* window = glfwCreateWindow(800, 800, "firstOpenGLWindow", NULL, NULL);
	//error check in case window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//introduce window into current context
	glfwMakeContextCurrent(window);

	//load glad so it configures openGL
	gladLoadGL();

	//specifying viewport of openGL in the window (in this case the whole thing)
	glViewport(0, 0, 800, 800);

	//specifying the color of the window background (this is navy(ish) blue
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	//main wihile loop
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}


	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
