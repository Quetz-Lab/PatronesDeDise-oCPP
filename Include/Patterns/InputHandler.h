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

#pragma once

#include <map>
#include <memory>
#include <string>

#include "Command.h"

class Command; // Forward declaration para evitar dependencias circulares

/**
 * @class InputHandler
 * @brief Maneja la entrada del usuario y mapea teclas a comandos.
 *
 * @details
 * Esta clase implementa el patrón Command para manejar la entrada del usuario.
 * Mantiene un mapeo de teclas a comandos específicos y permite el remapeo
 * dinámico de controles durante la ejecución. Utiliza tanto punteros crudos
 * para comandos predefinidos como punteros inteligentes para comandos dinámicos.
 *
 * @warning Mezcla diferentes tipos de gestión de memoria (punteros crudos y inteligentes).
 * Se recomienda unificar el enfoque en futuras versiones.
 */
class InputHandler
{
private:
    std::map<char, std::shared_ptr<Command>> keyMappings;  ///< Mapeo dinámico de teclas a comandos
    Command* botonW_;  ///< Comando predefinido para la tecla 'W' (saltar)
    Command* botonF_;  ///< Comando predefinido para la tecla 'F' (disparar)
    Command* botonI_;  ///< Comando predefinido para la tecla 'I' (agacharse)
    Command* botonR_;  ///< Comando predefinido para la tecla 'R' (remapear)
    Command* botonV_;  ///< Comando predefinido para la tecla 'V' (debug daño)

public:
    /**
     * @brief Constructor por defecto.
     * @details Inicializa todos los comandos predefinidos y configura el mapeo básico de teclas.
     * @post Todos los comandos básicos están listos para usar.
     */
    InputHandler();
    
    /**
     * @brief Destructor.
     * @details Libera la memoria de todos los comandos predefinidos.
     * @warning Los comandos en keyMappings se liberan automáticamente por shared_ptr.
     */
    ~InputHandler();
    
    /**
     * @brief Maneja la entrada de una tecla y devuelve el comando correspondiente.
     * @param tecla Carácter de la tecla presionada.
     * @return Puntero al comando asociado con la tecla, o nullptr si no hay mapeo.
     * 
     * @details
     * Busca primero en los comandos predefinidos (W, F, I, R, V) y luego
     * en el mapeo dinámico. Si no encuentra ningún comando asociado, devuelve nullptr.
     * 
     * @note El puntero devuelto no debe ser liberado por el llamador.
     */
    Command* handleInput(char tecla);
    
    /**
     * @brief Remapea una tecla a una nueva acción de comando.
     * @param tecla El carácter de la tecla a remapear (ej. 'w').
     * @param accion El nombre de la acción a asignar (ej. "jump", "shoot", "crouch", "DebugDamage").
     * 
     * @details
     * Crea un nuevo comando basado en la acción especificada y lo asocia con la tecla
     * en el mapeo dinámico. Las acciones válidas son:
     * - "jump": Crea un JumpCommand
     * - "shoot": Crea un ShootCommand  
     * - "crouch": Crea un CrouchCommand
     * - "DebugDamage": Crea un GetDamageDebug
     * 
     * @post La tecla queda asociada al nuevo comando en keyMappings.
     * @warning Si la acción no es reconocida, no se realiza ningún mapeo.
     */
    void remapearTecla(char tecla, const std::string& accion);
};