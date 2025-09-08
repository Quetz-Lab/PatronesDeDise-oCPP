/**
 * @file EventQueue.h
 * @brief Definición de eventos de sonido y cola de eventos.
 *
 * @details
 * Este archivo define:
 * - `SoundID`: identificadores de sonidos básicos.
 * - `SoundEvent`: estructura que encapsula un evento de sonido.
 * - `EventQueue`: clase que actuará como sistema de encolado de eventos.
 *
 * Implementa los fundamentos del patrón Event Queue para el procesamiento
 * asíncrono y diferido de eventos de audio en el sistema de juego.
 *
 * @note Actualmente `EventQueue` está vacío; se espera implementar almacenamiento
 * y despacho de `SoundEvent` en futuras versiones.
 */

#pragma once

/**
 * @enum SoundID
 * @brief Identificadores únicos para sonidos reproducibles.
 *
 * @details
 * Define los diferentes tipos de sonidos que pueden ser reproducidos
 * en el sistema de audio. Cada ID representa un sonido específico
 * que puede ser encolado y procesado por el sistema de audio.
 */
enum class SoundID
{
    HIT,    ///< Sonido de impacto o golpe
    JUMP,   ///< Sonido de salto del personaje
    DEATH   ///< Sonido de muerte o derrota
};

/**
 * @struct SoundEvent
 * @brief Estructura que encapsula un evento de sonido.
 *
 * @details
 * Representa un evento de sonido que puede ser encolado para procesamiento
 * posterior. Contiene el identificador del sonido y operadores de comparación
 * para facilitar la gestión en contenedores y algoritmos.
 * 
 * Esta estructura es fundamental para el patrón Event Queue, permitiendo
 * que los sonidos sean solicitados en un momento y procesados en otro.
 */
struct SoundEvent
{
    SoundID id;  ///< Identificador del sonido a reproducir
    
    /**
     * @brief Operador de igualdad para comparar eventos de sonido.
     * @param other Otro evento de sonido para comparar.
     * @return true si ambos eventos tienen el mismo ID de sonido, false en caso contrario.
     * 
     * @details
     * Permite comparar eventos de sonido basándose únicamente en su ID.
     * Útil para buscar, eliminar o filtrar eventos específicos en colas.
     */
    bool operator==(const SoundEvent& other) const
    {
        return id == other.id;
    }
    
    /**
     * @brief Operador de desigualdad para comparar eventos de sonido.
     * @param other Otro evento de sonido para comparar.
     * @return true si los eventos tienen IDs diferentes, false si son iguales.
     */
    bool operator!=(const SoundEvent& other) const
    {
        return !(*this == other);
    }
};

/**
 * @class EventQueue
 * @brief Clase base para el sistema de cola de eventos.
 *
 * @details
 * Esta clase está diseñada para implementar el patrón Event Queue,
 * que permite el procesamiento asíncrono y diferido de eventos.
 * Actualmente es una clase vacía que sirve como placeholder para
 * futuras implementaciones.
 * 
 * El patrón Event Queue es especialmente útil para:
 * - Desacoplar el momento de solicitud del momento de procesamiento
 * - Evitar saturación del sistema con muchos eventos simultáneos
 * - Permitir procesamiento por lotes de eventos
 * - Controlar el orden y timing de procesamiento
 * 
 * @note Esta clase está actualmente vacía y sirve como base para
 * futuras implementaciones del sistema de cola de eventos.
 * 
 * @todo Implementar métodos para:
 * - Encolar eventos (enqueue)
 * - Desencolar eventos (dequeue)
 * - Procesar cola de eventos (process)
 * - Limpiar cola (clear)
 * - Verificar si la cola está vacía (isEmpty)
 */
class EventQueue
{
public:
    /**
     * @brief Constructor por defecto.
     * @details Inicializa una cola de eventos vacía.
     * @todo Implementar inicialización de estructuras de datos internas.
     */
    EventQueue() = default;
    
    /**
     * @brief Destructor virtual.
     * @details Asegura la destrucción correcta de clases derivadas.
     * @todo Implementar limpieza de eventos pendientes.
     */
    virtual ~EventQueue() = default;
    
    // TODO: Métodos a implementar en futuras versiones:
    // virtual void enqueue(const SoundEvent& event) = 0;
    // virtual SoundEvent dequeue() = 0;
    // virtual void processEvents() = 0;
    // virtual bool isEmpty() const = 0;
    // virtual size_t size() const = 0;
    // virtual void clear() = 0;
};