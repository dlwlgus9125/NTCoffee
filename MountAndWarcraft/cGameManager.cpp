#include "stdafx.h"
#include "cGameManager.h"
#include "cObjectManager.h"
#include "TestMap.h"





void cGameManager::Init()
{
	DEVICE->Init();
	TIME->Init(60);
	
	OBJECT->Init();
	
    CAMERA->Setup();
	
	TESTMAP->Setup();
	INPUT->Init();
	//<<
}

void cGameManager::Update()
{
	if (TIME->Update())
	{
		//cout << m_player->GetCharacterEntity()->Pos().x << ", " << m_player->GetCharacterEntity()->Pos().y << ", " << m_player->GetCharacterEntity()->Pos().z << endl;

		m_prevTime = m_currentTime;
		INPUT->Update();
		
		OBJECT->Update(TIME->DeltaTime());
		CAMERA->Update();
	}

}

void cGameManager::Render()
{
	CAMERA->Update();
	D3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(47, 121, 112),
		1.0f, 0);
	D3DDevice->BeginScene();

	OBJECT->Render();
	TESTMAP->Render();
	D3DDevice->EndScene();
	D3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cGameManager::Release()
{
}

void cGameManager::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	CAMERA->WndProc(hwnd, message, wParam, lParam);


	switch (message)
	{
	case WM_LBUTTONDOWN:
	{

	}
	break;

	case WM_RBUTTONDOWN:
	{

	}
	break;
	}
}


