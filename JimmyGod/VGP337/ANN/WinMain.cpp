#include <JimmyGodEngine/Inc/JimmyGodEngine.h>
#include "GameState.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	JimmyGod::MainApp().AddState<GameState>("GameState");
	JimmyGod::MainApp().Run({ "Hello Genetic Algorithms, JimmyGod",1280,720 });
	return 0;
}

// NDC = Normalized device coordinate