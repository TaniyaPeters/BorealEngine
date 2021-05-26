#include "Time.h"
#include "GLFW/glfw3.h"

// Create an Null Pointer
Time* Time::m_Instance = nullptr;

Time::Time() {
	m_CurrentTime = 0.0;
	m_DeltaTime = 0.0;
	m_PreviousTime = 0.0;
}

Time::~Time() {}

Time* Time::GetInstance() {
	if (!m_Instance) {
		m_Instance = new Time();
	}

	return m_Instance;
}

float Time::GetDeltaTime() {
	return (float)GetInstance()->m_DeltaTime;
}

void Time::Update() {
	GetInstance()->m_PreviousTime = GetInstance()->m_CurrentTime;
	GetInstance()->m_CurrentTime = glfwGetTime();
	GetInstance()->m_DeltaTime = GetInstance()->m_CurrentTime - GetInstance()->m_PreviousTime;
}

void Time::Destroy() {

	delete m_Instance;
	m_Instance = nullptr;

}
