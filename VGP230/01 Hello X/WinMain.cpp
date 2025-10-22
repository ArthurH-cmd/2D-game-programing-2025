#include <XEngine.h>

// 1
X::TextureId imageID = 0;
X::Math::Vector2 imagePosition = { 0.0f, 0.0f };
float speedX = 500.0f;
float speedY = 500.0f;
float imageHeight = 10.0f;
float imageWidth = 10.0f;

// 2
X::TextureId imageID2 = 0;
X::Math::Vector2 imagePosition2 = { 0.0f, 0.0f };
float speedX2 = 1000.0f;
float speedY2 = 1000.0f;
float imageHeight2 = 10.0f;
float imageWidth2 = 10.0f;

void GameInit()
{
	imageID = X::LoadTexture("bullet2.png");
	imageWidth = X::GetSpriteWidth(imageID);
	imageHeight = X::GetSpriteHeight(imageID);
	imagePosition.x = X::GetScreenWidth() * 0.5f;
	imagePosition.y = X::GetScreenHeight() * 0.5f;

	imageID2 = X::LoadTexture("bullet1.png");
	imageWidth2 = X::GetSpriteWidth(imageID);
	imageHeight2 = X::GetSpriteHeight(imageID);
	imagePosition2.x = X::GetScreenWidth() * 0.5f;
	imagePosition2.y = X::GetScreenHeight() * 0.5f;
	
}

void GameRender()
{
	X::DrawSprite(imageID, imagePosition);
	X::DrawSprite(imageID2, imagePosition2);
}

bool GameLoop(float deltaTime)
{
	imagePosition2.x += speedX2 * deltaTime;
	imagePosition2.y += speedY2 * deltaTime;


	imagePosition.x += speedX * deltaTime;
	imagePosition.y += speedY * deltaTime;
	
	if (imagePosition.x - imageWidth <= 0.0f)
	{
		imagePosition.x = imageWidth;
		speedX = -speedX;
	}
	else if (imagePosition.x + imageWidth >= X::GetScreenWidth()) 
	{
		imagePosition.x = X::GetScreenWidth() - imageWidth;
		speedX = -speedX;
	
	}


	if (imagePosition.y - imageHeight <= 0.0f)
	{
		imagePosition.y = imageHeight;
		speedY = -speedY;
	}
	else if (imagePosition.y + imageHeight >= X::GetScreenHeight())
	{
		imagePosition.y = X::GetScreenHeight() - imageHeight;
		speedY = -speedY;
	}

	/////

	if (imagePosition2.x - imageWidth2 <= 0.0f)
	{
		imagePosition2.x = imageWidth2;
		speedX2 = -speedX2;
	}
	else if (imagePosition2.x + imageWidth2 >= X::GetScreenWidth())
	{
		imagePosition2.x = X::GetScreenWidth() - imageWidth2;
		speedX2 = -speedX2;

	}


	if (imagePosition2.y - imageHeight2 <= 0.0f)
	{
		imagePosition2.y = imageHeight2;
		speedY2 = -speedY2;
	}
	else if (imagePosition2.y + imageHeight2 >= X::GetScreenHeight())
	{
		imagePosition2.y = X::GetScreenHeight() - imageHeight2;
		speedY2 = -speedY2;
	}

	GameRender();

	return X::IsKeyPressed(X::Keys::ESCAPE);	
}

void GameCleanup()
{
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
