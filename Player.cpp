#include "Player.h"

Player::Player(){
	Init();
}

Player::~Player(){
	bulletArry_.clear();
}

void Player::Init(){
	pos_ = { 640.0f, 500.0f };
	radius_ = 30.0f;
	speed_ = 5.0f;

}

void Player::Update(char* keys, char* preKeys){
	Move(keys);
	Shot(keys, preKeys);

	// bullet ---------------------------------------------
	for (int oi = 0; oi < bulletArry_.size(); oi++) {
		bulletArry_[oi]->Update();
	}
}

void Player::Draw(){
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f,
		0x90EE90FF,
		kFillModeSolid
	);

	// bullet ---------------------------------------------
	for (int oi = 0; oi < bulletArry_.size(); oi++) {
		bulletArry_[oi]->Draw();
	}
}

void Player::Move(char* keys){
	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}

	if (keys[DIK_D]) {
		pos_.x += speed_;
	}

	if (keys[DIK_W]) {
		pos_.y -= speed_;
	}

	if (keys[DIK_S]) {
		pos_.y += speed_;
	}
}

void Player::Shot(char* keys, char* preKeys){
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		bullet_ = new Bullet(pos_);
		bulletArry_.push_back(bullet_);
	}
}
