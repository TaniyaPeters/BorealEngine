#include "Window.h"

#include <iostream>

namespace Boreal {
	// Constructor
	Window::Window(int width, int height, std::string title, bool isFullscreen):
	m_Width(width),
	m_Height(height),
	m_Title(title),
	m_IsFullscreen(isFullscreen)
	{
		// Check if fullscreen
		if (isFullscreen) {
			m_Monitor = glfwGetPrimaryMonitor();
		}
		else {
			m_Monitor = NULL;
		}

		// Create window
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), m_Monitor, NULL);

		// If Window does not exist exit with error
		if (!m_Window) {
			std::cerr << "Window could not be created" << std::endl;
			glfwTerminate();
			exit(-1);
		}

		// Get Current Context - ie new window
		glfwMakeContextCurrent(m_Window);

		// Initialize GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD" << std::endl;
			exit(-1);
		}

		// Set up OpenGL viewport
		glViewport(0, 0, m_Width, m_Height);
	}

	// Destructor
	Window::~Window(){
		// Destroy Window
		glfwDestroyWindow(m_Window);
	}

	void Window::SetIsFullscreen(bool isFullscreen){
		if (isFullscreen) {
			m_Monitor = glfwGetPrimaryMonitor();
		}
		else {
			m_Monitor = NULL;
		}

		// Set monitor
		glfwSetWindowMonitor(m_Window, m_Monitor, 0, 0, m_Width, m_Height, NULL);
	}

	// Callback function for window resize
	void Window::FrameBufferCallback(GLFWwindow* window, int width, int height){
		// Set up OpenGL viewport
		glViewport(0, 0, width, height);
	}
}