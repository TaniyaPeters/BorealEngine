#include "Camera.h"
#include <gtx/euler_angles.hpp>
#include <cmath>
namespace Boreal {
	// Create an Null Pointer
	Camera* Camera::m_Instance = nullptr;

	// Constuctor and Destructor
	Camera::Camera() {
		m_ProjectionType = CAMERA_PERSPECTIVE;
		m_FOV = 60.0f;
		m_ZNear = 0.1f;
		m_ZFar = 100.0f;
		m_Height = 1;
		m_Width = 1;
		m_View = glm::mat4(0.0f);
		m_Projection = glm::mat4(0.0f);
		m_Direction = glm::vec3(0.0f, 0.0f, 1.0f);
		m_Location = glm::vec3(0.0f);
		m_Rotation = glm::vec3(0.0f);
	}

	Camera::~Camera() {}


	// Public Functions
	Camera* Camera::GetInstance() {
		if (!m_Instance) {
			m_Instance = new Camera();
		}

		return m_Instance;
	}

	void Camera::Destroy() {

		delete m_Instance;
		m_Instance = nullptr;

	}

	void Camera::Translate(glm::vec3 translation) {
		m_Location += translation;
		Update();
	}

	void Camera::Rotate(glm::vec3 rotation) {
		m_Rotation += rotation;
		Update();
	}

	void Camera::LookAt(glm::vec3 target) {
		float x, y, z;
		m_View = glm::lookAt(m_Location, target, glm::vec3(0.0f, 1.0f, 0.0f));
		glm::extractEulerAngleXYZ(m_View, x, y, z);
		m_Rotation.x = glm::degrees(x) + 180.0f;
		m_Rotation.y = glm::degrees(y);
		m_Rotation.z = glm::degrees(z) + 180.0f;
		Update();
	}

	void Camera::CheckRotation() {
		if (m_Rotation.x >= 180.0f) {
			m_Rotation.x -= 360.0f;
		}
		else if (m_Rotation.x <= -180.0f) {
			m_Rotation.x += 360.0f;
		}

		if (m_Rotation.y >= 180.0f) {
			m_Rotation.y -= 360.0f;
		}
		else if (m_Rotation.y <= -180.0f) {
			m_Rotation.y += 360.0f;
		}

		if (m_Rotation.z >= 180.0f) {
			m_Rotation.z -= 360.0f;
		}
		else if (m_Rotation.z <= -180.0f) {
			m_Rotation.z += 360.0f;
		}
	}

	// Private Functions
	void Camera::Update() {

		// Update projection
		if (m_ProjectionType == CAMERA_ORTHOGRAPHIC) {
			m_Projection = glm::ortho(0.0f, (float)m_Width, (float)m_Height, 0.0f, m_ZNear, m_ZFar);
		}
		else if (m_ProjectionType == CAMERA_PERSPECTIVE) {
			m_Projection = glm::perspective(glm::radians(m_FOV), (float)m_Width / (float)m_Height, m_ZNear, m_ZFar);
		}

		CheckRotation();

		m_Direction.x = sin(glm::radians(m_Rotation.y)) * cos(glm::radians(m_Rotation.x));
		m_Direction.y = -sin(glm::radians(m_Rotation.x));
		m_Direction.z = cos(glm::radians(m_Rotation.y)) * cos(glm::radians(m_Rotation.x));

		m_Direction = glm::normalize(m_Direction);

		// Update View
		m_View = glm::lookAt(m_Location, m_Location + m_Direction, glm::vec3(0.0f, 1.0f, 0.0f));
	}
}