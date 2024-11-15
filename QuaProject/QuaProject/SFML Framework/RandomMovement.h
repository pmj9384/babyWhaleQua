#pragma once
#include "MovementPattern.h"

class RandomMovement : public MovementPattern
{
private:

public:
    RandomMovement(const std::string& name = "");
    ~RandomMovement() = default;
    void Update(float dt, Enemy* enemy, Player* player) override;
};
