# Patrones de Diseño en C++

Un portafolio completo que demuestra la implementación práctica de patrones de diseño clásicos en C++ a través de un sistema de juego interactivo. Este proyecto ilustra cómo los patrones de diseño pueden mejorar la arquitectura del software, promoviendo código limpio, mantenible y extensible.

## 📋 Índice de Patrones Implementados

1. [**Command Pattern**](#-command-pattern) - Encapsulación de acciones como objetos
2. [**Observer Pattern**](#-observer-pattern) - Notificación automática de eventos
3. [**State Pattern**](#-state-pattern) - Gestión de estados del personaje
4. [**Event Queue Pattern**](#-event-queue-pattern) - Procesamiento asíncrono de eventos

## 🚀 Instrucciones de Compilación y Uso

### Prerrequisitos
- Visual Studio 2019 o superior
- Windows 10/11
- Git

### Pasos de Instalación

1. **Clonar el repositorio**
   ```bash
   https://github.com/Quetz-Lab/PatronesDeDise-oCPP
   cd PatronesDeDise-oCPP
   ```

2. **Abrir en Visual Studio**
   - Abrir Visual Studio
   - Seleccionar "Abrir un proyecto o solución"
   - Navegar hasta el directorio clonado
   - Abrir el archivo `PatronesDeDisenoCPP.sln`

3. **Compilar y Ejecutar**
   - Presionar `Ctrl + F5` para compilar y ejecutar sin depuración
   - O usar `F5` para ejecutar con depuración
   - El programa se ejecutará en la consola

### Controles del Juego
- `w` - Saltar
- `f` - Atacar/Disparar
- `v` - Debug: Recibir daño
- `r` - Remapear teclas
- `x` - Salir

## 🎯 Command Pattern

### Explicación Conceptual

El patrón Command encapsula una solicitud como un objeto, permitiendo parametrizar clientes con diferentes solicitudes, encolar operaciones y soportar operaciones reversibles. En mi implementación, cada acción del personaje (saltar, disparar, agacharse) se convierte en un objeto Command independiente.

Este patrón es especialmente útil para:
- Desacoplar el objeto que invoca la operación del que la ejecuta
- Permitir el remapeo dinámico de controles
- Facilitar la implementación de macros o secuencias de comandos
- Simplificar el manejo de entrada del usuario

### Diagrama UML - Command Pattern

```
┌─────────────────────┐
│     Command         │ <<abstract>>
├─────────────────────┤
│ +execute(Character&)│
└─────────────────────┘
           ▲
           │
    ┌──────┼──────┬──────────┬─────────────┐
    │      │      │          │             │
┌─────────┐ ┌──────────┐ ┌─────────────┐ ┌──────────────┐
│JumpCmd  │ │ShootCmd  │ │CrouchCmd    │ │GetDamageDebug│
├─────────┤ ├──────────┤ ├─────────────┤ ├──────────────┤
│+execute │ │+execute  │ │+execute     │ │+execute      │
└─────────┘ └──────────┘ └─────────────┘ └──────────────┘
           │
           ▼
┌─────────────────────┐
│    Character        │
├─────────────────────┤
│ +Jump()             │
│ +Shoot()            │
│ +Crouch()           │
│ +DebugGetDamage()   │
└─────────────────────┘
           ▲
           │
┌─────────────────────┐
│   InputHandler      │
├─────────────────────┤
│ -botonW_: Command*  │
│ -botonF_: Command*  │
│ -keyMappings: map   │
├─────────────────────┤
│ +handleInput(char)  │
│ +remapearTecla()    │
└─────────────────────┘
```

### Fragmento de Código Representativo

```cpp
// Interfaz Command abstracta
class Command {
public:
    virtual ~Command();
    virtual void execute(Character& character) = 0;
};

// Implementación concreta - JumpCommand
class JumpCommand : public Command {
public:
    virtual void execute(Character& character) override {
        character.Jump();
    }
};

// InputHandler que usa los comandos
class InputHandler {
private:
    std::map<char, std::shared_ptr<Command>> keyMappings;
    Command* botonW_;
    Command* botonF_;

public:
    Command* handleInput(char tecla) {
        if (tecla == 'w') return botonW_;
        if (tecla == 'f') return botonF_;
        return nullptr;
    }
    
    void remapearTecla(char tecla, std::string accion) {
        if (accion == "jump") {
            keyMappings[tecla] = std::make_unique<JumpCommand>();
        }
        // ... más mapeos
    }
};
```

## 👁️ Observer Pattern

### Explicación Conceptual

El patrón Observer define una dependencia uno-a-muchos entre objetos, de manera que cuando un objeto cambia de estado, todos sus dependientes son notificados automáticamente. En mi implementación, el `Character` actúa como el Subject que notifica a múltiples observadores (`AudioSystem` y `Achievements`) cuando ocurren eventos importantes.

Este patrón es fundamental para:
- Mantener consistencia entre objetos relacionados
- Implementar sistemas de eventos desacoplados
- Permitir que múltiples sistemas reaccionen a un mismo evento
- Facilitar la extensión del sistema sin modificar código existente

### Diagrama UML - Observer Pattern

```
┌─────────────────────┐
│     Observer        │ <<abstract>>
├─────────────────────┤
│ +OnNotify(Character&│
│          Event)     │
└─────────────────────┘
           ▲
           │
    ┌──────┴──────┐
    │             │
┌─────────────┐ ┌─────────────┐
│Achievements │ │AudioSystem  │
├─────────────┤ ├─────────────┤
│+OnNotify()  │ │+OnNotify()  │
└─────────────┘ │+RequestSound│
                │+processEvents│
                └─────────────┘
           ▲
           │ notifies
┌─────────────────────┐
│     Character       │
├─────────────────────┤
│ -observers[10]      │
│ -m_numObservers     │
├─────────────────────┤
│ +addObserver()      │
│ -Notify(Event)      │
└─────────────────────┘

┌─────────────────────┐
│       Event         │ <<enum>>
├─────────────────────┤
│ Character_Get_Damage│
└─────────────────────┘
```

### Fragmento de Código Representativo

```cpp
// Interfaz Observer
class Observer {
public:
    virtual ~Observer() {}
    virtual void OnNotify(const Character& character, Event event) = 0;
};

// Character como Subject
class Character {
private:
    static const int MaxObservers = 10;
    Observer* observers[MaxObservers];
    int m_numObservers;
    
    void Notify(Event event) {
        for (int i = 0; i < m_numObservers; ++i) {
            observers[i]->OnNotify(*this, event);
        }
    }

public:
    void addObserver(Observer* observer) {
        if (m_numObservers < MaxObservers) {
            observers[m_numObservers++] = observer;
        }
    }
    
    int GetDamage() {
        Notify(Event::Character_Get_Damage);  // Notifica a observadores
        return _damage;
    }
};

// Observador concreto - Achievements
class Achievements : public Observer {
public:
    virtual void OnNotify(const Character& character, Event event) {
        if (event == Event::Character_Get_Damage) {
            std::cout << "¡Logro desbloqueado 'Primer Golpe'!" << std::endl;
        }
    }
};
```

## 🔄 State Pattern

### Explicación Conceptual

El patrón State permite que un objeto altere su comportamiento cuando su estado interno cambia, aparentando como si el objeto hubiera cambiado de clase. En mi implementación, utilizo una máquina de estados finita (FSM) simple para controlar los estados del personaje: IDLE, JUMPING y ATTACKING.

Este patrón es esencial para:
- Organizar código complejo dependiente del estado
- Eliminar condicionales complejas y anidadas
- Hacer que las transiciones de estado sean explícitas
- Facilitar la adición de nuevos estados sin afectar los existentes

### Diagrama UML - State Pattern

```
┌─────────────────────┐
│    StateEnum        │ <<enum>>
├─────────────────────┤
│ IDLE                │
│ JUMPING             │
│ ATTACKING           │
└─────────────────────┘
           ▲
           │ uses
┌─────────────────────┐
│      State          │
├─────────────────────┤
│ +m_CurrentState     │
│ +m_stateTimer       │
├─────────────────────┤
│ +State()            │
└─────────────────────┘

Transiciones de Estado:
[IDLE] ──w──► [JUMPING] ──timer──► [IDLE]
  │                                   ▲
  └──f──► [ATTACKING] ──timer─────────┘
```

### Fragmento de Código Representativo

```cpp
// Enumeración de estados
enum StateEnum {
    IDLE,
    JUMPING,
    ATTACKING
};

// Clase State que mantiene el estado actual
class State {
public:
    StateEnum m_CurrentState;
    int m_stateTimer;
    
    State() : m_CurrentState(IDLE), m_stateTimer(0) {}
};

// Uso en el juego principal
int main() {
    State state;
    Character* player = new Character(20,20,10,10,10, 0);
    
    while (true) {
        // Lógica de transición de estados
        switch(state.m_CurrentState) {
            case IDLE:
                // Puede saltar o atacar
                if (tecla == 'w') {
                    state.m_CurrentState = JUMPING;
                    player->Jump();
                }
                else if (tecla == 'f') {
                    state.m_CurrentState = ATTACKING;
                    player->Shoot();
                }
                break;
                
            case JUMPING:
                // Solo puede volver a IDLE después del timer
                if (state.m_stateTimer <= 0) {
                    state.m_CurrentState = IDLE;
                }
                break;
                
            case ATTACKING:
                // Solo puede volver a IDLE después del timer
                if (state.m_stateTimer <= 0) {
                    state.m_CurrentState = IDLE;
                }
                break;
        }
        
        state.m_stateTimer--;
    }
}
```

## 📬 Event Queue Pattern

### Explicación Conceptual

El patrón Event Queue desacopla el momento en que se envía un mensaje del momento en que se procesa, almacenando eventos en una cola para procesarlos posteriormente. A diferencia del patrón Observer que procesa eventos síncronamente, Event Queue permite procesamiento asíncrono y diferido.

Este patrón es crucial para:
- Evitar saturación del sistema con muchos eventos simultáneos
- Permitir procesamiento por lotes de eventos
- Controlar el orden y timing de procesamiento de eventos
- Mejorar el rendimiento al diferir operaciones costosas

### Diagrama UML - Event Queue Pattern

```
┌─────────────────────┐
│     SoundID         │ <<enum>>
├─────────────────────┤
│ HIT                 │
│ JUMP                │
│ DEATH               │
└─────────────────────┘
           ▲
           │ uses
┌─────────────────────┐
│   SoundEvent        │ <<struct>>
├─────────────────────┤
│ +id: SoundID        │
├─────────────────────┤
│ +operator==()       │
└─────────────────────┘
           ▲
           │ queues
┌─────────────────────┐
│   AudioSystem       │
├─────────────────────┤
│ -MAX_PENDING: 16    │
│ -pendingSounds[]    │
│ -pendingCount       │
├─────────────────────┤
│ +RequestSound()     │
│ +processEvents()    │
└─────────────────────┘

┌─────────────────────┐
│   EventQueue        │ <<placeholder>>
├─────────────────────┤
│ // Future expansion │
└─────────────────────┘
```

### Fragmento de Código Representativo

```cpp
// Definición de eventos de sonido
enum class SoundID {
    HIT, JUMP, DEATH
};

struct SoundEvent {
    SoundID id;
    bool operator==(const SoundEvent& other) const {
        return id == other.id;
    }
};

// AudioSystem implementa Event Queue
class AudioSystem : public Observer {
private:
    static const int MAX_PENDING = 16;
    SoundID pendingSounds[MAX_PENDING];
    int pendingCount;

public:
    AudioSystem() : pendingCount(0) {}
    
    // Encolar evento (asíncrono)
    void RequestSound(SoundEvent event) {
        if (pendingCount < MAX_PENDING) {
            pendingSounds[pendingCount++] = event.id;
        }
    }
    
    // Procesar cola de eventos (diferido)
    void processEvents() {
        for (int i = 0; i < pendingCount; ++i) {
            switch (pendingSounds[i]) {
                case SoundID::HIT:
                    std::cout << "Reproduciendo sonido de HIT" << std::endl;
                    break;
                case SoundID::JUMP:
                    std::cout << "Reproduciendo sonido de JUMP" << std::endl;
                    break;
                case SoundID::DEATH:
                    std::cout << "Reproduciendo sonido de DEATH" << std::endl;
                    break;
            }
        }
        pendingCount = 0; // Limpiar cola
    }
};

// Uso en el bucle principal
int main() {
    AudioSystem audioSystem;
    
    while (true) {
        // Encolar múltiples eventos durante el frame
        audioSystem.RequestSound({SoundID::HIT});
        audioSystem.RequestSound({SoundID::JUMP});
        audioSystem.RequestSound({SoundID::DEATH});
        
        std::cout << "--- Fin del frame de lógica ---\n";
        
        // Procesar todos los eventos encolados al final del frame
        audioSystem.processEvents();
        
        // ... resto de la lógica del juego
    }
}
```

## 📁 Estructura del Proyecto

```
PatronesDeDisenoCPP/
├── Include/
│   ├── Core/
│   │   └── Character.h
│   ├── Patterns/
│   │   ├── Command.h
│   │   ├── Observer.h
│   │   ├── State.h
│   │   ├── EventQueue.h
│   │   └── InputHandler.h
│   └── Systems/
│       ├── Achievements.h
│       └── AudioSystem.h
├── src/
│   ├── Core/
│   │   └── Character.cpp
│   ├── Patterns/
│   │   ├── Command.cpp
│   │   ├── Observer.cpp
│   │   ├── State.cpp
│   │   ├── EventQueue.cpp
│   │   └── InputHandler.cpp
│   ├── System/
│   │   ├── Achievements.cpp
│   │   └── AudioSystem.cpp
│   └── PatronesDeDisenoCPP.cpp
├── UML_Diagram.puml
├── UML_Documentation.md
└── README.md
```

## 🎓 Conclusiones

Este proyecto demuestra cómo los patrones de diseño pueden trabajar juntos para crear un sistema robusto y extensible. Cada patrón resuelve problemas específicos:

- **Command**: Flexibilidad en el manejo de entrada
- **Observer**: Comunicación desacoplada entre sistemas
- **State**: Control organizado del comportamiento del personaje
- **Event Queue**: Procesamiento eficiente de eventos

La combinación de estos patrones resulta en un código más mantenible, testeable y extensible, demostrando el valor práctico de los patrones de diseño en el desarrollo de software.

