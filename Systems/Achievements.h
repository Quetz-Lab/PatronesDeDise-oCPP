/**
 * @file Achievements.h
 * @brief Sistema de logros que implementa el patrón Observer.
 *
 * @details
 * Define la clase `Achievements` que actúa como observador de eventos
 * del personaje para desbloquear y notificar logros basados en las
 * acciones realizadas durante el juego.
 * 
 * Este sistema demuestra cómo el patrón Observer puede ser utilizado
 * para implementar sistemas de gamificación desacoplados del gameplay principal.
 */

#pragma once

#include <iostream>

#include "../Patterns/Observer.h"

/**
 * @class Achievements
 * @brief Sistema de logros que observa eventos del personaje.
 *
 * @details
 * Esta clase implementa el patrón Observer para crear un sistema de logros
 * que reacciona automáticamente a eventos específicos del personaje.
 * Cuando el personaje realiza ciertas acciones (como recibir daño), el
 * sistema evalúa si se debe desbloquear algún logro y notifica al jugador.
 * 
 * El sistema está diseñado para ser:
 * - Desacoplado: No afecta la lógica principal del juego
 * - Extensible: Fácil agregar nuevos logros y condiciones
 * - Reactivo: Responde inmediatamente a eventos del personaje
 * 
 * @note Hereda de Observer para recibir notificaciones automáticas.
 */
class Achievements : public Observer
{
public:
    /**
     * @brief Constructor por defecto.
     * @details Inicializa el sistema de logros sin logros desbloqueados.
     * @post El sistema está listo para recibir notificaciones de eventos.
     */
    Achievements() {}
    
    /**
     * @brief Destructor.
     * @details Limpia recursos del sistema de logros.
     * @note No requiere limpieza especial en esta implementación básica.
     */
    ~Achievements() {}
    
    /**
     * @brief Maneja las notificaciones de eventos del personaje.
     * @param character Referencia constante al personaje que generó el evento.
     * @param event Tipo de evento que ocurrió.
     * 
     * @details
     * Este método es llamado automáticamente cuando el personaje genera
     * un evento. Evalúa el tipo de evento y determina si se debe desbloquear
     * algún logro específico.
     * 
     * Eventos manejados actualmente:
     * - Event::Character_Get_Damage: Desbloquea el logro "Primer Golpe"
     * 
     * @post Si se cumple una condición de logro, se muestra una notificación.
     * 
     * @note Este método override la implementación pura virtual de Observer.
     */
    virtual void OnNotify(const Character& character, Event event) override
    {
        // Implementación específica para logros
        switch (event)
        {
            case Event::Character_Get_Damage:
                // Logro por recibir daño por primera vez
                std::cout << "¡Logro desbloqueado 'Primer Golpe'!" << std::endl;
                break;
                
            // TODO: Agregar más casos para otros eventos y logros
            // case Event::Character_Jump:
            //     std::cout << "¡Logro desbloqueado 'Saltarín'!" << std::endl;
            //     break;
            // case Event::Character_Shoot:
            //     std::cout << "¡Logro desbloqueado 'Primer Disparo'!" << std::endl;
            //     break;
                
            default:
                // Evento no manejado por el sistema de logros
                break;
        }
    }
    
    // TODO: Métodos adicionales para futuras versiones:
    // bool IsAchievementUnlocked(const std::string& achievementId) const;
    // void UnlockAchievement(const std::string& achievementId);
    // std::vector<std::string> GetUnlockedAchievements() const;
    // void SaveAchievements() const;
    // void LoadAchievements();
};