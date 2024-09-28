#include "include.h"

int main()
{
	Init();

	while (true)
	{
		// 포인터
		// FMOD - 라이브러리(.dll or .lib, .h)
		// State(Scene) - FSM
		// 싱글톤 - 디자인 패턴
		// C++ STL - 자료구조
		// 오브젝트 관리

		Update();
		Draw();

		EngineSync(30);
	}

	Release();

	return 0;
}