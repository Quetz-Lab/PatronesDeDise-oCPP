#pragma once
#include "Command.h"
#include <string>
#include <map>
#include <memory> //Para usar std::unique_ptr
class InputHandler
{
private:
	std::map<char, std::unique_ptr<Command>> keyMappings;
	Command* botonW_;
	Command* botonF_;
	Command* botonI_;

public:
	InputHandler();
	~InputHandler();
	Command* handleInput(char tecla);
	
	void remapearTecla(char telca, std::string accion)
	{
		if (keyMappings.count(tecla))
			keyMappings[tecla]->execute();
	}
	void bindCommand(char tecla, std::unique_ptr<Command> command)
	{
		keyMappings[tecla] = std::move(command);
	}

};

