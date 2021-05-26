#pragma once

#include <memory>
#include <string>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Boreal {
	/*
	* @file Window.h
	* @brief Allows user to create and manage windows.
	* @date 2021-05-25
	* 
	* @section DESCRIPTION
	* 
	* The window class is used to create and managed windows.
	* It allows the user to do the following:
	* - Create window with parameters
	* - Change window width & height
	* - Change window title
	* - Update window for main loop
	*/
	class Window {
	private:
		// VARIABLES
		int m_Width, m_Height;
		bool m_IsFullscreen;
		std::string m_Title;
		GLFWwindow* m_Window;
		GLFWmonitor* m_Monitor;

		// METHODS
		void FrameBufferCallback(GLFWwindow* window, int width, int height);
	public:
		/*
		* Constructor that initalizes a window with the given width, height, title, and a boolean for fullscreen.
		* 
		* @param width is the width of the window in pixels
		* @param height is the height of the window in pixels
		* @param title is the title of the window
		* @param isFullscreen is a boolean that determines if the window is initialized to fullscreen or not
		*/
		Window(int width, int height, std::string title, bool isFullscreen = false);

		/*
		* Destructor that destroys the window.
		*/
		~Window();

		/*
		* Update function to be used in main loop, swaps the buffers
		*/
		void Update() { glfwSwapBuffers(m_Window); }

		/*
		* Should close function returns true if window should be closing
		*/
		bool ShouldClose() { return glfwWindowShouldClose(m_Window); }

		/*
		* Close function to close the window
		*/
		void Close() { glfwSetWindowShouldClose(m_Window, true); }

		// GETTERS
		int GetWidth() { return m_Width; }
		int GetHeight() { return m_Height; }
		bool GetIsFullscreen() { return m_IsFullscreen; }
		std::string GetTitle() { return m_Title; }
		GLFWwindow* GetWindow() { return m_Window; }
		GLFWmonitor* GetMonitor() { return m_Monitor; }

		// SETTERS
		void SetWidth(int width) { m_Width = width; glfwSetWindowSize(m_Window, m_Width, m_Height); }
		void SetHeight(int height) { m_Height = height; glfwSetWindowSize(m_Window, m_Width, m_Height); }
		void SetIsFullscreen(bool isFullscreen);
		void SetTitle(std::string title) { m_Title = title; glfwSetWindowTitle(m_Window, m_Title.c_str()); }
	};
}

