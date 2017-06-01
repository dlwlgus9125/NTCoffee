#pragma once
#include "cCharacter.h"
class cUnit :
	public cCharacter
{
	IEntity* m_pLeader;
	D3DXVECTOR3 m_offset;
public:
	cUnit(IEntity* pLeader, D3DXVECTOR3 offset);
	~cUnit();

	void Init();
	void Update(float deltaTime);
	void Render();
	void SetOffset(D3DXVECTOR3 offset) { m_offset = offset; }
	D3DXVECTOR3 GetOffset() { return m_offset; }
};

