#include "include.h"

int main()
{
	Init();

	while (true)
	{
		// ������
		// FMOD - ���̺귯��(.dll or .lib, .h)
		// State(Scene) - FSM
		// �̱��� - ������ ����
		// C++ STL - �ڷᱸ��
		// ������Ʈ ����

		Update();
		Draw();

		EngineSync(30);
	}

	Release();

	return 0;
}