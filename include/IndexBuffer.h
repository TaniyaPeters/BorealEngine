#pragma once

namespace Boreal {
	class IndexBuffer {
	public:
		IndexBuffer(unsigned int* indexes, unsigned int indexCount);
		~IndexBuffer();
		void Bind();
		void UnBind();
	private:
		unsigned int m_EBO;
	};
}