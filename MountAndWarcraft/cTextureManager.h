#pragma once
#include "Singleton.h"

#define TEXTURE cTextureManager::Instance() 

class cTextureManager :
	public Singleton<cTextureManager>
{
private:
	map<string, LPDIRECT3DTEXTURE9> m_mapTexture;
public:
	void                Init();
	LPDIRECT3DTEXTURE9	GetTexture(char* szFullPath);
	LPDIRECT3DTEXTURE9	GetTexture(string& sFullPath);
	void                SetTexture(char* szFullPath);
	void                SetTexture(string& sFullPath);
	void Destroy();
};

