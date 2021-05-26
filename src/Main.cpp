#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Boreal.h"

namespace Boreal {
	int main() {
		// Initialize Boreal Engine
		Boreal::Initialize();

		// Create New Window
		Boreal::Window window(800, 600, "Hello!");

		std::cout << "Hello, Boreal Engine!" << std::endl;

		// Main loop
		while (!window.ShouldClose()) {
			glClearColor(0.3f, 0.29f, 0.69f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			window.Update();
			Boreal::Input::Update();
		}

		// Terminate Boreal Engine
		Boreal::Terminate();
		return 0;
	}
}