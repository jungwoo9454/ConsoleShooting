#pragma once

class Player : public Unit
{
public:
	Player();
	~Player();

	void Update() override;
	void Move() override;
	void Clipping() override;
};