#pragma once
#include "Vertex.h"

namespace Boreal {
	class VertexBuffer {
	public:
		VertexBuffer(Vertex* vertices, unsigned int vertexCount);
		~VertexBuffer();
		void Bind();
		void UnBind();
	private:
		unsigned int m_VBO;
	};
}
