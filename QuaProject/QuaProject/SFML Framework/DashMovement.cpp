#include "stdafx.h"
#include "DashMovement.h"
#include "Enemy.h"
#include "Player.h"

DashMovement::DashMovement(const std::string& name)
{
}

void DashMovement::Update(float dt, Enemy* enemy, Player* player)
{
    dashTimer += dt;

    if (dashTimer >= dashInterval)
    {
        isDashing = true;
        dashTimer = 0.f;
    }

    if (isDashing)
    {
        sf::Vector2f dashDirection = Utils::GetNormal(player->GetPosition() - enemy->GetPosition());
        if (std::isnan(dashDirection.x) || std::isnan(dashDirection.y))
        {

            return;
        }

        enemy->SetDirection(dashDirection);
        enemy->SetPosition(enemy->GetPosition() + dashDirection * (enemy->GetSpeed() * 3.f) * dt); // 3배 속도로 돌진
        isDashing = false;

    }
    else
    {
        // 기본 이동
        enemy->SetPosition(enemy->GetPosition() + enemy->GetDirection() * enemy->GetSpeed() * dt);
    }
}
