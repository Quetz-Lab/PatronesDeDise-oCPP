#include "InputHandler.h"

InputHandler::InputHandler()
{
    // Al crear el InputHandler, creamos las instancias de nuestros comandos
    botonW_ = new JumpCommand();
    botonF_ = new ShootCommand();
    botonI_ = new CrouchCommand();
}

InputHandler::~InputHandler()
{
    // Es crucial liberar la memoria que asignamos para evitar memory leaks
    delete botonW_;
    delete botonF_;
    delete botonI_;
}

Command* InputHandler::handleInput(char tecla)
{
    if (tecla == 'w') return botonW_;
    if (tecla == 'f') return botonF_;
    if (tecla == 'i') return botonI_;

    // Si no es una tecla mapeada, no devolvemos ningún comando
    return nullptr;
}

void InputHandler::remapearTecla(char telca, std::string accion)
{
    // Este método podría ser implementado para cambiar la asignación de teclas
    // Por ahora, no se implementa ninguna lógica específica
	std::cout << "Remapeando tecla '" << telca << "' a acción '" << accion << "' (no implementado)\n";
}
