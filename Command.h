#pragma once

#include "Character.h"
#include <iostream>
#include "InputHandler.h"
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

