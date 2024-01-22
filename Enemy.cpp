#include "Enemy.h"

bool Enemy::isAlive_ = true;

Enemy::Enemy(Vector2 pos){
	Init(pos);
}

Enemy::~Enemy(){
}

void Enemy::Init(Vector2 pos){
	pos_ = pos;
	radius_ = 20.0f;
	speed_ = 3.0f;
}

void Enemy::Update(){
	if (isAlive_) {
		pos_.x += speed_;

		if (pos_.x < 0 || pos_.x + radius_ > 1280) {
			speed_ *= -1;
		}
	}
}

void Enemy::Draw(){
	if (isAlive_) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(radius_),
			static_cast<int>(radius_),
			0.0f,
			0xDC143CFF,
			kFillModeSolid
		);
	}
}
