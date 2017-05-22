#include "stdafx.h"
#include "cGameManager.h"
#include "cObjectManager.h"

#define FPS				60


void cGameManager::Init()
{
	m_frameTime = 1.0f / (float)FPS;
	m_currentTime = timeGetTime();
	m_prevTime = timeGetTime();
	OBJECT->Init();
	DEVICE->Init();
}

void cGameManager::Update()
{
	m_currentTime = timeGetTime();
	float deltaTime = (m_currentTime - m_prevTime) * 0.001f;	// 실제 한 프레임 시간

	if (deltaTime >= m_frameTime)
	{
		m_prevTime = m_currentTime;
		OBJECT->Update();
		cout << deltaTime << endl;
	}
	
}

void cGameManager::Render()
{
}

void cGameManager::Release()
{
}
