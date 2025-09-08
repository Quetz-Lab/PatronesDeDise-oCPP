#pragma once
/**
 * @file State.h
 * @brief Definición de estados básicos para un personaje o entidad de juego.
 *
 * @details
 * Contiene la enumeración `StateEnum` con los posibles estados
 * y la clase `State`, que mantiene el estado actual y un temporizador asociado.
 */

 /**
  * @enum StateEnum
  * @brief Estados posibles de una entidad controlada por la máquina de estados.
  *
  * @details
  * Define los estados más comunes de un personaje (reposo, salto, ataque).
  */
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

