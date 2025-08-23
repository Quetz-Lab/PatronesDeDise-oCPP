// PatronesDeDisenoCPP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Character.h"
#include "State.h"
#include "Achievements.h"
#include "AudioSystem.h"
int main()
{
	char tecla;
	State state;
    Character* player = new Character(20,20,10,10,10, 0);
	//Agregar instancia de observadores utiliznado apuntadores
	Achievements* achievements = new Achievements();
	AudioSystem* audioSystem = new AudioSystem();
	//Menu de inicio
  
	std::cout << "=================================\n";
	std::cout << "Bienvenido al juego \n";
	std::cout << "Aprieta una tecla para jugar\n";
	std::cout << "=================================\n";
	//Update
	while (true)
	{
		
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
}