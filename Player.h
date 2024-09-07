#pragma once

struct Player
{
	int x;
	int y;
	char body[10];

	int attack;
	int speed;
};

void PlayerInit();
void PlayerUpdate();
void PlayerDraw();

void PlayerMove();
void PlayerClipping();
void FireBullet();