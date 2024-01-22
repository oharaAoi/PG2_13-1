#include "Bullet.h"

Bullet::Bullet(Vector2 pos){
	Init(pos);
}

Bullet::~Bullet(){
}

void Bullet::Init(Vector2 pos){
	pos_ = pos;
	radius_ = 10;
	speed_ = 8;
	isAlive_ = true;
}

void Bullet::Update(){
	pos_.y -= speed_;
}

void Bullet::Draw(){
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f,
		0x87CEEBFF,
		kFillModeSolid
	);
}
