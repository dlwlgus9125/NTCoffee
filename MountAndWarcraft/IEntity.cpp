#include "stdafx.h"
#include "IEntity.h"


IEntity::IEntity(D3DXVECTOR3 pos, float radius, D3DXVECTOR3 forward ,
	float mass, float maxSpeed)
{
	static int id_counter = 1;
	m_uniqueId = id_counter++;

	m_pos = pos;
	m_forward = forward;
	m_velocity = D3DXVECTOR3(0, 0, 0);
	m_radius = radius;
	m_mass = mass;
	m_maxSpeed = maxSpeed;
}

IEntity::~IEntity() {}

int IEntity::UniqueID() { return m_uniqueId; }
D3DXVECTOR3 IEntity::Pos() { return m_pos; }
D3DXVECTOR3 IEntity::Forward() { return m_forward; }
D3DXVECTOR3 IEntity::Velocity() { return m_velocity; }
float IEntity::Radius() { return m_radius; }
float IEntity::Mass() { return m_mass; }
float IEntity::Speed() { return MATH->Magnitude(m_velocity); }
float IEntity::MaxSpeed() { return m_maxSpeed; }

void IEntity::SetPos(D3DXVECTOR3 pos) { m_pos = pos; }
void IEntity::AddPos(D3DXVECTOR3 pos) { SetPos(m_pos + pos); }
void IEntity::SetForward(D3DXVECTOR3 forward)
{
	if (MATH->SqrMagnitude(forward) < EPSILON) return;
	D3DXVec3Normalize(&m_forward, &forward);
}
void IEntity::SetVelocity(D3DXVECTOR3 velocity) { m_velocity = MATH->Clamp(velocity, 0, MaxSpeed()); }
void IEntity::AddVelocity(D3DXVECTOR3 velocity) { SetVelocity(m_velocity + velocity); }
void IEntity::SetRadius(float radius) { m_radius = radius; }
