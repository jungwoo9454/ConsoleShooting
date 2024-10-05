#include "include.h"
Player::Player()
{
	x = 60;
	y = 15;
	body = 'A';
	isActive = true;
	color = WHITE;
}

Player::~Player()
{
}

void Player::Update()
{
	Unit::Update();
	
	if (GetAsyncKeyState(VK_SPACE))
	{
		gameMng.CreateBullet(x, y);
	}
}

void Player::Move()
{
	if (GetAsyncKeyState('W') & 0x8000)
		y -= speed;

	if (GetAsyncKeyState('A') & 0x8000)
		x -= speed;

	if (GetAsyncKeyState('S') & 0x8000)
		y += speed;

	if (GetAsyncKeyState('D') & 0x8000)
		x += speed;
}

void Player::Clipping()
{
	if (x > 119)
		x = 119;

	if (x < 0)
		x = 0;

	if (y > 29)
		y = 29;

	if (y < 0)
		y = 0;
}