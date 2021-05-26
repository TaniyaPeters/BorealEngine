#include "VertexBuffer.h"
#include "glad/glad.h"

namespace Boreal {
	VertexBuffer::VertexBuffer(Vertex* vertices, unsigned int vertexCount) {
		// Create the vertex Buffer
		glGenBuffers(1, &m_VBO);					// Generate the Buffer
		Bind();
		// Send the Data
		glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(Vertex), vertices, GL_STATIC_DRAW);
		UnBind();
	}

	VertexBuffer::~VertexBuffer() {
		glDeleteBuffers(1, &m_VBO);
	}

	void VertexBuffer::Bind() {
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);		// Bind buffer for vertices to Context
	}

	void VertexBuffer::UnBind() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}