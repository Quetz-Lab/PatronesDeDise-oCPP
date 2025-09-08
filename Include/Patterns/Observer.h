#pragma once
/**
 * @file Observer.h
 * @brief Definición del patrón Observer para notificar eventos de `Character`.
 *
 * @details
 * Define la interfaz abstracta `Observer` que escucha cambios o sucesos
 * de un `Character`, y el `enum class Event` con los tipos de eventos
 * que pueden notificarse.
 *
 * @note Evita dependencias circulares declarando `class Character;` en vez
 * de incluir directamente todo `Character.h`. Aquí, sin embargo, se incluye
 * para garantizar la definición completa si se necesita en la implementación.
 */
#include "Character.h"

class Character; // Forward declaration to avoid circular dependency
class Observer
{
	public:
		//Destructor virtual
	virtual ~Observer() {}
	//Metodo para notificar mediante el patron Observer 
	virtual void OnNotify(const Character& character, Event event) = 0;

};

enum class Event
{
	Character_Get_Damage
};

