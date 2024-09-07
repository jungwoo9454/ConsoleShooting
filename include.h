#include <stdio.h>
#include <Windows.h>	//win32 API
#include <time.h>
#include "Define.h"

#include "Player.h"
#include "Bullet.h"


void Init();
void Update();
void Draw();
void Release();

void DrawStr(int x, int y, const char* str, WORD color);
void EngineSync(int fps);
void ClearScreen();
void Flip();