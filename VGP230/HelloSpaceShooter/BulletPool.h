#pragma once

#include "Entity.h"


class Bullet;

class BulletPool : public Entity
{
public:
	BulletPool();
	~BulletPool() override;

	void Load() override;
	void Update(float deltatime) override;
	void Render() override;
	void Unload() override;

	Bullet* GetBullet();
	std::vector<Bullet*>& GetBullets();
private:
	int mNextAvalibleIndex = 0;
	std::vector<Bullet*> mBullets;

};
