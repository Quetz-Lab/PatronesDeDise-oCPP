#pragma once
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

