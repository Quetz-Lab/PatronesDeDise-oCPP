#pragma once
/**
 * @file Character.h
 * @brief Declaración de la clase Character con patrón Observer y acciones básicas.
 *
 * @details
 * La clase `Character` modela un personaje con estadísticas (salud, velocidad, daño, salto)
 * e integra un sistema de observadores para notificar eventos del juego (`Event`).
 * Expone acciones como saltar, disparar y agacharse, además de getters/setters.
 *
 * @note Requiere `Observer.h` que define `Observer` y el tipo `Event`.
 * @warning Este archivo conserva intencionalmente dos posibles issues de API:
 * - `int GetNumObservers(int NumObservers)` recibe un parámetro innecesario.
 * - `SetJumpHeigth` está mal escrito (debería ser `SetJumpHeight`).
 * Considera corregirlos en una versión posterior con deprecaciones.
 */

#include <iostream>
#include "Observer.h"
 /**
  * @class Character
  * @brief Entidad jugable/NPJ con estadísticas y notificación de eventos.
  *
  * @details
  * Mantiene hasta `MaxObservers` observadores registrados. Cuando ocurre una acción
  * (p. ej., salto, disparo, daño) se invoca `Notify(Event)` para informar a los
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
	 * @param NumObservers Número inicial de espacios para observadores (se limita a MaxObservers).
	 *
	 * @pre maxHealth > 0
	 * @post `GetHealth() <= GetMaxHealth()`
	 * @note Los observadores reales se agregan con `addObserver`.
	 */
	Character(float health, float maxHealth, float speed, int damage, float jumpHeight, int NumObservers);
	/**
	* @brief Constructor por defecto.
	* @details Inicializa con valores seguros (p. ej. 0 o mínimos razonables).
	*/
	Character();
	/**
	* @brief Destructor.
	* @details No destruye observadores externos; solo limpia referencias internas.
	*/
	~Character();
	/**
   * @brief Ejecuta la acción de salto.
   * @post Puede disparar una notificación `Event::Jump` (según implementación).
   */
	void Jump();
	/**
		* @brief Ejecuta la acción de disparo.
		* @post Puede disparar una notificación `Event::Shoot` (según implementación).
		*/
	void Shoot();
	/**
  * @brief Ejecuta la acción de agacharse.
  * @post Puede disparar una notificación `Event::Crouch` (según implementación).
  */
	void Crouch();
	/**
	 * @brief Utilidad de depuración para simular recepción de daño.
	 * @post Puede reducir salud y notificar `Event::Damaged`.
	 * @warning Solo para depuración; evitar en builds de producción.
	 */
	void DebugGetDamage();
	/**
 * @brief Agrega un observador para recibir eventos del personaje.
 * @param observer Puntero válido a `Observer` (no se toma ownership).
 * @return void
 * @pre `observer != nullptr`
 * @post Si hay espacio, el observador quedará registrado y recibirá futuras notificaciones.
 * @warning Capado por `MaxObservers`; observadores duplicados pueden ser ignorados según implementación.
 */

	void addObserver(Observer* observer);


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
	

private:
	static const int MaxObservers = 10;
	Observer* observers[MaxObservers];
	int m_numObservers;
	float _health;
	float _speed;
	int _damage;
	float _maxHealth;
	float _jumpheight;
	void Notify(Event event);
};

