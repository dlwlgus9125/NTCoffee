#pragma once
#include "ISteeringEntity.h"
#include "cObject.h"

class cCharacter : public cObject
{
protected:
	ISteeringEntity* m_CharacterEntity;
	MeshSpere        m_CollideSphere;
	MeshSpere        m_dirSphere;
public:
	cCharacter();
	virtual ~cCharacter();

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();

	MeshSpere        GetMeshSphere() { return m_CollideSphere; }
	ISteeringEntity* GetCharacterEntity() { return m_CharacterEntity; }

	void RenderSphere();

};

