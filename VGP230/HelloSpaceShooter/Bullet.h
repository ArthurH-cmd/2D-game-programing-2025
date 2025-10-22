#pragma once

#include "Entity.h"

class Bullet : public Entity
{
public:
	Bullet();
	~Bullet() override;

	void Load() override;
	void Update(float deltatime) override;
	void Render() override;
	void Unload() override;

	void SetActive(const X::Math::Vector2& pos, float rotation, float lifetime = 2.0f);
	bool IsActive() const;

private:

	X::TextureId mImageID;
	X::Math::Vector2 mPosition;
	float mRotation;
	float mLifeTime;

};


