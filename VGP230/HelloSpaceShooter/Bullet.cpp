#include "Bullet.h"


Bullet::Bullet()
	:Entity()
	,mImageID(0)
	,mPosition(0.0f)
	,mRotation(0.0f)
	,mLifeTime(0.0f)
{}

Bullet::~Bullet()
{

}

void Bullet::Load() 
{
	mImageID = X::LoadTexture("bullet1.png");
}

void Bullet::Update(float deltatime) 
{
	if (IsActive())
	{
		const float speed = 1900.0f;
		mPosition += X::Math::Vector2::Forward(mRotation) * speed * deltatime;
		mLifeTime -= deltatime;
	}
	
}

void Bullet::Render() 
{
	if (IsActive())
	{
		X::DrawSprite(mImageID, mPosition, mRotation);
	}
	
}

void Bullet::Unload() 
{

}

void Bullet::SetActive(const X::Math::Vector2& pos, float rotation, float lifeTime)
{
	mPosition = pos;
	mRotation = rotation;
	mLifeTime = lifeTime;

}

bool Bullet::IsActive() const
{
	return mLifeTime > 0.0f;
}