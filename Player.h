#pragma once
#include <Novice.h>
#include "Vector2.h"
#include "Bullet.h"
#include "vector"

class Player{
private:

	Vector2 pos_;
	float radius_;
	float speed_;

	Bullet* bullet_;
	std::vector<Bullet*> bulletArry_;


public:

	Player();
	~Player();

	void Init();
	void Update(char* keys, char* preKeys);
	void Draw();

	void Move(char* keys);
	void Shot(char* keys, char* preKeys);

	std::vector<Bullet*> GetBulletArry() const { return bulletArry_; }
};

