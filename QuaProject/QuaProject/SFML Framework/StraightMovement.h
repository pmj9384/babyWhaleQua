#pragma once
#include "MovementPattern.h"
class StraightMovement :  public MovementPattern
{
public:
	StraightMovement(const std::string& name = "");
	~StraightMovement() = default;
	void Update(float dt, Enemy* enemy, Player* player) override;
};

