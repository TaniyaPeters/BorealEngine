#include "ShaderProgram.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

namespace Boreal {
	ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath) {
		// String buffer for shaders
		std::stringstream buffer;

		std::ifstream vertexSource;
		vertexSource.open(vertexPath);
		if (!vertexSource) {
			std::cerr << "NO VERTEX FILE " << vertexPath << std::endl;
		}
		buffer << vertexSource.rdbuf();
		std::string vertexString = buffer.str();
		const char* vertexCString = vertexString.c_str();

		// Assign the vertex shader
		unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vShader, 1, &vertexCString, NULL);
		glCompileShader(vShader);
		CheckErrors(1, vShader);
		buffer.str(std::string());

		std::ifstream fragmentSource;
		fragmentSource.open(fragmentPath);
		if (!fragmentSource) {
			std::cerr << "NO FRAGMENT FILE " << fragmentPath << std::endl;
		}
		buffer << fragmentSource.rdbuf();
		std::string fragmentString = buffer.str();
		const char* fragmentCString = fragmentString.c_str(); \

			// Assign the fragment Shader
			unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fShader, 1, &fragmentCString, NULL);
		glCompileShader(fShader);
		CheckErrors(1, fShader);
		buffer.str(std::string());

		// Link the Shaders
		m_ShaderProgram = glCreateProgram();
		glAttachShader(m_ShaderProgram, vShader);
		glAttachShader(m_ShaderProgram, fShader);
		glLinkProgram(m_ShaderProgram);
		CheckErrors(2, m_ShaderProgram);

		// Use the Program and Free up Space
		vertexSource.close();
		fragmentSource.close();
		glDeleteShader(vShader);
		glDeleteShader(fShader);
	}

	ShaderProgram::~ShaderProgram() {
		glDeleteProgram(m_ShaderProgram);
	}

	void ShaderProgram::Bind() {
		glUseProgram(m_ShaderProgram);							// Choose Shader Program
	}

	void ShaderProgram::UnBind() {
		glUseProgram(0);
	}

	void ShaderProgram::CheckErrors(int a, unsigned int shader) {
		int success = 1;
		char infolog[512];
		if (a == 1) {

			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		}
		else if (a == 2) {
			glGetProgramiv(shader, GL_COMPILE_STATUS, &success);
		}
		if (!success) {
			if (a == 1) {
				glGetShaderInfoLog(shader, 512, NULL, infolog);
			}
			else if (a == 2) {
				glGetProgramInfoLog(shader, 512, NULL, infolog);
			}

			std::cerr << infolog << std::endl;
			glfwTerminate();
			exit(-1);
		}
	}
}