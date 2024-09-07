#include "include.h"

int screenIndex;
HANDLE hScreen[2];

void Init()
{
	//																			0000 1001				
	//																0000 1000			0000 0001
	hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 1;

	SetConsoleCursorInfo(hScreen[0], &cci);
	SetConsoleCursorInfo(hScreen[1], &cci);

	PlayerInit();
	BulletInit();
}
void Update()
{
	PlayerUpdate();
	BulletUpdate();
}
void Draw()
{
	ClearScreen();

	PlayerDraw();
	BulletDraw();

	Flip();
}
void Release()
{
	CloseHandle(hScreen[0]);
	CloseHandle(hScreen[1]);
}

void DrawStr(int x, int y, const char* str, WORD color)
{
	if (x > 119 || x < 0 || y > 29 || y < 0)
		return;

	COORD coor = { x,y };
	DWORD dw;
	SetConsoleCursorPosition(hScreen[screenIndex], coor);
	SetConsoleTextAttribute(hScreen[screenIndex], color);

	int maxLen = 120 - x;
	int strLen = strlen(str);

	if (maxLen < strLen)
		strLen = maxLen;

	WriteFile(hScreen[screenIndex], str, strLen, &dw, NULL);
}

void EngineSync(int fps)
{
	//					프로그램 실행 시간
	clock_t old = clock();
	clock_t cur;

	while (true)
	{
		cur = clock();	// 0.03
		if (cur - old > 1000 / fps)
			break;
	}
}

void ClearScreen()
{
	COORD coor = { 0,0 };
	DWORD dw;

	FillConsoleOutputCharacter(hScreen[screenIndex], ' ', 120 * 30, coor, &dw);
	FillConsoleOutputAttribute(hScreen[screenIndex], 0, 120 * 30, coor, &dw);
}

void Flip()
{
	//더블 버퍼링
	SetConsoleActiveScreenBuffer(hScreen[screenIndex]);
	screenIndex = !screenIndex;
}