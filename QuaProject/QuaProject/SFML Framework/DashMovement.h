#pragma once
#include "MovementPattern.h"

class DashMovement : public MovementPattern
{
private:

    float dashTimer = 0.f;
    float dashInterval = 5.f; // 5초마다 돌진
    bool isDashing = false;

public:
    DashMovement(const std::string& name = "");
    ~DashMovement() = default;
    void Update(float dt, Enemy* enemy, Player* player) override;
};
