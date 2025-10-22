#include <XEngine.h>
#include "Ship.h"

Ship mship;

void GameInit()
{
	mship.Load();
}

void GameRender()
{
	
}

bool GameLoop(float deltaTime)
{
	mship.Update(deltaTime);
	mship.Render();
	return X::IsKeyPressed(X::Keys::ESCAPE);	
}

void GameCleanup()
{
	mship.Unload();
}

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	X::Start("xconfig.json");
	GameInit();

	X::Run(GameLoop);

	GameCleanup();
	X::Stop();
	return 0;
}
