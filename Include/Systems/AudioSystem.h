/**
 * @file AudioSystem.h
 * @brief Sistema de audio que implementa los patrones Observer y Event Queue.
 *
 * @details
 * Define la clase `AudioSystem` que combina dos patrones de diseño:
 * - Observer: Para reaccionar automáticamente a eventos del personaje
 * - Event Queue: Para procesar sonidos de manera asíncrona y diferida
 * 
 * Este sistema demuestra cómo múltiples patrones pueden trabajar juntos
 * para crear un subsistema robusto y eficiente.
 */

#pragma once

#include <iostream>

#include "EventQueue.h"
#include "Observer.h"

/**
 * @class AudioSystem
 * @brief Sistema de audio que maneja sonidos usando Observer y Event Queue.
 *
 * @details
 * Esta clase implementa un sistema de audio completo que combina dos patrones:
 * 
 * 1. **Patrón Observer**: Permite que el sistema reaccione automáticamente
 *    a eventos del personaje (como recibir daño) reproduciendo sonidos apropiados.
 * 
 * 2. **Patrón Event Queue**: Permite encolar solicitudes de sonido para
 *    procesamiento posterior, evitando saturación del sistema y permitiendo
 *    control sobre cuándo y cómo se procesan los sonidos.
 * 
 * El sistema está diseñado para ser:
 * - Eficiente: Procesa sonidos por lotes para mejor rendimiento
 * - Desacoplado: No bloquea la lógica principal del juego
 * - Escalable: Puede manejar múltiples sonidos simultáneos
 * - Controlado: Limita el número de sonidos pendientes para evitar saturación
 * 
 * @note Hereda de Observer para recibir notificaciones automáticas del personaje.
 */
class AudioSystem : public Observer
{
public:
    static const int MAX_PENDING = 16;  ///< Número máximo de sonidos en cola
    
    SoundID pendingSounds[MAX_PENDING];  ///< Cola de sonidos pendientes
    int pendingCount;                    ///< Número actual de sonidos en cola
    
    /**
     * @brief Constructor por defecto.
     * @details Inicializa el sistema de audio con la cola vacía.
     * @post pendingCount = 0, sistema listo para recibir solicitudes de sonido.
     */
    AudioSystem();
    
    /**
     * @brief Destructor.
     * @details Limpia recursos del sistema de audio.
     * @note Procesa cualquier sonido pendiente antes de destruir el objeto.
     */
    ~AudioSystem();
    
    /**
     * @brief Solicita la reproducción de un sonido (patrón Event Queue).
     * @param event Evento de sonido que contiene el ID del sonido a reproducir.
     * 
     * @details
     * Encola el sonido para procesamiento posterior en lugar de reproducirlo
     * inmediatamente. Esto permite:
     * - Evitar saturación del sistema de audio
     * - Procesar sonidos por lotes para mejor rendimiento
     * - Controlar el timing de reproducción de sonidos
     * 
     * @pre pendingCount < MAX_PENDING
     * @post Si hay espacio, el sonido se agrega a la cola pendiente.
     * @warning Si la cola está llena, el sonido se descarta silenciosamente.
     */
    void RequestSound(SoundEvent event);
    
    /**
     * @brief Procesa todos los sonidos encolados (patrón Event Queue).
     * 
     * @details
     * Procesa todos los sonidos en la cola pendiente, reproduciéndolos
     * según su tipo. Después de procesar, limpia la cola para el siguiente
     * frame. Este método típicamente se llama una vez por frame del juego.
     * 
     * Sonidos soportados:
     * - SoundID::HIT: Sonido de impacto
     * - SoundID::JUMP: Sonido de salto
     * - SoundID::DEATH: Sonido de muerte
     * 
     * @post La cola de sonidos pendientes queda vacía (pendingCount = 0).
     */
    void processEvents();
    
    /**
     * @brief Maneja las notificaciones de eventos del personaje (patrón Observer).
     * @param character Referencia constante al personaje que generó el evento.
     * @param event Tipo de evento que ocurrió.
     * 
     * @details
     * Este método es llamado automáticamente cuando el personaje genera
     * un evento. Reproduce sonidos apropiados basados en el tipo de evento.
     * 
     * A diferencia de RequestSound(), este método reproduce sonidos
     * inmediatamente (procesamiento síncrono) para eventos críticos
     * que requieren feedback audio instantáneo.
     * 
     * Eventos manejados:
     * - Event::Character_Get_Damage: Reproduce sonido de daño
     * 
     * @post Se reproduce el sonido apropiado para el evento.
     * 
     * @note Este método override la implementación pura virtual de Observer.
     */
    virtual void OnNotify(const Character& character, Event event) override
    {
        // Implementación específica para el sistema de audio
        switch (event)
        {
            case Event::Character_Get_Damage:
                std::cout << "Reproduciendo sonido de daño al personaje." << std::endl;
                // En una implementación real, aquí se reproduciría el sonido actual
                break;
                
            // TODO: Agregar más casos para otros eventos
            // case Event::Character_Jump:
            //     std::cout << "Reproduciendo sonido de salto." << std::endl;
            //     break;
            // case Event::Character_Shoot:
            //     std::cout << "Reproduciendo sonido de disparo." << std::endl;
            //     break;
                
            default:
                // Evento no manejado por el sistema de audio
                break;
        }
    }
    
    // TODO: Métodos adicionales para futuras versiones:
    // void SetVolume(float volume);
    // float GetVolume() const;
    // void PauseAll();
    // void ResumeAll();
    // bool IsPlaying(SoundID soundId) const;
    // void StopSound(SoundID soundId);
    // void StopAll();
};