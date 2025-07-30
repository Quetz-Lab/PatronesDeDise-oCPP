#pragma once
#include "Command.h"
#include <string>
class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	Command* handleInput(char tecla);
	
	void remapearTecla(char telca, std::string accion);
	
private:
	Command* botonW_;
	Command* botonF_;
	Command* botonI_;
};

