#include "stdafx.h"
#include "SleepMovement.h"



SleepMovement::SleepMovement(const std::string& name)
{

}

void SleepMovement::Update(float dt, Enemy* enemy, Player* player)
{
    sleepTimer += dt;

    if (isSleeping)
    {
        // ���� �ӵ��� ������ ����
        float slowSpeed = enemy->GetSpeed() * 0.05f;
        sf::Vector2f newPosition = enemy->GetPosition() + enemy->GetDirection() * slowSpeed * dt;
        enemy->SetPosition(newPosition);


        // ���� ���� �ð��� ������ ����
        if (sleepTimer >= sleepDuration)
        {
            sleepTimer = 0.0f;
            isSleeping = false;

        }
    }
    else
    {
        // �⺻ �̵�
        sf::Vector2f normalPosition = enemy->GetPosition() + enemy->GetDirection() * enemy->GetSpeed() * dt;
        enemy->SetPosition(normalPosition);

        // ���� ���·� ��ȯ
        if (sleepTimer >= sleepInterval)
        {
            sleepTimer = 0.0f;
            isSleeping = true;
            sleepInterval = static_cast<float>(Utils::RandomRange(3, 5)); // 3~5�� ������ ���ο� ���͹�
        }
    }
}
