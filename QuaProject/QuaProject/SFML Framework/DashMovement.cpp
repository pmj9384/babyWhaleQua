#include "stdafx.h"
#include "DashMovement.h"
#include "Enemy.h"
#include "Player.h"

DashMovement::DashMovement(const std::string& name)
    : dashTimer(0.f), dashInterval(2.f), isDashing(false), dashSpeedMultiplier(2.f)
{
}

void DashMovement::Update(float dt, Enemy* enemy, Player* player)
{
    dashTimer += dt;

    // 2초 동안 대시 속도 증가
    if (dashTimer >= dashInterval && !isDashing)
    {
        isDashing = true;  // 대시 시작
        dashTimer = 0.f;   // 타이머 초기화
    }

    if (isDashing)
    {
        // 대시 속도 적용
        enemy->SetPosition(enemy->GetPosition() + enemy->GetDirection() * enemy->GetSpeed() * dashSpeedMultiplier * dt);

        // 2초 대시 후, 원래 속도로 돌아가기
        if (dashTimer >= dashInterval)
        {
            isDashing = false;
            dashTimer = 0.f;  // 타이머 초기화
        }
    }
    else
    {
        // 기본 속도
        enemy->SetPosition(enemy->GetPosition() + enemy->GetDirection() * enemy->GetSpeed() * dt);
    }
}
