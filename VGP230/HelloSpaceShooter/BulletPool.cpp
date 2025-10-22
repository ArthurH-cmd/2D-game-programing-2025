#include "BulletPool.h"
#include "Bullet.h"

BulletPool::BulletPool()
	:Entity()
	,mNextAvalibleIndex(0)
{
}

BulletPool::~BulletPool()
{
	XASSERT(mBullets.empty(), "BulletPool: unload must be called");
}

void BulletPool::Load()
{
	const int maxBullets = 50;
	for (int i = 0; i < maxBullets; i++)
	{
		Bullet* newBullet = new Bullet();
		newBullet->Load();
		mBullets.push_back(newBullet);
	}
}

void BulletPool::Update(float deltatime)
{
	for (int i = 0; i < mBullets.size(); i++)
	{
		mBullets[i]->Update(deltatime);
	}
}

void BulletPool::Render()
{
	for (int i = 0; i < mBullets.size(); i++)
	{
		mBullets[i]->Render();
	}
}

void BulletPool::Unload()
{
	for (int i = 0; i < mBullets.size(); i++)
	{
		mBullets[i]->Unload();
		delete mBullets[i];
		mBullets[i] = nullptr;
	}
	mBullets.clear();
}

Bullet* BulletPool::GetBullet()
{
	Bullet* bullet = mBullets[mNextAvalibleIndex];
	mNextAvalibleIndex = (mNextAvalibleIndex + 1) % mBullets.size();
	return bullet;
}

std::vector<Bullet*>& BulletPool::GetBullets()
{
	return mBullets;
	// TODO: insert return statement here
}
