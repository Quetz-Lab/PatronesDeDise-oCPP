#pragma once

enum StateEnum
{
	IDLE,
	JUMPING,
	ATTACKING
};
class State
{
public:
	StateEnum m_CurrentState;
	int m_stateTimer;
	State() : m_CurrentState(IDLE), m_stateTimer(0) {}
};

