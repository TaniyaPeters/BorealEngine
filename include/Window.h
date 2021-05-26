#pragma once

#include <memory>
#include <string>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Boreal {
	/**
	* @brief Allows user to create and manage windows.
	* @date 2021-05-25
	* 
	* @section DESCRIPTION
	* 
	* The window class is used to create and manage windows.
	* It allows the user to do the following:
	* - Create window with parameters
	* - Change window width & height
	* - Change window title
	* - Update window for main loop
	*/
	class Window {
	private:
		// VARIABLES
		/**
		* @brief Width of the window in pixels
		*/
		int m_Width; 
		int m_Height;
		bool m_IsFullscreen;
		std::string m_Title;
		GLFWwindow* m_Window;
		GLFWmonitor* m_Monitor;

		// METHODS
		void FrameBufferCallback(GLFWwindow* window, int width, int height);
	public:
		/**
		* @brief Constructor that initalizes a window with the given width, height, title, and a boolean for fullscreen.
		* 
		* @param [in] width is the width of the window in pixels
		* @param [in] height is the height of the window in pixels
		* @param [in] title is the title of the window
		* @param [in] isFullscreen is a boolean that determines if the window is initialized to fullscreen or not
		*/
		Window(int width, int height, std::string title, bool isFullscreen = false);

		/**
		* @brief Destructor that destroys the window.
		*/
		~Window();

		/**
		* @brief Update function to be used in main loop, swaps the buffers
		*/
		void Update() { glfwSwapBuffers(m_Window); }

		/**
		* @brief Should close function returns true if window should be closing
		* 
		* @return Returns true if window should close, false if window should not close
		*/
		bool ShouldClose() { return glfwWindowShouldClose(m_Window); }

		/**
		* @brief Close function to close the window
		*/
		void Close() { glfwSetWindowShouldClose(m_Window, true); }

		// GETTERS

		/**
		* @brief Getter for the width of the window
		*
		* @return Returns the width of the window as an integer
		*/
		int GetWidth() { return m_Width; }

		/**
		* @brief Getter for the height of the window
		*
		* @return Returns the height of the window as an integer
		*/
		int GetHeight() { return m_Height; }
		
		/**
		* @brief Getter for the is fullscreen flag
		*
		* @return Returns the fullscreen flag as a boolean
		*/
		bool GetIsFullscreen() { return m_IsFullscreen; }
		
		/**
		* @brief Getter for the title of the window
		*
		* @return Returns the title of the window as an std::string
		*/
		std::string GetTitle() { return m_Title; }
		
		/**
		* @brief Getter for the GLFW window struct
		*
		* @return Returns a pointer to the GLFW window struct
		*/
		GLFWwindow* GetWindow() { return m_Window; }
		
		/**
		* @brief Getter for the GLFW monitor struct
		*
		* @return Returns a pointer to the GLFW monitor struct
		*/
		GLFWmonitor* GetMonitor() { return m_Monitor; }

		// SETTERS

		/**
		* @brief Setter for the width of the window
		*
		* @param [in] width is the width of the window in pixels
		*/
		void SetWidth(int width) { m_Width = width; glfwSetWindowSize(m_Window, m_Width, m_Height); }

		/**
		* @brief Setter for the height of the window
		*
		* @param [in] height is the height of the window in pixels
		*/
		void SetHeight(int height) { m_Height = height; glfwSetWindowSize(m_Window, m_Width, m_Height); }

		/**
		* @brief Setter for the is fullscreen flag
		*
		* @param [in] isFullscreen is the value of the fullscreen flag as a boolean
		*/
		void SetIsFullscreen(bool isFullscreen);

		/**
		* @brief Setter for the title of the window
		*
		* @param [in] title is the title of the window as an std::string
		*/
		void SetTitle(std::string title) { m_Title = title; glfwSetWindowTitle(m_Window, m_Title.c_str()); }
	};
}

