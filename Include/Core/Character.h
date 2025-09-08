#pragma once
<<<<<<< Updated upstream
/**
 * @file Character.h
 * @brief DeclaraciÛn de la clase Character con patrÛn Observer y acciones b·sicas.
 *
 * @details
 * La clase `Character` modela un personaje con estadÌsticas (salud, velocidad, daÒo, salto)
 * e integra un sistema de observadores para notificar eventos del juego (`Event`).
 * Expone acciones como saltar, disparar y agacharse, adem·s de getters/setters.
 *
 * @note Requiere `Observer.h` que define `Observer` y el tipo `Event`.
 * @warning Este archivo conserva intencionalmente dos posibles issues de API:
 * - `int GetNumObservers(int NumObservers)` recibe un par·metro innecesario.
 * - `SetJumpHeigth` est· mal escrito (deberÌa ser `SetJumpHeight`).
 * Considera corregirlos en una versiÛn posterior con deprecaciones.
 */
=======
>>>>>>> Stashed changes

#include <iostream>

#include "Observer.h"
<<<<<<< Updated upstream
 /**
  * @class Character
  * @brief Entidad jugable/NPJ con estadÌsticas y notificaciÛn de eventos.
  *
  * @details
  * Mantiene hasta `MaxObservers` observadores registrados. Cuando ocurre una acciÛn
  * (p. ej., salto, disparo, daÒo) se invoca `Notify(Event)` para informar a los
  * observadores suscritos.
  */
class Character
{
public:
	/**
	 * @brief Constructor completo.
	 * @param health Salud inicial (0..maxHealth).
	 * @param maxHealth Salud m·xima (> 0).
	 * @param speed Velocidad de movimiento (>= 0).
	 * @param damage DaÒo base por ataque (>= 0).
	 * @param jumpHeight Altura de salto (>= 0).
	 * @param NumObservers N˙mero inicial de espacios para observadores (se limita a MaxObservers).
	 *
	 * @pre maxHealth > 0
	 * @post `GetHealth() <= GetMaxHealth()`
	 * @note Los observadores reales se agregan con `addObserver`.
	 */
	Character(float health, float maxHealth, float speed, int damage, float jumpHeight, int NumObservers);
	/**
	* @brief Constructor por defecto.
	* @details Inicializa con valores seguros (p. ej. 0 o mÌnimos razonables).
	*/
	Character();
	/**
	* @brief Destructor.
	* @details No destruye observadores externos; solo limpia referencias internas.
	*/
	~Character();
	/**
   * @brief Ejecuta la acciÛn de salto.
   * @post Puede disparar una notificaciÛn `Event::Jump` (seg˙n implementaciÛn).
   */
	void Jump();
	/**
		* @brief Ejecuta la acciÛn de disparo.
		* @post Puede disparar una notificaciÛn `Event::Shoot` (seg˙n implementaciÛn).
		*/
	void Shoot();
	/**
  * @brief Ejecuta la acciÛn de agacharse.
  * @post Puede disparar una notificaciÛn `Event::Crouch` (seg˙n implementaciÛn).
  */
	void Crouch();
	/**
	 * @brief Utilidad de depuraciÛn para simular recepciÛn de daÒo.
	 * @post Puede reducir salud y notificar `Event::Damaged`.
	 * @warning Solo para depuraciÛn; evitar en builds de producciÛn.
	 */
	void DebugGetDamage();
	/**
 * @brief Agrega un observador para recibir eventos del personaje.
 * @param observer Puntero v·lido a `Observer` (no se toma ownership).
 * @return void
 * @pre `observer != nullptr`
 * @post Si hay espacio, el observador quedar· registrado y recibir· futuras notificaciones.
 * @warning Capado por `MaxObservers`; observadores duplicados pueden ser ignorados seg˙n implementaciÛn.
 */

