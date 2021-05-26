#pragma once

#include "GLFW/glfw3.h"

#define BOREAL_KEY_0 GLFW_KEY_0
// Add rest of the keys

namespace Boreal {
	/*
	* @file Input.h
	* @brief Allows user to handle user input.
	* @date 2021-05-25
	*
	* @section DESCRIPTION
	*
	* The input class allows the user input to be read
	* The class consists of static functions only so no instantiation is required
	* 
	*/
	class Input {
	public:
		static void Update() { glfwPollEvents(); }
	};
}