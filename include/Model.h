#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ShaderProgram.h"
#include "Vertex.h"
#include "Texture.h"
#include "gtc/type_ptr.hpp"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include <memory>

namespace Boreal {
	class Model {

	public:
		Model(Vertex* vertices, unsigned int vertexSize, unsigned int* indexes, unsigned int indexSize, const char* vertexPath, const char* fragmentPath, const char* texturePath);
		~Model();

		void Draw();
		void SetColour(float r, float g, float b, float a);

		void Translate(glm::vec3 translation);
		void Rotate(glm::vec3 rotation);

		// Setters
		void SetLocation(glm::vec3 location) { m_Location = location; }
		void SetRotation(glm::vec3 rotation) { m_Rotation = rotation; }
		void SetScale(glm::vec3 scale) { m_Scale = scale; }

		// Getters
		glm::vec3 GetLocation() { return m_Location; }
		glm::vec3 GetRotation() { return m_Rotation; }
		glm::vec3 GetScale() { return m_Scale; }

	private:
		void Update();
		unsigned int m_VAO;
		unsigned int m_IndexCount;
		unsigned int m_VertexCount;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		std::unique_ptr<ShaderProgram> m_ShaderProgram;
		std::unique_ptr<Texture> m_Texture;
		glm::mat4 m_Model;
		glm::vec3 m_Location;
		glm::vec3 m_Rotation;
		glm::vec3 m_Scale;
	};
}