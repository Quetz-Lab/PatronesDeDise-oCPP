// PatronesDeDisenoCPP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Character.h"
int main()
{
	char tecla;
    Character* player = new Character(20,20,10,10,10);
  
	std::cout << "=================================\n";
	std::cout << "Bienvenido al juego \n";
	std::cout << "Aprieta una tecla para jugar\n";
	std::cout << "=================================\n";
	//Update
	while (true)
	{
		
		std::cin >> tecla;
		if (tecla == 'w')
		{
			player->Jump();
		}
		else if (tecla == 'f')
		{
			player->Shoot();
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

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
