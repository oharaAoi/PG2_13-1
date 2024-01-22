#pragma once
#include "Vector2.h"
#include <Novice.h>

class Enemy{
private:

	Vector2 pos_;
	float radius_;
	float speed_;

	static bool isAlive_;

public:

	Enemy(Vector2 pos);
	~Enemy();

	void Init(Vector2 pos);
	void Update();
	void Draw();

	Vector2 GetPos() const { return pos_; }
	float GetRadius() const { return radius_; }

	static void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }
};

