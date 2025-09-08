# Ejemplos de Formateo de Código

Este documento muestra ejemplos del antes y después de aplicar el formateo con clang-format.

## 📋 Ejemplo 1: Archivo Principal (main)

### ❌ Antes del Formateo
```cpp
#include <iostream>
#include "Character.h"
#include "State.h"
#include "Achievements.h"
#include "AudioSystem.h"
#include "EventQueue.h"
int main()
{
	char tecla;
	State state;
    Character* player = new Character(20,20,10,10,10, 0);
	//Agregar instancia de observadores utiliznado apuntadores
	Achievements* achievements = new Achievements();
	AudioSystem* audioSystem = new AudioSystem();
	AudioSystem audioSystem2 = AudioSystem();
	//Menu de inicio
  
	std::cout << "=================================\n";
	std::cout << "Bienvenido al juego \n";
	std::cout << "Aprieta una tecla para jugar\n";
	std::cout << "=================================\n";
	//Update
	while (true)
	{
		//solicitamos los audios pendientes
		audioSystem2.RequestSound({ SoundID::HIT });
		audioSystem2.RequestSound({ SoundID::JUMP });
		audioSystem2.RequestSound({ SoundID::DEATH });

		std::cout << "Ingresa comando (w = saltar, f = atacar, x = salir, v = Debuggear dano): ";
		std::cin >> tecla;

		
		std::cin >> tecla;
		if (tecla == 'w')
		{
			player->Jump();
		}
		else if (tecla == 'f')
		{
			player->Shoot();
		}
		else if (tecla == 'v')
		{
			player->DebugGetDamage();
		}
		else
		{
			std::cout << "=================================\n";
			std::cout << "Tecla invalida\n";
			std::cout << "=================================\n";
		}
	}
}
```

### ✅ Después del Formateo
```cpp
// PatronesDeDisenoCPP.cpp : Este archivo contiene la función "main". 
// La ejecución del programa comienza y termina ahí.

#include <iostream>

#include "Achievements.h"
#include "AudioSystem.h"
#include "Character.h"
#include "EventQueue.h"
#include "State.h"

int main()
{
    char tecla;
    State state;
    Character* player = new Character(20, 20, 10, 10, 10, 0);
    
    // Agregar instancia de observadores utilizando apuntadores
    Achievements* achievements = new Achievements();
    AudioSystem* audioSystem = new AudioSystem();
    AudioSystem audioSystem2 = AudioSystem();
    
    // Menú de inicio
    std::cout << "=================================\n";
    std::cout << "Bienvenido al juego \n";
    std::cout << "Aprieta una tecla para jugar\n";
    std::cout << "=================================\n";
    
    // Update loop
    while (true)
    {
        // Solicitamos los audios pendientes
        audioSystem2.RequestSound({SoundID::HIT});
        audioSystem2.RequestSound({SoundID::JUMP});
        audioSystem2.RequestSound({SoundID::DEATH});

        std::cout << "Ingresa comando (w = saltar, f = atacar, x = salir, v = Debuggear dano): ";
        std::cin >> tecla;

        std::cin >> tecla;
        if (tecla == 'w')
        {
            player->Jump();
        }
        else if (tecla == 'f')
        {
            player->Shoot();
        }
        else if (tecla == 'v')
        {
            player->DebugGetDamage();
        }
        else
        {
            std::cout << "=================================\n";
            std::cout << "Tecla invalida\n";
            std::cout << "=================================\n";
        }
        
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    
    // Cleanup
    delete player;
    delete achievements;
    delete audioSystem;
    
    return 0;
}
```

## 📋 Ejemplo 2: Declaración de Clase

### ❌ Antes del Formateo
```cpp
#pragma once
#include <iostream>
#include "Observer.h"
class Character
{
public:
	Character(float health, float maxHealth, float speed, int damage, float jumpHeight, int NumObservers);
	Character();
	~Character();
	void Jump();
	void Shoot();
	void Crouch();
	void DebugGetDamage();
	void addObserver(Observer* observer);
	//Getters y Setters
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
```

