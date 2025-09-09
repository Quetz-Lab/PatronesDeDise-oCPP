/**
 * @file Command.h
 * @brief Comandos del patrón Command que operan sobre `Character`.
 *
 * @details
 * Define una interfaz abstracta `Command` y varias implementaciones concretas
 * (saltar, disparar, agacharse, remapear y daño de depuración) que encapsulan
 * acciones a ejecutar sobre un `Character`. Esto permite desacoplar la entrada
 * de usuario de la lógica de juego.
 *
 * @note Requiere `Character.h` y `InputHandler.h`.
 * @warning Algunas implementaciones realizan E/S de consola (bloqueante) y
 * podrían no ser adecuadas para entornos en tiempo real.
 */

#pragma once

#include <iostream>

#include "../Core/Character.h"
#include "../Patterns/InputHandler.h"

class Observer; // Forward declaration to avoid circular dependency


/**
 * @class Command
 * @brief Interfaz abstracta para el patrón Command.
 *
 * @details
 * Esta clase define la interfaz común para todos los comandos que pueden
 * ser ejecutados sobre un `Character`. Implementa el patrón Command clásico
 * que encapsula una solicitud como un objeto, permitiendo parametrizar
 * clientes con diferentes solicitudes, encolar operaciones y soportar
 * operaciones reversibles.
 */
class Command
{
public:
    /**
     * @brief Destructor virtual.
     * @details Asegura la destrucción correcta de comandos derivados.
     */
    virtual ~Command();
    
    /**
     * @brief Ejecuta el comando sobre el personaje especificado.
     * @param character Referencia al personaje sobre el cual ejecutar el comando.
     * 
     * @details
     * Método puramente virtual que debe ser implementado por todas las
     * clases derivadas para definir la acción específica del comando.
     * 
     * @note Método puramente virtual que debe ser implementado por todas las clases derivadas.
     */
    virtual void execute(Character& character) = 0;
};

/**
 * @class JumpCommand
 * @brief Comando concreto para ejecutar la acción de salto.
 *
 * @details
 * Implementa el patrón Command para encapsular la acción de salto del personaje.
 * Cuando se ejecuta, llama al método Jump() del personaje.
 */
class JumpCommand : public Command
{
public:
    /**
     * @brief Ejecuta la acción de salto en el personaje.
     * @param character Referencia al personaje que realizará el salto.
     * @post El personaje ejecuta su acción de salto.
     */
    virtual void execute(Character& character) override
    {
        character.Jump();
    }
};

/**
 * @class ShootCommand
 * @brief Comando concreto para ejecutar la acción de disparo.
 *
 * @details
 * Implementa el patrón Command para encapsular la acción de disparo del personaje.
 * Cuando se ejecuta, llama al método Shoot() del personaje.
 */
class ShootCommand : public Command
{
public:
    /**
     * @brief Ejecuta la acción de disparo en el personaje.
     * @param character Referencia al personaje que realizará el disparo.
     * @post El personaje ejecuta su acción de disparo.
     */
    virtual void execute(Character& character) override
    {
        character.Shoot();
    }
};

/**
 * @class CrouchCommand
 * @brief Comando concreto para ejecutar la acción de agacharse.
 *
 * @details
 * Implementa el patrón Command para encapsular la acción de agacharse del personaje.
 * Cuando se ejecuta, llama al método Crouch() del personaje.
 */
class CrouchCommand : public Command
{
public:
    /**
     * @brief Ejecuta la acción de agacharse en el personaje.
     * @param character Referencia al personaje que se agachará.
     * @post El personaje ejecuta su acción de agacharse.
     */
    virtual void execute(Character& character) override
    {
        character.Crouch();
    }
};

/**
 * @class RemapCommand
 * @brief Comando concreto para remapear controles de teclado.
 *
 * @details
 * Implementa el patrón Command para permitir el remapeo dinámico de teclas
 * a acciones específicas. Solicita al usuario una nueva tecla y acción,
 * luego actualiza el mapeo en el InputHandler.
 * 
 * @warning Este comando realiza E/S bloqueante de consola y puede no ser
 * adecuado para entornos en tiempo real.
 */
class RemapCommand : public Command
{
public:
    /**
     * @brief Ejecuta el proceso de remapeo de teclas.
     * @param character Referencia al personaje (no utilizada en esta implementación).
     * 
     * @details
     * Solicita al usuario que ingrese una nueva tecla y la acción asociada,
     * luego actualiza el mapeo de teclas en el InputHandler.
     * 
     * @post Se actualiza el mapeo de teclas según la entrada del usuario.
     * @warning Realiza E/S bloqueante de consola.
     */
    virtual void execute(Character& character) override
    {
        std::cout << "Elige la nueva tecla" << std::endl;
        char newKey;
        std::cin >> newKey;
        std::cout << "Elige la accion (jump, shoot, crouch)" << std::endl;
        std::string action;
        std::cin >> action;
        InputHandler inputHandler;
        inputHandler.remapearTecla(newKey, action);
        std::cout << "Tecla remapeada a: " << newKey << " para la acción: " << action << std::endl;
    }
};

/**
 * @class GetDamageDebug
 * @brief Comando de depuración para simular daño al personaje.
 *
 * @details
 * Implementa el patrón Command para proporcionar una utilidad de depuración
 * que simula que el personaje recibe daño. Reduce la salud del personaje
 * en una cantidad fija y activa el sistema de notificación de daño.
 * 
 * @warning Solo debe usarse para depuración y testing, no en builds de producción.
 */
class GetDamageDebug : public Command
{
public:
    /**
     * @brief Simula que el personaje recibe daño.
     * @param character Referencia al personaje que recibirá el daño simulado.
     * 
     * @details
     * Reduce la salud del personaje en 10 puntos, asegurándose de que no
     * baje de 0, y luego activa el sistema de notificación de daño.
     * 
     * @post La salud del personaje se reduce y se notifica a los observadores.
     * @warning Solo para depuración; no usar en producción.
     */
    virtual void execute(Character& character) override
    {
        // Simular que el personaje recibe daño
        float currentHealth = character.GetHealth();
        currentHealth -= 10; // Valor de daño de ejemplo
        if (currentHealth < 0) currentHealth = 0;
        character.SetHealth(currentHealth);
        std::cout << "Character received damage, new health: " << character.GetHealth() << std::endl;
        character.GetDamage();
    }
};