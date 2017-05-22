#include "stdafx.h"
#include "cTextureManager.h"


void cTextureManager::Init()
{
}

LPDIRECT3DTEXTURE9 cTextureManager::GetTexture(char * szFullPath)
{
	return LPDIRECT3DTEXTURE9();
}

LPDIRECT3DTEXTURE9 cTextureManager::GetTexture(std::string & sFullPath)
{
	return LPDIRECT3DTEXTURE9();
}

void cTextureManager::SetTexture(char * szFullPath)
{
	if (m_mapTexture.find(szFullPath) == m_mapTexture.end())
	{
		D3DXCreateTextureFromFile(D3DDevice, TEXT("szFullPath"),
			&m_mapTexture[szFullPath]);
	}
}

void cTextureManager::SetTexture(string & sFullPath)
{
	SetTexture((char*)sFullPath.c_str());
}

void cTextureManager::Destroy()
{
}
