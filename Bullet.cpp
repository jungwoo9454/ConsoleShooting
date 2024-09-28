#include "include.h"
Bullet::Bullet()
{
	body = '|';
	color = GREEN;
}

Bullet::~Bullet()
{
}

void Bullet::Move()
{
	if (isActive)
		y -= speed;
}

void Bullet::Clipping()
{
	if (isActive && y < 0)
		isActive = false;
}

void Bullet::Enable(int x, int y)
{
	this->x = x;
	this->y = y;
	isActive = true;
}

void Bullet::Disable()
{
	isActive = false;
}
