#pragma once
namespace Boreal {
	class ShaderProgram {

	public:
		ShaderProgram(const char* vertexPath, const char* fragmentPath);
		~ShaderProgram();
		void Bind();
		void UnBind();
		unsigned int GetShaderProgram() { return m_ShaderProgram; }
	private:
		unsigned int m_ShaderProgram;
		void CheckErrors(int a, unsigned int shader);
	};
}