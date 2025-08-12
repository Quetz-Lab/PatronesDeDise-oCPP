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
	Command* botonR_; // Botón para remapear teclas

public:
	InputHandler();
	~InputHandler();
	Command* handleInput(char tecla);
	// Método para remapear teclas a acciones
	void remapearTecla(char tecla, std::string accion);
	

};

