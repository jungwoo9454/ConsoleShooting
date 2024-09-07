#pragma once
struct Bullet
{
	bool isActive;
	int x;
	int y;
	char body[10];

	int attack;
	int speed;
};

void BulletInit();
void BulletUpdate();
void BulletDraw();

void BulletMove();
void BulletClipping();