#pragma once
class cObject;

#define OBJECT  cObjectManager::Instance()



class cObjectManager : public Singleton<cObjectManager>
{
	vector<cObject*> m_vecObject;

public:


	void Init();
	void Update();
	void Render();
	void Release();
};

