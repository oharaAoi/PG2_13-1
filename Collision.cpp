#include "Collision.h"

Collision::Collision(Player* player){
	player_ = player;
}

Collision::~Collision(){
}

void Collision::Update(Enemy* enemy){
	for (int i = 0; i < player_->GetBulletArry().size(); i++) {
		Vector2 distance = {
			enemy->GetPos().x - player_->GetBulletArry()[i]->GetPos().x,
			enemy->GetPos().y - player_->GetBulletArry()[i]->GetPos().y,
		};

		float length = sqrtf(powf(distance.x, 2) + powf(distance.y, 2));

		if (enemy->GetRadius() + player_->GetBulletArry()[i]->GetRadius() > length) {
			Enemy::SetIsAlive(false);
		}
	}
}
