/**
 * @file InputHandler.h
 * @brief Mapeo de teclas a comandos y despacho de entradas.
 *
 * @details
 * `InputHandler` encapsula la asociación de teclas con objetos `Command`
 * (patrón Command) y expone utilidades para manejar la entrada del usuario y
 * remapear controles en tiempo de ejecución.
 *
 * @note Este archivo incluye `Command.h` y usa `std::map` para los mapeos.
 * @warning La clase mezcla punteros inteligentes en `keyMappings` con punteros
 * crudos para botones dedicados (`botonW_`, `botonF_`, etc.). Revisa la
 * propiedad de memoria y el ciclo de vida para evitar fugas o dobles liberaciones.
 */
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

