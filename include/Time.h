#pragma once
class Time {

public:
	static Time* GetInstance();
	static float GetDeltaTime();
	void Update();
	void Destroy();

private:
	double m_CurrentTime, m_DeltaTime, m_PreviousTime;
	Time();
	~Time();

	// Camera Instance
	static Time* m_Instance;
};

