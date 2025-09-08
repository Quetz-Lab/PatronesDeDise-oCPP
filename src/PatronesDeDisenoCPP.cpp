// PatronesDeDisenoCPP.cpp : Este archivo contiene la función "main". 
// La ejecución del programa comienza y termina ahí.

#include <iostream>

#include "Achievements.h"
#include "AudioSystem.h"
#include "Character.h"
#include "EventQueue.h"
#include "State.h"

int main()
{
    char tecla;
    State state;
    Character* player = new Character(20, 20, 10, 10, 10, 0);
    
    // Agregar instancia de observadores utilizando apuntadores
    Achievements* achievements = new Achievements();
    AudioSystem* audioSystem = new AudioSystem();
    AudioSystem audioSystem2 = AudioSystem();
    
    // Menú de inicio
    std::cout << "=================================\n";
    std::cout << "Bienvenido al juego \n";
    std::cout << "Aprieta una tecla para jugar\n";
    std::cout << "=================================\n";
    
    // Update loop
    while (true)
    {
        // Solicitamos los audios pendientes
        audioSystem2.RequestSound({SoundID::HIT});
        audioSystem2.RequestSound({SoundID::JUMP});
        audioSystem2.RequestSound({SoundID::DEATH});
        audioSystem2.RequestSound({SoundID::HIT});
        audioSystem2.RequestSound({SoundID::HIT});

        std::cout << "--- Fin del frame de logica ---\n";

        std::cout << "Ingresa comando (w = saltar, f = atacar, x = salir, v = Debuggear dano): ";
        std::cin >> tecla;

        std::cin >> tecla;
        if (tecla == 'w')
        {
            player->Jump();
        }
        else if (tecla == 'f')
        {
            player->Shoot();
        }
        else if (tecla == 'v')
        {
            player->DebugGetDamage();
        }
        else
        {
            std::cout << "=================================\n";
            std::cout << "Tecla invalida\n";
            std::cout << "=================================\n";
        }
        
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    
    // Cleanup (aunque nunca se alcanza en este caso)
    delete player;
    delete achievements;
    delete audioSystem;
    
    return 0;
}