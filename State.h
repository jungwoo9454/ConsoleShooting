#pragma once


//FSM(유한 상태 기계) - 씬

// 상태 클래스^^
class CState
{
public:
	int			m_nStateIndex;		// 현재 State 인덱스
	CState*		m_pCurState;		// 현재 State 포인터(자기자신)

public:
	CState();
	~CState();

public:
	virtual void Start() = 0;		//순수가상함수
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Exit() = 0;

};