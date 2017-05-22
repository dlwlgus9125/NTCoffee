#pragma once
class cObject
{
	//vector<ST_PNT_VERTEX> m_vecVertex;
protected:
	ULONG m_ulRefCount;
public:
	cObject();
	virtual ~cObject();
	virtual void Init() {};
	virtual void Update() {};
	virtual void Render() {};
	virtual void AddRef();
	virtual void Release();
};
