#include "../Core/Character.h"
Character::Character(float health, float maxHealth, float speed, int damage, float jumpHeight, int NumObservers)
{
	_health = health;
	_maxHealth = maxHealth;
	_speed = speed;
	_damage = damage;
	_jumpheight = jumpHeight;
	//Observers
	m_numObservers = NumObservers;
    observers[0] = 0;
}
Character::Character()
{
	_health = 100;
	_maxHealth = 100;
	_speed = 10;
	_damage = 10;
	_jumpheight = 10;
	//Setear el numero de observers a 0
	m_numObservers = 0;
    observers[0] = 0;
}
void Character::Jump()
{
	std::cout << "Saltando" << std::endl;
}
void Character::Shoot()
{
	std::cout << "Disparando" << std::endl;
}
void Character::Crouch()
{
	std::cout << "Agachandose" << std::endl;
}
void Character::DebugGetDamage()
{
	std::cout << "Debug: Personaje recibe dano" << std::endl;
}
void Character::addObserver(Observer* observer)
{
	//Verificar que no se exceda el maximo de observers
	if (m_numObservers < MaxObservers)
	{
		//Añadir el observer al array y aumentar el contador
		observers[m_numObservers++] = observer;
	}
}
Character::~Character()
{
	std::cout << "Llamando Destructor" << std::endl;
}

float Character::GetHealth()
{
	return _health;
}
void Character::SetHealth(float health)
{
	_health = health;
}

float Character::GetSpeed()
{
	return _speed;
}

void Character::SetSpeed(float speed)
{
	_speed = speed;
}

int Character::GetDamage()
{
	//Notificar a los observers que el personaje ha recibido daño
	Notify(Event::Character_Get_Damage);
	return _damage;

}

void Character::SetDamage(int damage)
{
	_damage = damage;
}

float Character::GetMaxHealth()
{
	return _maxHealth;
}

void Character::SetMaxHealth(float maxHealth)
{
	_maxHealth = maxHealth;
}

float Character::GetJumpHeight()
{
	return _jumpheight;
}


void Character::SetJumpHeigth(float jumpHeight)
{
	_jumpheight = jumpHeight; }

int Character::GetNumObservers(int NumObservers) 
{ 
	return 0; 
}

void Character::Notify(Event event)
{
	//Notificar a todos los observers registrados del evento
	for (int i = 0; i < m_numObservers; ++i)
	{
		//Usar el metodo OnNotify de cada observer mediante array de punteros
		observers[i]->OnNotify(*this, event);
	}
}


