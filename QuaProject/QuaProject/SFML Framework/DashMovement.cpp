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

    // 2�� ���� ��� �ӵ� ����
    if (dashTimer >= dashInterval && !isDashing)
    {
        isDashing = true;  // ��� ����
        dashTimer = 0.f;   // Ÿ�̸� �ʱ�ȭ
    }

    if (isDashing)
    {
        // ��� �ӵ� ����
        enemy->SetPosition(enemy->GetPosition() + enemy->GetDirection() * enemy->GetSpeed() * dashSpeedMultiplier * dt);

        // 2�� ��� ��, ���� �ӵ��� ���ư���
        if (dashTimer >= dashInterval)
        {
            isDashing = false;
            dashTimer = 0.f;  // Ÿ�̸� �ʱ�ȭ
        }
    }
    else
    {
        // �⺻ �ӵ�
        enemy->SetPosition(enemy->GetPosition() + enemy->GetDirection() * enemy->GetSpeed() * dt);
    }
}
