#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Boreal.h"

int main() {
	// Initialize Boreal Engine
	Boreal::Initialize();

	// Create New Window
	Boreal::Window window(800, 600, "Hello!");

	Boreal::Debug::SetLogFilter(BOREAL_DEBUG_DISABLE);
	Boreal::Debug::Log("Hello, Boreal Engine!");
	Boreal::Debug::LogWarning("Test warning!");
	Boreal::Debug::LogError("Test error!");

	// Main loop
	while (!window.ShouldClose()) {
		glClearColor(0.3f, 0.29f, 0.69f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		window.Update();
		Boreal::Input::Update();
	}

	// Terminate Boreal Engine
	Boreal::Debug::PrintLogCount();
	Boreal::Debug::PrintLogs();
	Boreal::Debug::PrintWarningCount();
	Boreal::Debug::PrintWarnings();
	Boreal::Debug::PrintErrorCount();
	Boreal::Debug::PrintErrors();
	Boreal::Terminate();
	return 0;
}