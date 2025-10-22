#pragma once
#include"Entity.h"
#include"BulletPool.h"

class Ship : public Entity
{
public:
	Ship();
	~Ship() override;

	void Load() override;
	void Update(float deltatime) override;
	void Render() override;
	void Unload() override;


private:
	X::TextureId mImageID = 0;
	X::Math::Vector2 mPosition;
	float mRotation;
	
	BulletPool mbulletPool;
};

