
#include "Command.h"
#include <string>
#include <map>
#include <memory> //Para usar std::unique_ptr
class Command; // Forward declaration
//Una forward declaration de Command es necesaria para evitar dependencias circulares
class InputHandler
{
private:
	std::map<char, std::shared_ptr<Command>> keyMappings;
	Command* botonW_;
	Command* botonF_;
	Command* botonI_;
	Command* botonR_; // Boton para remapear teclas
	Command* botonV_;

public:
	InputHandler();
	~InputHandler();
	Command* handleInput(char tecla);
	// Metodo para remapear teclas a acciones
	void remapearTecla(char tecla, std::string accion);
	


};