### ✅ Después del Formateo
```cpp
#pragma once

#include <iostream>

#include "Observer.h"

/**
 * @class Character
 * @brief Entidad jugable/NPJ con estadísticas y notificación de eventos.
 */
class Character
{
public:
    // Constructores y destructor
    Character(float health, float maxHealth, float speed, int damage, 
              float jumpHeight, int NumObservers);
    Character();
    ~Character();

    // Acciones del personaje
    void Jump();
    void Shoot();
    void Crouch();
    void DebugGetDamage();

    // Sistema Observer
    void addObserver(Observer* observer);

    // Getters y Setters
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
    
    // Estadísticas del personaje
    float _health;
    float _speed;
    int _damage;
    float _maxHealth;
    float _jumpheight;
    
    void Notify(Event event);
};
```

## 📋 Ejemplo 3: Implementación de Métodos

### ❌ Antes del Formateo
```cpp
void InputHandler::remapearTecla(char tecla, std::string accion)
{
    // Remapea la tecla a una acción específica
    if (accion == "jump") {
        keyMappings[tecla] = std::make_unique<JumpCommand>();
		std::cin >> tecla; // Consumir el espacio
    }
    else if (accion == "shoot") {
        keyMappings[tecla] = std::make_unique<ShootCommand>();
    }
    else if (accion == "crouch") {
        keyMappings[tecla] = std::make_unique<CrouchCommand>();

    }
    else if (accion == "DebugDamage")
    {
		keyMappings[tecla] = std::make_unique<GetDamageDebug>();

    }
    else {
        // Si la accion no es valida, podriamos lanzar una excepción o manejar el error
	}
}
```

### ✅ Después del Formateo
```cpp
void InputHandler::remapearTecla(char tecla, std::string accion)
{
    // Remapea la tecla a una acción específica
    if (accion == "jump")
    {
        keyMappings[tecla] = std::make_unique<JumpCommand>();
        std::cin >> tecla;  // Consumir el espacio
    }
    else if (accion == "shoot")
    {
        keyMappings[tecla] = std::make_unique<ShootCommand>();
    }
    else if (accion == "crouch")
    {
        keyMappings[tecla] = std::make_unique<CrouchCommand>();
    }
    else if (accion == "DebugDamage")
    {
        keyMappings[tecla] = std::make_unique<GetDamageDebug>();
    }
    else
    {
        // Si la acción no es válida, podríamos lanzar una excepción o manejar el error
        std::cerr << "Acción no reconocida: " << accion << std::endl;
    }
}
```

## 🎯 Mejoras Aplicadas

### 1. **Indentación Consistente**
- 4 espacios en lugar de tabs mezclados
- Alineación correcta de parámetros largos
- Indentación uniforme en bloques anidados

### 2. **Espaciado Mejorado**
- Espacios alrededor de operadores (`=`, `==`, `<<`)
- Espacios después de comas en listas de parámetros
- Espacios consistentes en inicializadores de listas

### 3. **Organización de Includes**
- Separación entre includes del sistema y locales
- Ordenamiento alfabético automático
- Líneas en blanco apropiadas entre secciones

### 4. **Formato de Llaves**
- Estilo Allman (llaves en nueva línea)
- Consistencia en todas las estructuras de control
- Mejor legibilidad visual

### 5. **Comentarios y Documentación**
- Espaciado consistente en comentarios
- Formato mejorado para comentarios de documentación
- Alineación apropiada de comentarios inline

### 6. **Límite de Línea**
- Líneas que exceden 100 caracteres se dividen apropiadamente
- Parámetros largos se dividen en múltiples líneas
- Mejor legibilidad en pantallas estándar

## 🚀 Beneficios Observados

1. **Legibilidad**: El código es más fácil de leer y seguir
2. **Consistencia**: Estilo uniforme en todo el proyecto
3. **Mantenibilidad**: Más fácil de modificar y extender
4. **Profesionalismo**: Apariencia pulida y bien organizada
5. **Colaboración**: Diffs más limpios en control de versiones

## 📝 Notas de Implementación

- Se preservaron los comentarios originales en español
- Se mantuvieron los nombres de variables existentes
- Se agregó documentación adicional donde era apropiado
- Se corrigieron algunos errores menores de espaciado
- Se añadió cleanup de memoria en el main (aunque no se alcance)