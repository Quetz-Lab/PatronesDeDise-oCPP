#pragma once
#include "Observer.h"
#include "EventQueue.h"
class AudioSystem :
    public Observer
{
    public:
		static const int MAX_PENDING = 16;
		SoundID pendingSounds[MAX_PENDING];
		int pendingCount;
        AudioSystem();
        ~AudioSystem();
		void RequestSound(SoundEvent event);
		void processEvents();
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

