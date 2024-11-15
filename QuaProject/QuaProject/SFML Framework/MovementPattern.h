#pragma once

class Enemy;
class Player;

class MovementPattern
{

public:
	virtual ~MovementPattern() = default;
	virtual void Update(float dt, Enemy* enemy, Player* player) = 0;
};

