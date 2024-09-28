#include "include.h"

Enemy::Enemy()
{
	color = RED_BOX;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	Unit::Update();
}

void Enemy::Move()
{
	if (isActive)
		y += speed;
}

void Enemy::Clipping()
{
	if (isActive && y > 30)
		isActive = false;
}

void Enemy::Enable(int x, int y)
{
	this->x = x;
	this->y = y;
	isActive = true;
}

void Enemy::Disable()
{
	isActive = false;
}
