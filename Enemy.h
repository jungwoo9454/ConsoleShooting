#pragma once
class Enemy : public Unit
{
public:
	Enemy();
	~Enemy();

	void Update() override;

	void Move() override;
	void Clipping() override;

	void Enable(int x, int y);
	void Disable();
};