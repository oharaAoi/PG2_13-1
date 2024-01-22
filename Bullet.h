#pragma once
#include <Novice.h>
#include "Vector2.h"

class Bullet{
private:

	Vector2 pos_;
	float radius_;
	float speed_;
	bool isAlive_;

public:

	Bullet(Vector2 pos);
	~Bullet();

	void Init(Vector2 pos);
	void Update();
	void Draw();

	Vector2 GetPos() const { return pos_; }
	bool GetIsAlive() const { return isAlive_; }
	float GetRadius() const { return radius_; }
};

