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
	/**
	* @brief Allows user to create and manage models.
	*
	* @section Description
	*
	* The model class is used to create and manage models.
	* It allows the user to do the following:
	* - Create model with vertices, indexes, shaders, textures
	* - Change location, rotation, and scale of the model
	* - Move and rotate model
	*/
	class Model {
	private:
		// VARIABLES
		unsigned int m_VAO;									// ID of Vertex Array Object
		unsigned int m_IndexCount;							// Number of Indexes
		unsigned int m_VertexCount;							// Number of Vertices
		std::unique_ptr<VertexBuffer> m_VertexBuffer;		// Pointer to Vertex Buffer
		std::unique_ptr<IndexBuffer> m_IndexBuffer;			// Pointer to Index Buffer
		std::unique_ptr<ShaderProgram> m_ShaderProgram;		// Pointer to Shader Program
		std::unique_ptr<Texture> m_Texture;					// Pointer to Texture
		glm::mat4 m_Model;									// Model Matrix
		glm::vec3 m_Location;								// Location of Model
		glm::vec3 m_Rotation;								// Rotation of Model in Degrees (Euler Angles)
		glm::vec3 m_Scale;									// Scale of Model
		
		// METHODS
		void Update();										// Function to Update Model for Draw
	public:
		/**
		* @brief Constructor that initalizes a model with the given vertices, indexes, shaders, and texture.
		*
		* @param [in] vertices Pointer to array of vertices to be used by the model
		* @param [in] vertexCount Number of vertices in array pointed to by vertices parameter
		* @param [in] indexes Pointer to array of indexes to be used by the model
		* @param [in] indexCount Number of indexes in array pointed to by indexes parameter
		* @param [in] vertexPath Path to vertex shader to be used by the model
		* @param [in] fragmentPath Path to fragment shader to be used by the model
		* @param [in] texturePath Path to texture to be used by the model
		* 
		*/
		Model(Vertex* vertices, unsigned int vertexCount, unsigned int* indexes, unsigned int indexCount, const char* vertexPath, const char* fragmentPath, const char* texturePath);
		
		/**
		* @brief Destructor that destroys the model.
		*/
		~Model();

		// METHODS

		/**
		* @brief Draw function that draws the model.
		*/
		void Draw();

		/**
		* @brief Set colour function that lets you set the colour of the model (currently not functional)
		* 
		* @param r Red value of the colour to be set
		* @param g Green value of the colour to be set
		* @param b Blue value of the colour to be set
		* @param a Alpha value of the colour to be set
		*/
		void SetColour(float r, float g, float b, float a);

		/**
		* @brief Translate function moves the model by the specified translation vector.
		* 
		* @param translation Vector to translate the position of the model by
		*/
		void Translate(glm::vec3 translation);

		/**
		* @brief Rotation function rotates the model by the specified rotation amount.
		* 
		* @param rotation Vector to rotate the model by in degrees (Euler Angles)
		*/
		void Rotate(glm::vec3 rotation);

		// Setters

		/**
		* @brief Set location function sets the location of the model.
		*
		* @param location Location vector to set the model location to
		*/
		void SetLocation(glm::vec3 location) { m_Location = location; }

		/**
		* @brief Set rotation function sets the rotation of the model.
		*
		* @param rotation Rotation vector to set the model rotation to in degrees (Euler Angles)
		*/
		void SetRotation(glm::vec3 rotation) { m_Rotation = rotation; }
		
		/**
		* @brief Set scale function sets the scale of the model.
		*
		* @param scale Scale vector to set the model scale to
		*/
		void SetScale(glm::vec3 scale) { m_Scale = scale; }

		// Getters

		/**
		* @brief Get location function returns the location of the model
		* 
		* @return Returns the location of the model as a glm::vec3
		*/
		glm::vec3 GetLocation() { return m_Location; }

		/**
		* @brief Get rotation function returns the rotation of the model
		*
		* @return Returns the rotation of the model as a glm::vec3 in degrees (Euler Angles)
		*/
		glm::vec3 GetRotation() { return m_Rotation; }

		/**
		* @brief Get scale function returns the scale of the model
		*
		* @return Returns the scale of the model as a glm::vec3
		*/
		glm::vec3 GetScale() { return m_Scale; }

	};
}