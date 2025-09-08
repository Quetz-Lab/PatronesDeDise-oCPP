#pragma once

/**
 * @file Command.h
 * @brief Comandos del patrón Command que operan sobre `Character`.
 *
 * @details
 * Define una interfaz abstracta `Command` y varias implementaciones concretas
 * (saltar, disparar, agacharse, remapear y daño de depuración) que encapsulan
 * acciones a ejecutar sobre un `Character`. Esto permite desacoplar la entrada
 * de usuario de la lógica de juego.
 *
 * @note Requiere `Character.h` y `InputHandler.h`.
 * @warning Algunas implementaciones realizan E/S de consola (bloqueante) y
 * podrían no ser adecuadas para entornos en tiempo real.
 */

#include "Character.h"
#include <iostream>
#include "InputHandler.h"
class Observer; // Forward declaration to avoid circular dependency
class Command
{
public:
	
	virtual ~Command();
	virtual void execute(Character& character) = 0;
};

class JumpCommand : public Command
{
public:
	virtual void execute(Character& character) override
	{
		character.Jump();
	}
};

class ShootCommand : public Command
{
	public:
	virtual void execute(Character& character) override
	{
		character.Shoot();
	}
};

class CrouchCommand : public Command
{
	public:
	virtual void execute(Character& character) override
	{
		// Assuming Character has a Crouch method
		character.Crouch();
	}
};
class RemapCommand : public Command
{
public:
	virtual void execute(Character& character) override
	{
		// This command could be used to remap keys, but for simplicity, we won't implement it here.
		std::cout << "Elige la nueva tecla" << std::endl;
		char newKey;
		std::cin >> newKey;
		std::cout << "Elige la accion (jump, shoot, crouch)" << std::endl;
		std::string action;
		std::cin >> action;
		InputHandler inputHandler;

		inputHandler.remapearTecla(newKey, action);
		std::cout << "Tecla remapeada a: " << newKey << " para la accin: " << action << std::endl;



	}
};

class GetDamageDebug : public Command
{
	public:
	virtual void execute(Character& character) override
	{
		// Simulate the character taking damage
		float currentHealth = character.GetHealth();
		currentHealth -= 10; // Example damage value
		if (currentHealth < 0) currentHealth = 0;
		character.SetHealth(currentHealth);
		std::cout << "Character received damage, new health: " << character.GetHealth() << std::endl;
		character.GetDamage();
	}
};

