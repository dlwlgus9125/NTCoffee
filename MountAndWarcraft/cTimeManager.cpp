#include "stdafx.h"
#include "cTimeManager.h"


void cTimeManager::Init(int fps)
{
	// �ʴ� ���ļ� ���
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_frequency);

	// ���ļ��� �ð� ���
	m_frequencyTime = 1.0 / m_frequency;

	// ���� ī��Ʈ ���
	QueryPerformanceCounter((LARGE_INTEGER*)&m_startCount);
	m_currentCount = m_startCount;
	m_previousCount = m_startCount;

	// �����Ӵ� �ð� ���
	m_fps = fps;
	m_frameTime = 1.0 / fps;
}

int cTimeManager::FPS() { return m_fps; }
float cTimeManager::StartTime() { return m_startCount * m_frequencyTime; }
float cTimeManager::CurrentTime() { return m_currentCount * m_frequencyTime; }
float cTimeManager::DeltaTime() { return m_deltaTime; }

bool cTimeManager::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&m_currentCount);

	m_deltaTime = (m_currentCount - m_previousCount) * m_frequencyTime;

	if (m_deltaTime > m_frameTime)
	{
		m_previousCount = m_currentCount;
		return true;
	}
	return false;
}