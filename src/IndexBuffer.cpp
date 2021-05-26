#include "IndexBuffer.h"
#include "glad/glad.h"

namespace Boreal {
	IndexBuffer::IndexBuffer(unsigned int* indexes, unsigned int indexCount) {
		glGenBuffers(1, &m_EBO);
		Bind();

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indexes, GL_STATIC_DRAW);
		UnBind();
	}

	IndexBuffer::~IndexBuffer() {
		glDeleteBuffers(1, &m_EBO);
	}

	void IndexBuffer::Bind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	}

	void IndexBuffer::UnBind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}