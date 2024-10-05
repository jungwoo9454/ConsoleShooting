#include "include.h"

MenuState::MenuState()
{
}

MenuState::~MenuState()
{
}

void MenuState::Start()
{
}

void MenuState::Update()
{
	if (GetAsyncKeyState(VK_F2) & 0x8000)
		gameMng.stateCtrl.StateChange(E_GAME);
}

void MenuState::Draw()
{
	DrawStr(10, 10, "Menu State", WHITE);
}

void MenuState::Exit()
{
}
