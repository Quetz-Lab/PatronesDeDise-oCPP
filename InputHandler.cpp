#include "InputHandler.h"

InputHandler::InputHandler()
{
    // Al crear el InputHandler, creamos las instancias de nuestros comandos
    botonW_ = new JumpCommand();
    botonF_ = new ShootCommand();
    botonI_ = new CrouchCommand();
	botonR_ = new RemapCommand(); // Inicializamos el botón de remapeo a nullptr, no lo usamos en este ejemplo
}

InputHandler::~InputHandler()
{
    // Es crucial liberar la memoria que asignamos para evitar memory leaks
    delete botonW_;
    delete botonF_;
    delete botonI_;
	delete botonR_; // Liberamos el botón de remapeo
}

Command* InputHandler::handleInput(char tecla)
{
    if (tecla == 'w') return botonW_;
    if (tecla == 'f') return botonF_;
    if (tecla == 'i') return botonI_;
	if (tecla == 'r') return botonR_; // Si se presiona 'r', devolvemos el comando de remapeo

    // Si no es una tecla mapeada, no devolvemos ningún comando
    return nullptr;
}

void InputHandler::remapearTecla(char tecla, std::string accion)
{
    // Remapea la tecla a una acción específica
    if (accion == "jump") {
        keyMappings[tecla] = std::unique_ptr<Command>(botonW_);
    } else if (accion == "shoot") {
        keyMappings[tecla] = std::unique_ptr<Command>(botonF_);
    } else if (accion == "crouch") {
        keyMappings[tecla] = std::unique_ptr<Command>(botonI_);
    } else {
        // Si la acción no es válida, podríamos lanzar una excepción o manejar el error
	}
}



