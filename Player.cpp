#include "include.h"
extern Bullet bullets[D_BULLET_MAX];
Player player;
void PlayerInit()
{
	player.x = 60;
	player.y = 15;
	player.speed = 1;
	player.attack = 1;
	strcpy_s(player.body,10, "A");
}
void PlayerUpdate()
{
	PlayerMove();
	PlayerClipping();
	FireBullet();
}
void PlayerDraw()
{
	DrawStr(player.x, player.y, player.body, WHITE);
}

void PlayerMove()
{
	//VK_SPACE
	if (GetAsyncKeyState('W') & 0x8000)
		player.y -= player.speed;

	if (GetAsyncKeyState('A') & 0x8000)
		player.x -= player.speed;

	if (GetAsyncKeyState('S') & 0x8000)
		player.y+= player.speed;

	if (GetAsyncKeyState('D') & 0x8000)
		player.x+= player.speed;
}
void PlayerClipping()
{
	if (player.x > 119)
		player.x = 119;

	if (player.x < 0)
		player.x = 0;

	if (player.y > 29)
		player.y = 29;

	if (player.y < 0)
		player.y = 0;
}

void FireBullet()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		for (int i = 0; i < D_BULLET_MAX; i++)
		{
			if (bullets[i].isActive == false)
			{
				bullets[i].isActive = true;
				bullets[i].x = player.x;
				bullets[i].y = player.y;
				break;
			}
		}
	}
}