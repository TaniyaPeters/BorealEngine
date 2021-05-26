#pragma once

// Main Includes
#include "glad/glad.h"
#include "GLFW/glfw3.h"

// Boreal Engine Includes
#include "Input.h"
#include "Window.h"

#define BOREAL_OPENGL_VERSION_MAJOR 4
#define BOREAL_OPENGL_VERSION_MINOR 6
#define BOREAL_OPENGL_PROFILE GLFW_OPENGL_CORE_PROFILE

namespace Boreal {
	void Initialize() {
		// Initialize GLFW
		glfwInit();

		// Window Hints - Verson: 4.6 - Profile: Core Profile
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, BOREAL_OPENGL_VERSION_MAJOR);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, BOREAL_OPENGL_VERSION_MINOR);
		glfwWindowHint(GLFW_OPENGL_PROFILE, BOREAL_OPENGL_PROFILE);
	}

	void Terminate() {
		// Terminate GLFW
		glfwTerminate();
	}
}
