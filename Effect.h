#pragma once
class Effect : public Unit
{
public:
	Effect();
	~Effect();

	DWORD indexUpdateTime;
	int index;

	void Update() override;
	void Draw() override;
	void Enable(int x, int y);
};

