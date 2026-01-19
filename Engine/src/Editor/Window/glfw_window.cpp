#include "ARBpch.h"
#include "glfw_window.h"

#ifdef _GLFW_USE_

namespace ARB {
	glfw_Window::glfw_Window(unsigned int width, unsigned int height, char* name) : ARBWindow() {
		mainWindow = WindowProps<GLFWwindow>(width, height, name);

		if (glfwInit()) {
			ARB_INFO("GLFW Initiated");
		}
		else
			ARB_ERROR("GLFW could not be initiated");
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void glfw_Window::GenerateWindow() {

		mainWindow.m_handle = glfwCreateWindow(mainWindow.m_width, mainWindow.m_height, mainWindow.m_name, NULL, NULL);

		if (mainWindow.m_handle) {
			ARB_INFO("{} window has been created", mainWindow.m_name);
		}
		else {
			ARB_CRITICAL("{} window could not be created", mainWindow.m_name);
			return;
		}

		glfwMakeContextCurrent(mainWindow.m_handle);

		glfwSetInputMode(mainWindow.m_handle, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	void glfw_Window::ShowWindow() {
		if(mainWindow.m_handle)
		   glfwShowWindow(mainWindow.m_handle);
	}

	void glfw_Window::HideWindow() {
		if (mainWindow.m_handle)
		   glfwHideWindow(mainWindow.m_handle);
	}

	glfw_Window::~glfw_Window() {
		
	}

	void glfw_Window::processInput() {

	}

	int glfw_Window::windowShouldClose() {
		if (mainWindow.m_handle)
		    return glfwWindowShouldClose(mainWindow.m_handle);
		return 0;
	}

	void glfw_Window::onWindowClosed() {
		if (!mainWindow.m_handle)
			return;

		glfwDestroyWindow(mainWindow.m_handle);
		ARB_TRACE("{} window has been destroyed", mainWindow.m_name);
		glfwTerminate();
		ARB_TRACE("GLFW terminated");
	}

	void glfw_Window::closeWindow() {
		if (mainWindow.m_handle)
		    glfwSetWindowShouldClose(mainWindow.m_handle, true);
	}

	void glfw_Window::startUpdate() {

	}

	void glfw_Window::endUpdate() {
		glfwSwapBuffers(mainWindow.m_handle);
		glfwPollEvents();
	}

}

#endif