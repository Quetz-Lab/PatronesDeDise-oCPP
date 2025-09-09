
 

#pragma once

/**
 * @file Observer.h
 * @brief Definici�n del patr�n Observer para notificar eventos de `Character`.
 *
 * @details
 * Define la interfaz abstracta `Observer` que escucha cambios o sucesos
 * de un `Character`, y el `enum class Event` con los tipos de eventos
 * que pueden notificarse.
 *
 * @note Evita dependencias circulares declarando `class Character;` en vez
 * de incluir directamente todo `Character.h`. Aqu�, sin embargo, se incluye
 * para garantizar la definici�n completa si se necesita en la implementaci�n.
 */
#include "../Core/Character.h"


class Character; // Forward declaration to avoid circular dependency

/**
 * @enum Event
 * @brief Enumeración de eventos que pueden ser notificados por el sistema Observer.
 *
 * @details
 * Define los diferentes tipos de eventos que un `Character` puede generar
 * y que los observadores pueden recibir para reaccionar apropiadamente.
 */
enum class Event
{
    Character_Get_Damage  ///< Evento disparado cuando el personaje recibe daño
};

/**
 * @class Observer
 * @brief Interfaz abstracta para el patrón Observer.
 *
 * @details
 * Esta clase define la interfaz que deben implementar todos los observadores
 * que deseen recibir notificaciones de eventos del `Character`. Implementa
 * el patrón Observer clásico donde el Subject (Character) notifica a múltiples
 * observadores cuando ocurren eventos de interés.
 *
 * @note Esta es una clase abstracta pura que no puede ser instanciada directamente.
 */
class Observer
{
public:
    /**
     * @brief Destructor virtual.
     * @details Asegura la destrucción correcta de clases derivadas.
     */
    virtual ~Observer() {}
    
    /**
     * @brief Método de notificación del patrón Observer.
     * @param character Referencia constante al personaje que generó el evento.
     * @param event Tipo de evento que ocurrió.
     * 
     * @details
     * Este método es llamado automáticamente por el `Character` cuando ocurre
     * un evento. Las clases derivadas deben implementar este método para
     * definir cómo reaccionar a cada tipo de evento.
     * 
     * @note Método puramente virtual que debe ser implementado por todas las clases derivadas.
     */
    virtual void OnNotify(const Character& character, Event event) = 0;
};

