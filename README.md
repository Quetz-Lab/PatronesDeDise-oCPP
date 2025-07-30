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


