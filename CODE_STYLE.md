# Guía de Estilo de Código - Patrones de Diseño C++

## 🎯 Objetivo

Este proyecto mantiene un estilo de código consistente y profesional utilizando **clang-format** para garantizar legibilidad, mantenibilidad y colaboración efectiva.

## 📐 Estándares de Formateo

### Configuración Base
- **Estilo**: Google modificado con Allman braces
- **Estándar C++**: C++17
- **Indentación**: 4 espacios (sin tabs)
- **Límite de línea**: 100 caracteres
- **Codificación**: UTF-8

### Reglas Específicas

#### 1. **Llaves y Bloques**
```cpp
// ✅ Correcto - Estilo Allman
if (condition)
{
    DoSomething();
}

class MyClass
{
public:
    void Method()
    {
        // código aquí
    }
};

// ❌ Incorrecto
if (condition) {
    DoSomething();
}
```

#### 2. **Indentación**
```cpp
// ✅ Correcto - 4 espacios
class Character
{
public:
    Character(float health, float maxHealth, float speed, 
              int damage, float jumpHeight, int numObservers);
    
private:
    static const int MaxObservers = 10;
    Observer* observers[MaxObservers];
    int m_numObservers;
};
```

#### 3. **Espaciado**
```cpp
// ✅ Correcto
int result = a + b * c;
if (x == y)
{
    Function(param1, param2, param3);
}

// ❌ Incorrecto
int result=a+b*c;
if(x==y)
{
    Function(param1,param2,param3);
}
```

#### 4. **Punteros y Referencias**
```cpp
// ✅ Correcto - Alineación a la izquierda
int* pointer;
const std::string& reference;
Observer* observer;

// ❌ Incorrecto
int *pointer;
int * pointer;
```

#### 5. **Includes**
```cpp
// ✅ Correcto - Ordenados y agrupados
#include <iostream>
#include <memory>
#include <string>

#include "Character.h"
#include "Observer.h"

// ❌ Incorrecto - Desordenados
#include "Observer.h"
#include <iostream>
#include "Character.h"
#include <string>
```

#### 6. **Comentarios**
```cpp
// ✅ Correcto - Espaciado consistente
/**
 * @brief Descripción breve del método.
 * @param parameter Descripción del parámetro.
 * @return Descripción del valor de retorno.
 */
void Method(int parameter);

// Comentario de línea con espacio
int variable = 0;  // Comentario inline con 2 espacios

// ❌ Incorrecto
/*Comentario sin espacios*/
int variable=0;//Sin espacios
```

## 🔧 Herramientas y Configuración

### Archivos de Configuración
- **`.clang-format`**: Configuración principal de formateo
- **`format_code.ps1`**: Script de PowerShell para formateo automático
- **`FORMATTING.md`**: Guía detallada de instalación y uso

### Comandos Esenciales
```bash
# Formatear archivo específico
clang-format -i src/PatronesDeDisenoCPP.cpp

# Formatear todo el proyecto
.\format_code.ps1

# Verificar formateo sin aplicar cambios
clang-format --dry-run --Werror src/*.cpp
```

## 📋 Convenciones de Nomenclatura

### Clases y Estructuras
```cpp
// ✅ PascalCase
class Character { };
struct SoundEvent { };
enum class StateEnum { };
```

### Métodos y Funciones
```cpp
// ✅ PascalCase para métodos públicos
void Jump();
void GetHealth();
void SetDamage(int damage);

// ✅ camelCase para funciones privadas/internas
void notify(Event event);
void processInput();
```

### Variables
```cpp
// ✅ Miembros privados con prefijo underscore
class Character
{
private:
    float _health;
    int _damage;
    float _maxHealth;
};

// ✅ Variables locales en camelCase
int playerHealth = 100;
bool isJumping = false;

// ✅ Constantes en UPPER_CASE
static const int MAX_OBSERVERS = 10;
```

### Enumeraciones
```cpp
// ✅ Enum class con PascalCase
enum class SoundID
{
    HIT,
    JUMP,
    DEATH
};

enum StateEnum
{
    IDLE,
    JUMPING,
    ATTACKING
};
```

## 🎨 Patrones de Código Recomendados

### 1. **Inicialización de Constructores**
```cpp
// ✅ Lista de inicialización con formato claro
Character::Character(float health, float maxHealth, float speed, int damage, 
                     float jumpHeight, int numObservers)
    : _health(health)
    , _maxHealth(maxHealth)
    , _speed(speed)
    , _damage(damage)
    , _jumpheight(jumpHeight)
    , m_numObservers(numObservers)
{
    // Cuerpo del constructor
}
```

### 2. **Manejo de Punteros Inteligentes**
```cpp
// ✅ Uso de smart pointers cuando sea apropiado
std::unique_ptr<Command> command = std::make_unique<JumpCommand>();
std::shared_ptr<Observer> observer = std::make_shared<AudioSystem>();
```

### 3. **Documentación de Métodos**
```cpp
/**
 * @brief Agrega un observador al sistema de notificaciones.
 * @param observer Puntero válido al observador (no se toma ownership).
 * @pre observer != nullptr
 * @post El observador será notificado de futuros eventos.
 * @warning Limitado por MaxObservers.
 */
void addObserver(Observer* observer);
```

## 🚨 Errores Comunes a Evitar

### 1. **Inconsistencia en Espaciado**
```cpp
// ❌ Evitar
if(condition){DoSomething();}

// ✅ Usar
if (condition)
{
    DoSomething();
}
```

### 2. **Líneas Demasiado Largas**
```cpp
// ❌ Evitar líneas > 100 caracteres
Character* player = new Character(20, 20, 10, 10, 10, 0, "PlayerName", true, false, SomeOtherLongParameter);

// ✅ Dividir en múltiples líneas
Character* player = new Character(20, 20, 10, 10, 10, 0, 
                                  "PlayerName", true, false, 
                                  SomeOtherLongParameter);
```

### 3. **Includes Desordenados**
```cpp
// ❌ Evitar
#include "LocalHeader.h"
#include <iostream>
#include "AnotherLocal.h"
#include <string>

// ✅ Agrupar y ordenar
#include <iostream>
#include <string>

#include "AnotherLocal.h"
#include "LocalHeader.h"
```

## 📊 Métricas de Calidad

### Objetivos del Proyecto
- **Consistencia**: 100% de archivos formateados
- **Legibilidad**: Líneas < 100 caracteres
- **Documentación**: Métodos públicos documentados
- **Estilo**: Sin warnings de clang-format

### Verificación Automática
```bash
# Script para verificar cumplimiento
find . -name "*.cpp" -o -name "*.h" | xargs clang-format --dry-run --Werror
```

## 🔄 Proceso de Desarrollo

### Antes de Commit
1. Ejecutar `.\format_code.ps1`
2. Revisar cambios con `git diff`
3. Verificar que no hay warnings de formato
4. Hacer commit con mensaje descriptivo

### Durante Code Review
- Verificar que el código sigue las convenciones
- Asegurar que la documentación está actualizada
- Confirmar que el formateo es consistente

## 📚 Referencias

- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [ClangFormat Documentation](https://clang.llvm.org/docs/ClangFormat.html)
- [Modern C++ Best Practices](https://github.com/cpp-best-practices/cppbestpractices)

---

**Nota**: Este estilo de código es específico para el proyecto "Patrones de Diseño C++" y está diseñado para maximizar la legibilidad y mantenibilidad del código educativo.