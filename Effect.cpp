#include "include.h"

char g_effect[3][3][3] =
{
	{
		{' ', ' ', ' '},
		{' ', '*', ' '},
		{' ', ' ', ' '}
	},
	{
		{' ', '*', ' '},
		{'*', '*', '*'},
		{' ', '*', ' '}
	},
	{
		{'*', ' ', '*'},
		{' ', '*', ' '},
		{'*', ' ', '*'}
	}
};

Effect::Effect()
{
	index = 0;
	indexUpdateTime = 0;
	color = GREEN;
}

Effect::~Effect()
{
}

void Effect::Update()
{
	if (isActive && indexUpdateTime <= GetTickCount())
	{
		//														1000 = 1ÃÊ
		indexUpdateTime = GetTickCount() + 300;
		index++;

		if (index > 2)
			isActive = false;
	}
}

void Effect::Draw()
{
	if (isActive)
	{
		DrawChar(x - 1, y - 1, g_effect[index][0][0], color);
		DrawChar(x, y - 1, g_effect[index][0][1], color);
		DrawChar(x + 1, y - 1, g_effect[index][0][2], color);

		DrawChar(x - 1, y, g_effect[index][1][0], color);
		DrawChar(x, y, g_effect[index][1][1], color);
		DrawChar(x + 1, y, g_effect[index][1][2], color);

		DrawChar(x - 1, y + 1, g_effect[index][2][0], color);
		DrawChar(x, y + 1, g_effect[index][2][1], color);
		DrawChar(x + 1, y + 1, g_effect[index][2][2], color);
	}
}

void Effect::Enable(int x, int y)
{
	this->x = x;
	this->y = y;
	isActive = true;

	index = 0;
	indexUpdateTime = GetTickCount() + 300;
}
