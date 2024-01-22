#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

class Collision{
private:

	Player* player_;

public:

	Collision(Player* player);
	~Collision();

	void Update(Enemy* enemy);

};

