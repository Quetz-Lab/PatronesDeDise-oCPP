/**
 * @file State.h
 * @brief Definición de estados básicos para un personaje o entidad de juego.
 *
 * @details
 * Contiene la enumeración `StateEnum` con los posibles estados
 * y la clase `State`, que mantiene el estado actual y un temporizador asociado.
 * Implementa los fundamentos del patrón State para controlar el comportamiento
 * de entidades basado en su estado interno.
 */

#pragma once

/**
 * @enum StateEnum
 * @brief Estados posibles de una entidad controlada por la máquina de estados.
 *
 * @details
 * Define los estados más comunes de un personaje en un juego:
 * - IDLE: Estado de reposo, el personaje no está realizando ninguna acción especial
 * - JUMPING: Estado de salto, el personaje está en el aire
 * - ATTACKING: Estado de ataque, el personaje está ejecutando un ataque
 * 
 * Estos estados determinan qué acciones puede realizar el personaje en cada momento.
 */
enum StateEnum
{
    IDLE,      ///< Estado de reposo - el personaje puede realizar cualquier acción
    JUMPING,   ///< Estado de salto - el personaje está en el aire, acciones limitadas
    ATTACKING  ///< Estado de ataque - el personaje está atacando, no puede saltar
};

/**
 * @class State
 * @brief Clase que mantiene el estado actual de una entidad y su temporizador.
 *
 * @details
 * Esta clase implementa los fundamentos del patrón State, manteniendo
 * el estado actual de una entidad y un temporizador asociado que puede
 * usarse para controlar la duración de cada estado o transiciones automáticas.
 * 
 * La clase es simple pero efectiva para implementar máquinas de estado
 * básicas en juegos donde las entidades tienen comportamientos diferentes
 * según su estado actual.
 */
class State
{
public:
    StateEnum m_CurrentState;  ///< Estado actual de la entidad
    int m_stateTimer;         ///< Temporizador para controlar duración del estado
    
    /**
     * @brief Constructor por defecto.
     * @details Inicializa la entidad en estado IDLE con temporizador en 0.
     * @post m_CurrentState = IDLE, m_stateTimer = 0
     */
    State() : m_CurrentState(IDLE), m_stateTimer(0) {}
    
    /**
     * @brief Obtiene el estado actual.
     * @return El estado actual de la entidad.
     */
    StateEnum GetCurrentState() const { return m_CurrentState; }
    
    /**
     * @brief Establece un nuevo estado.
     * @param newState El nuevo estado a establecer.
     * @post m_CurrentState se actualiza al nuevo estado.
     */
    void SetState(StateEnum newState) { m_CurrentState = newState; }
    
    /**
     * @brief Obtiene el valor actual del temporizador.
     * @return Valor actual del temporizador de estado.
     */
    int GetTimer() const { return m_stateTimer; }
    
    /**
     * @brief Establece el valor del temporizador.
     * @param timer Nuevo valor para el temporizador.
     * @post m_stateTimer se actualiza al nuevo valor.
     */
    void SetTimer(int timer) { m_stateTimer = timer; }
    
    /**
     * @brief Decrementa el temporizador en 1.
     * @post m_stateTimer se reduce en 1 (no baja de valores negativos).
     */
    void DecrementTimer() 
    { 
        if (m_stateTimer > 0) 
            m_stateTimer--; 
    }
};