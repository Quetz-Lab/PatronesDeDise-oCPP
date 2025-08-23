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

