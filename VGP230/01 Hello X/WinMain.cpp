#include <XEngine.h>

X::TextureId imageID = 0;
X::Math::Vector2 imagePosition = { 0.0f, 0.0f };
float speedX = 500.0f;
float speedY = 500.0f;
float imageHeight = 10.0f;
float imageWidth = 10.0f;

void GameInit()
{
	imageID = X::LoadTexture("bullet2.png");
	imageWidth = X::GetSpriteWidth(imageID);
	imageHeight = X::GetSpriteHeight(imageID);
	imagePosition.x = X::GetScreenWidth() * 0.5f;
	imagePosition.y = X::GetScreenHeight() * 0.5f;
}

void GameRender()
{
	X::DrawSprite(imageID, imagePosition);
}

bool GameLoop(float deltaTime)
{
	
	



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


// place holder for my other code
/*

	while (true)
	{
		bool canMoveY = true;
		bool canMoveX = true;

		if (imagePosition.y == ScreenY || imagePosition.y == 0.0)
		{
			canMoveY = false;
		}
		else if (imagePosition.x == ScreenX || imagePosition.x == 0.0)
		{
			canMoveX = false;
		}

		// walls "X"
		if (imagePosition.x < ScreenX || imagePosition.x < 0.0)
		{
			// walking around

			if (X::IsKeyDown(X::Keys::A))
			{
				imagePosition.x -= moveSpeed * deltaTime;
			}

			else if (X::IsKeyDown(X::Keys::D))
			{
				imagePosition.x += moveSpeed * deltaTime;
			}

		}
		else // walking into walls
		{
			if (imagePosition.x > ScreenX)
			{
				imagePosition.x -= moveSpeed * deltaTime;
			}

			if (imagePosition.x < ScreenX/ScreenX)
			{
				imagePosition.x += moveSpeed * deltaTime;
			}
		}

		// walls "Y"
		if (imagePosition.y < ScreenY || imagePosition.y < 0.0)
		{
			// walking around
			if (X::IsKeyDown(X::Keys::W))
			{
				imagePosition.y -= moveSpeed * deltaTime;
			}
			else if (X::IsKeyDown(X::Keys::S))
			{
				imagePosition.y += moveSpeed * deltaTime;
			}
		}
		else // walking into walls
		{
			if (imagePosition.y > ScreenY)
			{
				imagePosition.y -= moveSpeed * deltaTime;
			}

		}

		// rotating
		if (X::IsKeyPressed(X::Keys::LEFT))
		{
			imageRotation += RotationSpeed;
		}

		if (X::IsKeyPressed(X::Keys::RIGHT))
		{
			imageRotation -= RotationSpeed;
		}




*/