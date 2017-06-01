#include "stdafx.h"
#include "cUnit.h"


cUnit::cUnit(IEntity* pLeader, D3DXVECTOR3 offset)
{
	m_CharacterEntity = new ISteeringEntity(pLeader->Pos(), pLeader->Radius() * 0.6f,
		pLeader->Forward(), pLeader->Mass(), pLeader->MaxSpeed() * 3);
	m_pLeader = pLeader;
	m_offset = offset;
}


cUnit::~cUnit()
{
	delete m_CharacterEntity;
	//delete m_pLeader;
}

void cUnit::Init()
{
	cCharacter::Init();
}

void cUnit::Update(float deltaTime)
{
	cCharacter::Update(deltaTime);
	//m_dirSphere.m_vCenter = m_CharacterEntity->Pos() + m_CharacterEntity->Forward()*0.5f;
	D3DXVECTOR3 worldOffset = MATH->LocalToWorld(m_offset, m_pLeader->Forward());
	D3DXVECTOR3 targetPos = m_pLeader->Pos() + worldOffset;
	float distance = MATH->Distance(m_CharacterEntity->Pos(), targetPos);

	if (distance > 0.5f)
	{

		m_CharacterEntity->Steering()->OffsetPursuit(m_pLeader, m_offset);
		//Steering()->AvoidObstacle(g_entities);
		//m_CharacterEntity->Steering()->UpdateVelocity(deltaTime);
		m_CharacterEntity->Steering()->ConstrainOverlap(OBJECT->GetEntities());
		/*m_CharacterEntity->Steering()->ConstrainOverlap(g_obstacles);*/
		//m_CharacterEntity->AddPos(m_CharacterEntity->Velocity() * 0.01f);
	}
	else
	{
		m_CharacterEntity->SetForward(m_pLeader->Forward());
	}
}

void cUnit::Render()
{
	cCharacter::Render();

}
