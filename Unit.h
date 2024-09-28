#pragma once
class Unit
{
public:
	Unit();
	~Unit();

	bool isActive;
	int x;
	int y;
	char body;
	int attack;
	int speed;
	WORD color;

	virtual void Update();
	virtual void Draw();

	virtual void Move();
	virtual void Clipping();
};