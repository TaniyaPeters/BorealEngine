#pragma once
#include <memory>
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#define CAMERA_ORTHOGRAPHIC 0
#define CAMERA_PERSPECTIVE	1

namespace Boreal {
	class Camera {

	public:
		static Camera* GetInstance();
		static void Destroy();

		void SetProjectionType(int projectionType) { m_ProjectionType = projectionType; Update(); }
		void SetFOV(float fov) { m_FOV = fov; Update(); }
		void SetHeight(int height) { m_Height = height; Update(); }
		void SetWidth(int width) { m_Width = width; Update(); }
		void SetZNear(float zNear) { m_ZNear = zNear; Update(); }
		void SetZFar(float zFar) { m_ZFar = zFar; Update(); }
		void SetScreenSize(int width, int height) { m_Height = height; m_Width = width; Update(); }
		void SetLocation(glm::vec3 location) { m_Location = location; Update(); }
		void SetRotation(glm::vec3 rotation) { m_Rotation = rotation; Update(); }

		int GetProjectionType() { return m_ProjectionType; }
		float GetFOV() { return m_FOV; }
		int GetHeight() { return m_Height; }
		int GetWidth() { return m_Width; }
		float GetZNear() { return m_ZNear; }
		float GetZFar() { return m_ZFar; }
		glm::vec3 GetLocation() { return m_Location; }
		glm::vec3 GetRotation() { return m_Rotation; }
		glm::vec3 GetRight() { return glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), m_Direction)); }

		static glm::mat4 GetProjection() { return GetInstance()->m_Projection; }
		static glm::mat4 GetView() { return GetInstance()->m_View; }

		void Translate(glm::vec3 translation);
		void Rotate(glm::vec3 rotation);
		void LookAt(glm::vec3 target);

	private:
		// Constructor and Destructor
		Camera();
		~Camera();

		// Camera Instance
		static Camera* m_Instance;

		// Private Functions
		void Update();
		void CheckRotation();

		// Member Variables
		glm::mat4 m_Projection, m_View;
		glm::vec3 m_Location, m_Rotation, m_Direction;
		int m_ProjectionType, m_Height, m_Width;
		float m_FOV, m_ZNear, m_ZFar;
	};
}