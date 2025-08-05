#pragma once
#include "State.h"
class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	void HandleInput(State& state, char input)
	{
		switch (input)
		{
		case 'w':
			state.m_CurrentState = JUMPING;
			state.m_stateTimer = 0; // Reset timer for jumping state
			break;
		case 'f':
			state.m_CurrentState = ATTACKING;
			state.m_stateTimer = 0; // Reset timer for attacking state
			break;
		default:
			state.m_CurrentState = IDLE;
			state.m_stateTimer = 0; // Reset timer for idle state
			break;
		}
	}
	void UpdateState(State& state)
	{
		if (state.m_CurrentState == JUMPING || state.m_CurrentState == ATTACKING)
		{
			state.m_stateTimer++;
			if (state.m_stateTimer > 10) // Example timer limit
			{
				state.m_CurrentState = IDLE; // Reset to idle after timer exceeds limit
				state.m_stateTimer = 0;
			}
		}
	}
};

