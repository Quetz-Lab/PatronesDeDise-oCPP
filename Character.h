#pragma once
#include <iostream>
class Character
{
public:
	Character(float health, float maxHealth, float speed, int damage, float jumpHeight);
	Character();
	~Character();
	void Jump();
	void Shoot();

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


private:
	float _health;
	float _speed;
	int _damage;
	float _maxHealth;
	float _jumpheight;
};

