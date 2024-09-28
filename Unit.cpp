#include "include.h"

Unit::Unit()
{
	x = 0;
	y = 0;
	speed = 1;
	attack = 1;
	body = ' ';
	isActive = false;
}

Unit::~Unit()
{
}

void Unit::Update()
{
	Move();
	Clipping();
}

void Unit::Draw()
{
	if (isActive)
		DrawChar(x, y, body, color);
}

void Unit::Move()
{
}

void Unit::Clipping()
{
}
