#include <stdio.h>
#include <Windows.h>	//win32 API
#include <time.h>
#include "Define.h"

#include "Unit.h"

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Effect.h"


#include "GameMng.h"

extern GameMng gameMng;

void Init();
void Update();
void Draw();
void Release();
void UIDraw();

void DrawStr(int x, int y, const char* str, WORD color);
void DrawChar(int x, int y, const char str, WORD color);
void EngineSync(int fps);
void ClearScreen();
void Flip();