	void addObserver(Observer* observer);
=======

/**
 * @file Character.h
 * @brief Declaraci√≥n de la clase Character con patr√≥n Observer y acciones b√°sicas.
 *
 * @details
 * La clase `Character` modela un personaje con estad√≠sticas (salud, velocidad, da√±o, salto)
 * e integra un sistema de observadores para notificar eventos del juego (`Event`).
 * Expone acciones como saltar, disparar y agacharse, adem√°s de getters/setters.
 *
 * @note Requiere `Observer.h` que define `Observer` y el tipo `Event`.
 */

/**
 * @class Character
 * @brief Entidad jugable/NPJ con estad√≠sticas y notificaci√≥n de eventos.
 *
 * @details
 * Mantiene hasta `MaxObservers` observadores registrados. Cuando ocurre una acci√≥n
 * (p. ej., salto, disparo, da√±o) se invoca `Notify(Event)` para informar a los
 * observadores suscritos.
 */
class Character
{
public:
    /**
     * @brief Constructor completo.
     * @param health Salud inicial (0..maxHealth).
     * @param maxHealth Salud m√°xima (> 0).
     * @param speed Velocidad de movimiento (>= 0).
     * @param damage Da√±o base por ataque (>= 0).
     * @param jumpHeight Altura de salto (>= 0).
     * @param NumObservers N√∫mero inicial de espacios para observadores.
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
>>>>>>> Stashed changes

    // ===========================
    // Acciones del personaje
    // ===========================
    
    /**
     * @brief Ejecuta la acci√≥n de salto.
     * @post Puede disparar una notificaci√≥n `Event::Jump`.
     */
    void Jump();
    
    /**
     * @brief Ejecuta la acci√≥n de disparo.
     * @post Puede disparar una notificaci√≥n `Event::Shoot`.
     */
    void Shoot();
    
    /**
     * @brief Ejecuta la acci√≥n de agacharse.
     * @post Puede disparar una notificaci√≥n `Event::Crouch`.
     */
    void Crouch();
    
    /**
     * @brief Utilidad de depuraci√≥n para simular recepci√≥n de da√±o.
     * @post Puede reducir salud y notificar `Event::Damaged`.
     * @warning Solo para depuraci√≥n; evitar en builds de producci√≥n.
     */
    void DebugGetDamage();

<<<<<<< Updated upstream
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
	
=======
    // ===========================
    // Sistema Observer
    // ===========================
    
    /**
     * @brief Agrega un observador para recibir eventos del personaje.
     * @param observer Puntero v√°lido a `Observer` (no se toma ownership).
     * @pre `observer != nullptr`
     * @post Si hay espacio, el observador quedar√° registrado.
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
     * @brief Obtiene el da√±o base del personaje y notifica a observadores.
     * @return Cantidad de da√±o que puede infligir el personaje.
     * @post Notifica evento Character_Get_Damage a todos los observadores.
     */
    int GetDamage();
    
    /**
     * @brief Establece el da√±o base del personaje.
     * @param damage Nueva cantidad de da√±o (debe ser >= 0).
     * @pre damage >= 0
     * @post El da√±o del personaje se actualiza al valor especificado.
     */
    void SetDamage(int damage);
    
    /**
     * @brief Obtiene la salud m√°xima del personaje.
     * @return Valor m√°ximo de salud que puede tener el personaje.
     */
    float GetMaxHealth();
    
    /**
     * @brief Establece la salud m√°xima del personaje.
     * @param maxHealth Nueva salud m√°xima (debe ser > 0).
     * @pre maxHealth > 0
     * @post La salud m√°xima se actualiza al valor especificado.
     */
    void SetMaxHealth(float maxHealth);
    
    /**
     * @brief Obtiene la altura de salto del personaje.
     * @return Altura m√°xima de salto del personaje.
     */
    float GetJumpHeight();
    
    /**
     * @brief Establece la altura de salto del personaje.
     * @param jumpHeight Nueva altura de salto (debe ser >= 0).
     * @pre jumpHeight >= 0
     * @post La altura de salto se actualiza al valor especificado.
     * @note Nombre del m√©todo conserva typo por compatibilidad.
     */
    void SetJumpHeigth(float jumpHeight);  // Note: typo preserved for compatibility
    
    /**
     * @brief Obtiene el n√∫mero de observadores registrados.
     * @param NumObservers Par√°metro no utilizado (legacy).
     * @return N√∫mero actual de observadores registrados.
     * @warning Este m√©todo tiene una firma inconsistente por razones de compatibilidad.
     */
    int GetNumObservers(int NumObservers);
>>>>>>> Stashed changes

private:
    static const int MaxObservers = 10;
    Observer* observers[MaxObservers];
    int m_numObservers;
    
    // Estad√≠sticas del personaje
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

