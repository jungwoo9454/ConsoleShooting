#pragma once
class GameMng
{
public:
	Sound backgroundSound;
	Sound bulletSound;
	CStateCtrl stateCtrl;

	MenuState menuState;
	GameState gameState;

	GameMng();
	~GameMng();

	void CreateBullet(int x, int y);
	void CreateEnemy(int x, int y);
	void CreateEffect(int x, int y);

	void EnemyBulletCollision();


	void Update();
	void Draw();
};

extern Player player;
extern Bullet bullets[D_BULLET_MAX];
extern Enemy enemys[D_ENEMY_MAX];
extern Effect effects[D_EFFECT_MAX];