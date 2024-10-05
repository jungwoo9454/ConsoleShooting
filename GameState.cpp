#include "include.h"

GameState::GameState()
{
}

GameState::~GameState()
{
}

void GameState::Start()
{
}

void GameState::Update()
{
	if (GetAsyncKeyState(VK_F1) & 0x8000)
		gameMng.stateCtrl.StateChange(E_MENU);

	for (int i = 0; i < D_BULLET_MAX; i++)
		bullets[i].Update();
	player.Update();
	for (int i = 0; i < D_ENEMY_MAX; i++)
		enemys[i].Update();
	for (int i = 0; i < D_EFFECT_MAX; i++)
		effects[i].Update();

	gameMng.CreateEnemy(rand() % 120, -1);
	gameMng.EnemyBulletCollision();
}

void GameState::Draw()
{
	player.Draw();
	for (int i = 0; i < D_BULLET_MAX; i++)
		bullets[i].Draw();
	for (int i = 0; i < D_ENEMY_MAX; i++)
		enemys[i].Draw();
	for (int i = 0; i < D_EFFECT_MAX; i++)
		effects[i].Draw();
}

void GameState::Exit()
{
}
