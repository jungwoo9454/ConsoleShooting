#include "include.h"
Bullet bullets[D_BULLET_MAX];
void BulletInit()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		bullets[i].x = 0;
		bullets[i].y = 0;
		bullets[i].speed = 1;
		bullets[i].attack = 1;
		bullets[i].isActive = false;
		strcpy_s(bullets[i].body, 10, "|");
	}
}
void BulletUpdate()
{
	BulletMove();
	BulletClipping();
}
void BulletDraw()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
		if (bullets[i].isActive)
			DrawStr(bullets[i].x, bullets[i].y, bullets[i].body, GREEN);
}

void BulletMove()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
		if (bullets[i].isActive)
			bullets[i].y -= bullets[i].speed;
}

void BulletClipping()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
		if (bullets[i].isActive && bullets[i].y < 0)
			bullets[i].isActive = false;
}