#include "Model.h"
#include "glad/glad.h"
#include "Camera.h"

namespace Boreal {
	// Constructor 
	Model::Model(Vertex* vertices, unsigned int vertexCount, unsigned int* indexes, unsigned int indexCount, const char* vertexPath, const char* fragmentPath, const char* texturePath) :
		m_VertexCount(vertexCount), m_IndexCount(indexCount)
	{
		// Create the Vertex Array Object
		glGenVertexArrays(1, &m_VAO);
		glBindVertexArray(m_VAO);

		// Create the Vertex Buffer
		m_VertexBuffer = std::make_unique<VertexBuffer>(vertices, m_VertexCount);
		m_VertexBuffer->Bind();

		// Create the Index Buffer
		m_IndexBuffer = std::make_unique<IndexBuffer>(indexes, m_IndexCount);
		m_IndexBuffer->Bind();

		// Create and Enable Vertex Attributes
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, x));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, r));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, u));
		glEnableVertexAttribArray(2);

		glBindVertexArray(0);

		// Create the Shader Program
		m_ShaderProgram = std::make_unique<ShaderProgram>(vertexPath, fragmentPath);

		m_Texture = std::make_unique<Texture>(texturePath);

		// Initialize Loc, Rot, and Scale
		m_Location = glm::vec3(0.0f);
		m_Rotation = glm::vec3(0.0f);
		m_Scale = glm::vec3(1.0f);
	}

	// Destructor
	Model::~Model() {
		glDeleteVertexArrays(1, &m_VAO);
	}

	// Public Functions
	void Model::Draw() {
		Update();
		m_ShaderProgram->Bind();											// Choose Shader Program
		m_Texture->Bind();
		glBindVertexArray(m_VAO);											// Chose Vertex Array Object
		glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, 0);		// Draw the Traingle0
		m_ShaderProgram->UnBind();
		m_Texture->UnBind();
		glBindVertexArray(0);
	}

	void Model::SetColour(float r, float g, float b, float a) {
		int colourLocation = glGetUniformLocation(m_ShaderProgram->GetShaderProgram(), "ourColour");
		m_ShaderProgram->Bind();
		glUniform4f(colourLocation, r, g, b, a);
		m_ShaderProgram->UnBind();
	}

	void Model::Translate(glm::vec3 translation) {
		m_Location += translation;
	}

	void Model::Rotate(glm::vec3 rotation) {
		m_Rotation += rotation;
	}

	// Private Functions
	void Model::Update() {
		// Update Model Matrix
		m_Model = glm::mat4(1.0f);
		m_Model = glm::translate(m_Model, m_Location);
		m_Model = glm::rotate(m_Model, glm::radians(m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		m_Model = glm::rotate(m_Model, glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		m_Model = glm::rotate(m_Model, glm::radians(m_Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		m_Model = glm::scale(m_Model, m_Scale);

		// Get MVP Uniform Locations
		int modelLocation = glGetUniformLocation(m_ShaderProgram->GetShaderProgram(), "model");
		int viewLocation = glGetUniformLocation(m_ShaderProgram->GetShaderProgram(), "view");
		int projectionLocation = glGetUniformLocation(m_ShaderProgram->GetShaderProgram(), "projection");

		// Transmit MVP Matrices to Shader Program
		m_ShaderProgram->Bind();
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(m_Model));
		glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(Camera::GetView()));
		glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(Camera::GetProjection()));
		m_ShaderProgram->UnBind();
	}
}