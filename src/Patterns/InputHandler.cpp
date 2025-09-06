#include "InputHandler.h"

InputHandler::InputHandler()
{
    // Al crear el InputHandler, creamos las instancias de nuestros comandos
    botonW_ = new JumpCommand();
    botonF_ = new ShootCommand();
    botonI_ = new CrouchCommand();
	botonR_ = new RemapCommand(); // Inicializamos el bot�n de remapeo a nullptr, no lo usamos en este ejemplo
	botonV_ = new GetDamageDebug();
}

InputHandler::~InputHandler()
{
    // Es crucial liberar la memoria que asignamos para evitar memory leaks
    delete botonW_;
    delete botonF_;
    delete botonI_;
	delete botonR_; // Liberamos el bot�n de remapeo
}

Command* InputHandler::handleInput(char tecla)
{
    if (tecla == 'w') return botonW_;
    if (tecla == 'f') return botonF_;
    if (tecla == 'i') return botonI_;
    if (tecla == 'v') return botonV_;
	if (tecla == 'r') return botonR_; // Si se presiona 'r', devolvemos el comando de remapeo

    // Si no es una tecla mapeada, no devolvemos ningun comando
    return nullptr;
}

void InputHandler::remapearTecla(char tecla, std::string accion)
{
    // Remapea la tecla a una acci�n espec�fica
    if (accion == "jump") {
        keyMappings[tecla] = std::make_unique<JumpCommand>();
		std::cin >> tecla; // Consumir el espacio
    }
    else if (accion == "shoot") {
        keyMappings[tecla] = std::make_unique<ShootCommand>();
    }
    else if (accion == "crouch") {
        keyMappings[tecla] = std::make_unique<CrouchCommand>();

    }
    else if (accion == "DebugDamage")
    {
		keyMappings[tecla] = std::make_unique<GetDamageDebug>();

    }
	//Usamos make_unique para crear y asignar el comando en una sola linea
	//Lo que hace make_unique es crear un objeto de tipo Command y devolver un puntero unico a ese objeto
    else {
        // Si la accion no es valida, podriamos lanzar una excepcin o manejar el error
	}
}