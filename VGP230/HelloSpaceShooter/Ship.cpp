#include "Ship.h"
#include "Bullet.h"


Ship::Ship()
	:Entity()
	,mImageID(0)
	,mPosition(0)
	,mRotation(0)
	
{

}

Ship::~Ship()
{

}

void Ship::Load()
{
	mImageID = X::LoadTexture("fighter.png");
	XASSERT(mImageID != 0, "ship not found");

	mPosition.x = X::GetScreenWidth() * 0.5;
	mPosition.y = X::GetScreenHeight() * 0.5;

	mbulletPool.Load();
	
}


void Ship::Update(float deltatime)
{
	const float speed = 250.0f;
	const float turnSpeed = 5.0f;

	if (X::IsKeyDown(X::Keys::W))
	{
		mPosition += X::Math::Vector2::Forward(mRotation) * speed * deltatime;
	}
	else if (X::IsKeyDown(X::Keys::S))
	{
		mPosition -= X::Math::Vector2::Forward(mRotation) * speed * deltatime;
	}

	if (X::IsKeyDown(X::Keys::A))
	{
		mRotation -= turnSpeed * deltatime;
	}
	else if (X::IsKeyDown(X::Keys::D))
	{
		mRotation+= turnSpeed * deltatime;
	}

	if (X::IsKeyPressed(X::Keys::SPACE))
	{
		X::Math::Vector2 spawnPOS = mPosition + X::Math::Vector2::Forward(mRotation) * 50.0f;
		Bullet* bullet = mbulletPool.GetBullet();
		bullet->SetActive(spawnPOS, mRotation);
	}

	mbulletPool.Update(deltatime);
}

void Ship::Render()
{
	X::DrawSprite(mImageID,mPosition,mRotation);

	mbulletPool.Render();
}

void Ship::Unload() 
{
	mbulletPool.Unload();
}
