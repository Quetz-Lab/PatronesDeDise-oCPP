// PatronesDeDisenoCPP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Character.h"
#include "InputHandler.h"
int main()
{
	char tecla;
    Character* player = new Character(20,20,10,10,10);
	InputHandler inputHandler;
	std::cout << "=================================\n";
	std::cout << "Bienvenido al juego \n";
	std::cout << "Aprieta una tecla para jugar\n";
	std::cout << "Controles: 'w' = Saltar, 'f' = Disparar, 'i' = Agacharse\n";
	std::cout << "=================================\n";
	//Update
	while (true)
	{
		
		std::cin >> tecla;
		Command* command = inputHandler.handleInput(tecla);
		if (command!= nullptr)
		{
			command->execute(*player);
		}
		else
		{
			std::cout << "=================================\n";
			std::cout << "Tecla invalida\n";
			std::cout << "=================================\n";
		}
		std::cout << "\n\n\n*************Next Frame***********\n";
		tecla = ' ';
	}
	delete player; // Liberar la memoria del jugador
}
