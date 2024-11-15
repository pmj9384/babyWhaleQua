#pragma once
#include "MovementPattern.h"
class ChaseMovement : public MovementPattern
{
public:
	ChaseMovement(const std::string& name = "");
	~ChaseMovement() = default;
	void Update(float dt, Enemy* enemy, Player* player) override;
};

