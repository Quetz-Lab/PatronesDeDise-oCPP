#pragma once
#include "Command.h"
class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	Command* handleInput(char tecla);
	
	
	
private:
	Command* botonW_;
	Command* botonF_;
	Command* botonI_;
};

