#include "stdafx.h"
#include "Math.h"

Math::Math() { srand(time(NULL)); }

float Math::Magnitude(D3DXVECTOR3 vec) { return sqrt(SqrMagnitude(vec)); }
float Math::SqrMagnitude(D3DXVECTOR3 vec) { return pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2); }
float Math::Min(float a, float b) { return (a < b) ? a : b; }
float Math::Max(float a, float b) { return (a > b) ? a : b; }
float Math::Clamp(float num, float min, float max) { num = Max(num, min); return Min(num, max); }
float Math::Distance(D3DXVECTOR3 from, D3DXVECTOR3 to) { return Magnitude(to - from); }
float Math::SqrDistance(D3DXVECTOR3 from, D3DXVECTOR3 to) { return SqrMagnitude(to - from); }


float Math::GetRotY(D3DXVECTOR3 dir)
{
	return atan2(-dir.x, -dir.z);
}

D3DXVECTOR3 Math::Clamp(D3DXVECTOR3 v, float min, float max)
{
	float sqrMagnitude = SqrMagnitude(v);
	if (sqrMagnitude < min * min*min)
	{
		D3DXVec3Normalize(&v, &v);
		return v * min;
	}
	if (sqrMagnitude > max * max*max)
	{
		D3DXVec3Normalize(&v, &v);
		return v * max;
	}
	return v;
}

bool Math::IsCollided(ST_SPHERE c0, ST_SPHERE c1)
{
	float totalRadius = c0.fRadius + c1.fRadius;
	return SqrDistance(c0.vCenter, c1.vCenter) <= totalRadius * totalRadius;
}



// ���� ���� ������ ���� ��ȯ
D3DXVECTOR3 Math::GetOverlappedVector(ST_SPHERE from, ST_SPHERE to)
{
	if (!IsCollided(from, to)) return D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 Length = to.vCenter - from.vCenter;
	D3DXVECTOR3 dir;
	D3DXVec3Normalize(&dir, &Length);
	float magnitude = MATH->Magnitude(Length);
	float length = (from.fRadius + to.fRadius) - magnitude;
	return dir * length;
}


D3DXVECTOR3 Math::LocalToWorld(D3DXVECTOR3 local, D3DXVECTOR3 forward)
{
	D3DXMATRIXA16 matWorld, matR, matT;
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);

	D3DXMatrixRotationY(&matR, MATH->GetRotY(forward));
	D3DXMatrixTranslation(&matT, local.x, local.y, local.z);

	D3DXVECTOR3 localToWorld;
	matWorld = matR*matT;
	D3DXVec3TransformCoord(&localToWorld, &local, &matR);
	return localToWorld;
}