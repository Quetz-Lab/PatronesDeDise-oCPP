#pragma once
#include "Character.h"
#include <iostream>

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
		std::cout << "Remapeo no exitoso" << std::endl;
	}
};

