#pragma once

namespace Boreal {
	/**
	* @brief Allows user to create and manage index buffers
	*
	* @section Description
	*
	* The index buffer class allows the user to create, bind, and unbind index buffers. This is used to create models along with the vertex buffer.
	*
	*/
	class IndexBuffer {
	public:
		/**
		* @brief Constructor that initializes the index buffer with a pointer to an array of indexes and the count of indexes in the array
		*
		* @param [in] indexes A pointer to an array of indexes
		* @param [in] indexCount The number of indexes in the array pointed to by the indexes parameter
		*
		*/
		IndexBuffer(unsigned int* indexes, unsigned int indexCount);

		/**
		* @brief Destructor that deletes the index buffer.
		*/
		~IndexBuffer();

		/**
		* @brief Bind function binds the index buffer to the current context
		*
		*/
		void Bind();

		/**
		* @brief UnBind function unbinds the index buffer from the current context
		*
		*/
		void UnBind();
	private:
		unsigned int m_EBO;		// ID of Element Buffer Object
	};
}