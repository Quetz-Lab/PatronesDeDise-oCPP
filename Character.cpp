#include "Character.h"
Character::Character(float health, float maxHealth, float speed, int damage, float jumpHeight)
{
	_health = health;
	_maxHealth = maxHealth;
	_speed = speed;
	_damage = damage;
	_jumpheight = jumpHeight;

}
Character::Character()
{
	_health = 100;
	_maxHealth = 100;
	_speed = 10;
	_damage = 10;
	_jumpheight = 10;
}
void Character::Jump()
{
	std::cout << "Saltando" << std::endl;
}
void Character::Shoot()
{
	std::cout << "Disparando" << std::endl;
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
	_jumpheight = jumpHeight;
}


