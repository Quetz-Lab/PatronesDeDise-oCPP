#pragma once


#include <iostream>

#include "../Patterns/Observer.h"
 /**
  * @class Character
  * @brief Entidad jugable/NPJ con estad�sticas y notificaci�n de eventos.
  *
  * @details
  * Mantiene hasta `MaxObservers` observadores registrados. Cuando ocurre una acci�n
  * (p. ej., salto, disparo, da�o) se invoca `Notify(Event)` para informar a los
  * observadores suscritos.
  */

class Character
{
public:
    /**
     * @brief Constructor completo.
     * @param health Salud inicial (0..maxHealth).
     * @param maxHealth Salud máxima (> 0).
     * @param speed Velocidad de movimiento (>= 0).
     * @param damage Daño base por ataque (>= 0).
     * @param jumpHeight Altura de salto (>= 0).
     * @param NumObservers Número inicial de espacios para observadores.
     */
    Character(float health, float maxHealth, float speed, int damage, float jumpHeight, 
              int NumObservers);
    
    /**
     * @brief Constructor por defecto.
     * @details Inicializa con valores seguros.
     */
    Character();
    
    /**
     * @brief Destructor.
     * @details No destruye observadores externos; solo limpia referencias internas.
     */
    ~Character();


    // ===========================
    // Acciones del personaje
    // ===========================
    
    /**
     * @brief Ejecuta la acción de salto.
     * @post Puede disparar una notificación `Event::Jump`.
     */
    void Jump();
    
    /**
     * @brief Ejecuta la acción de disparo.
     * @post Puede disparar una notificación `Event::Shoot`.
     */
    void Shoot();
    
    /**
     * @brief Ejecuta la acción de agacharse.
     * @post Puede disparar una notificación `Event::Crouch`.
     */
    void Crouch();
    
    /**
     * @brief Utilidad de depuración para simular recepción de daño.
     * @post Puede reducir salud y notificar `Event::Damaged`.
     * @warning Solo para depuración; evitar en builds de producción.
     */
    void DebugGetDamage();


	// ===========================
// Getters y Setters
// ===========================

	float GetHealth();
	void SetHealth(float health);
	float GetSpeed();
	void SetSpeed(float speed);
	int GetDamage();
	void SetDamage(int damage);
	float GetMaxHealth();
	void SetMaxHealth(float maxHealth);
	float GetJumpHeight();
	void SetJumpHeigth(float jumpHeight);
	int GetNumObservers(int NumObservers);
	

    // ===========================
    // Sistema Observer
    // ===========================
    
    /**
     * @brief Agrega un observador para recibir eventos del personaje.
     * @param observer Puntero válido a `Observer` (no se toma ownership).
     * @pre `observer != nullptr`
     * @post Si hay espacio, el observador quedará registrado.
     */
    void addObserver(Observer* observer);

    // ===========================
    // Getters y Setters
    // ===========================
    
    /**
     * @brief Obtiene la salud actual del personaje.
     * @return Valor actual de salud (0.0 a maxHealth).
     */
    float GetHealth();
    
    /**
     * @brief Establece la salud del personaje.
     * @param health Nueva cantidad de salud (debe ser >= 0).
     * @pre health >= 0
     * @post La salud del personaje se actualiza al valor especificado.
     */
    void SetHealth(float health);
    
    /**
     * @brief Obtiene la velocidad actual del personaje.
     * @return Velocidad de movimiento actual.
     */
    float GetSpeed();
    
    /**
     * @brief Establece la velocidad del personaje.
     * @param speed Nueva velocidad de movimiento (debe ser >= 0).
     * @pre speed >= 0
     * @post La velocidad del personaje se actualiza al valor especificado.
     */
    void SetSpeed(float speed);
    
    /**
     * @brief Obtiene el daño base del personaje y notifica a observadores.
     * @return Cantidad de daño que puede infligir el personaje.
     * @post Notifica evento Character_Get_Damage a todos los observadores.
     */
    int GetDamage();
    
    /**
     * @brief Establece el daño base del personaje.
     * @param damage Nueva cantidad de daño (debe ser >= 0).
     * @pre damage >= 0
     * @post El daño del personaje se actualiza al valor especificado.
     */
    void SetDamage(int damage);
    
    /**
     * @brief Obtiene la salud máxima del personaje.
     * @return Valor máximo de salud que puede tener el personaje.
     */
    float GetMaxHealth();
    
    /**
     * @brief Establece la salud máxima del personaje.
     * @param maxHealth Nueva salud máxima (debe ser > 0).
     * @pre maxHealth > 0
     * @post La salud máxima se actualiza al valor especificado.
     */
    void SetMaxHealth(float maxHealth);
    
    /**
     * @brief Obtiene la altura de salto del personaje.
     * @return Altura máxima de salto del personaje.
     */
    float GetJumpHeight();
    
    /**
     * @brief Establece la altura de salto del personaje.
     * @param jumpHeight Nueva altura de salto (debe ser >= 0).
     * @pre jumpHeight >= 0
     * @post La altura de salto se actualiza al valor especificado.
     * @note Nombre del método conserva typo por compatibilidad.
     */
    void SetJumpHeigth(float jumpHeight);  // Note: typo preserved for compatibility
    
    /**
     * @brief Obtiene el número de observadores registrados.
     * @param NumObservers Parámetro no utilizado (legacy).
     * @return Número actual de observadores registrados.
     * @warning Este método tiene una firma inconsistente por razones de compatibilidad.
     */
    int GetNumObservers(int NumObservers);


private:
    static const int MaxObservers = 10;
    Observer* observers[MaxObservers];
    int m_numObservers;
    
    // Estadísticas del personaje
    float _health;
    float _speed;
    int _damage;
    float _maxHealth;
    float _jumpheight;
    
    /**
     * @brief Notifica a todos los observadores registrados.
     * @param event Evento a notificar.
     */
    void Notify(Event event);
};

