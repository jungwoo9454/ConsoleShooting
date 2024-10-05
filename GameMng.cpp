#include "include.h"

Player player;
Bullet bullets[D_BULLET_MAX];
Enemy enemys[D_ENEMY_MAX];
Effect effects[D_EFFECT_MAX];

GameMng::GameMng()
{
	FMOD::System_Create(&Sound::system);
	Sound::system->init(512, FMOD_INIT_NORMAL, nullptr);
	//상대 경로, 절대 경로

	backgroundSound.LoadSoundFile("Debug/Asset/backgroundMusic.mp3", true);
	bulletSound.LoadSoundFile("Debug/Asset/bullet.wav", false);
	backgroundSound.Playsound();

	stateCtrl.StateAdd(E_MENU, &menuState);
	stateCtrl.StateAdd(E_GAME, &gameState);

	stateCtrl.StateChange(E_GAME);
}

GameMng::~GameMng()
{
}

void GameMng::CreateBullet(int x, int y)
{
	bulletSound.Playsound();
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (bullets[i].isActive == false)
		{
			bullets[i].Enable(x, y - 1);
			break;
		}
	}
}

void GameMng::CreateEnemy(int x, int y)
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemys[i].isActive == false)
		{
			enemys[i].Enable(x, y);
			break;
		}
	}
}

void GameMng::CreateEffect(int x, int y)
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		if (effects[i].isActive == false)
		{
			effects[i].Enable(x, y);
			break;
		}
	}
}

void GameMng::EnemyBulletCollision()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (bullets[i].isActive)
		{
			for (int j = 0; j < D_ENEMY_MAX; j++)
			{
				if (enemys[j].isActive &&
					bullets[i].x == enemys[j].x &&
					(bullets[i].y == enemys[j].y || bullets[i].y + 1 == enemys[j].y))
				{
					bullets[i].Disable();
					enemys[j].Disable();
					CreateEffect(bullets[i].x, bullets[i].y);
				}
			}
		}
	}
}

void GameMng::Update()
{
	stateCtrl.Update();
}

void GameMng::Draw()
{
	stateCtrl.Draw();
}
