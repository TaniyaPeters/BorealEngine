#pragma once
#include "Vertex.h"

namespace Boreal {
	/**
	* @brief Allows user to create and manage vertex buffers
	*
	* @section Description
	*
	* The vertex buffer class allows the user to create, bind, and unbind vertex buffers. This is used to create models along with the index buffer.
	*
	*/
	class VertexBuffer {
	public:
		/**
		* @brief Constructor that initializes the vertex buffer with a pointer to an array of vertices and the count of vertices in the array
		* 
		* @param [in] vertices A pointer to an array of vertices
		* @param [in] vertexCount The number of vertices in the array pointed to by the vertices parameter
		*
		*/
		VertexBuffer(Vertex* vertices, unsigned int vertexCount);

		/**
		* @brief Destructor that deletes the vertex buffer.
		*/
		~VertexBuffer();

		/**
		* @brief Bind function binds the vertex buffer to the current context
		*
		*/
		void Bind();

		/**
		* @brief UnBind function unbinds the vertex buffer from the current context
		*
		*/
		void UnBind();
	private:
		unsigned int m_VBO;
	};
}
