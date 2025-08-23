#pragma once
#include "Observer.h"
class AudioSystem :
    public Observer
{
    public:
    AudioSystem() {}
    ~AudioSystem() {}
   virtual void OnNotify(const Character& character, Event event) 
    {
       // Implementación específica para el sistema de audio
       // Por ejemplo, reproducir un sonido cuando el personaje recibe daño
       if (event == Event::Character_Get_Damage)
       {
           std::cout << "Reproduciendo sonido de daño al personaje." << std::endl;
       }
   }
};

