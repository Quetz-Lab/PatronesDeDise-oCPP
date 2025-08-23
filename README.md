Command: Sirve para hacer código limpio generando instancias a las que sean fáciles de acceder sin que tener que hacer un código largo en main, usando inputHandler.






+------------------+

|    Command       |<<abstract>>

+------------------+

| +execute(Character\&): void |

+------------------+



&nbsp;       ▲

&nbsp;       │

&nbsp;       ├───────────────┬────────────────┬─────────────────┐

&nbsp;       │               │                │                 │

+----------------+ +----------------+ +----------------+ +----------------+

| JumpCommand    | | ShootCommand   | | CrouchCommand  | | OtherCommand?  |

+----------------+ +----------------+ +----------------+ +----------------+

| +execute(Character\&): void        |

+----------------+ +----------------+ +----------------+ +----------------+



&nbsp;       ↓

+------------------+

|   Character      |

+------------------+

| +Jump(): void    |

| +Shoot(): void   |

| +Crouch(): void  |

+------------------+



&nbsp;       ↑

&nbsp;       │

+------------------+

| InputHandler     |

+------------------+

| -jump\_: JumpCommand         |

| -shoot\_: ShootCommand       |

| -crouch\_: CrouchCommand     |

| -mapeoTeclas: map<char, Command\*> |

+------------------+

| +handleInput(char, Character\&)    |

| +remapearTecla(char, string)      |



Para este caso decidí que el mensaje que debería dar al remapear sea "Remapeo no exitoso"


Una FSM es un método en el que se puede llamar un comando de manera más eficiente y directa a la par de que se puede elegir que estados pueden tener una función simultanea como saltar y atacar. Usar un enum es más eficiente y fácil de leer para un programa que tener una larga lista de bools.

En este caso el inputHandler es quien se lleva la responsabilidad de cargar todo desde la clase de State al tener que estar checando que estados pueden estar en simultaneo y cuales no.


[IDLE]
  ├── al presionar "saltar" ──► [JUMPING]
  ├── al presionar "atacar" ──► [ATTACKING]

[JUMPING]
  └── al tocar el suelo ──► [IDLE]
      (el personaje está en el aire y no puede atacar)

[ATTACKING]
  └── al terminar la animación de ataque ──► [IDLE]
      (el personaje está atacando y no puede saltar)

 El patron observer nos ayuda a leer eventos y notificarlos a clases que hereden de el, mediante la función notify y onNotify, por ejemplo al conseguir un logro se activa onNotify por parte del padre que es Observer y lo mando al Notify de los hijos (AudioSystem y Achievements en este caso) Si bien no es rápido estos errores de pueden mejorar después.

<img width="934" height="1063" alt="UML (1)" src="https://github.com/user-attachments/assets/50d76334-3a8f-44b0-84c2-369f1d3818aa" />

