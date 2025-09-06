#pragma once
#include "Observer.h"
class Achievements :
    public Observer
{
public:
        Achievements() {}
    ~Achievements() {}
   virtual void OnNotify(const Character& character, Event event)
    {
	   // Implementación específica para logros
	   // Por ejemplo, ¡Logro desbloqueado 'Primer Golpe'! esto al personaje cuando recibe daño
       if (event == Event::Character_Get_Damage)
       {
           std::cout << "¡Logro desbloqueado 'Primer Golpe'!" << std::endl;
	   }
	}
};

