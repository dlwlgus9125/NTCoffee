#pragma once

#define GAMEMAIN cGameManager::Instance()

class cGameManager : public Singleton<cGameManager>
{
private:
	float m_frameTime;
	float m_currentTime;
	float m_prevTime;
public:
	void Init();
	void Update();
	void Render();
	void Release();
};

