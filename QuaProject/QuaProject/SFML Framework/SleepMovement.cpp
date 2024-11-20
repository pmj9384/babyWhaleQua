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
        // 적의 속도를 느리게 설정
        float slowSpeed = enemy->GetSpeed() * 0.05f;
        sf::Vector2f newPosition = enemy->GetPosition() + enemy->GetDirection() * slowSpeed * dt;
        enemy->SetPosition(newPosition);


        // 슬립 지속 시간이 지나면 복구
        if (sleepTimer >= sleepDuration)
        {
            sleepTimer = 0.0f;
            isSleeping = false;

        }
    }
    else
    {
        // 기본 이동
        sf::Vector2f normalPosition = enemy->GetPosition() + enemy->GetDirection() * enemy->GetSpeed() * dt;
        enemy->SetPosition(normalPosition);

        // 슬립 상태로 전환
        if (sleepTimer >= sleepInterval)
        {
            sleepTimer = 0.0f;
            isSleeping = true;
            sleepInterval = static_cast<float>(Utils::RandomRange(3, 5)); // 3~5초 사이의 새로운 인터벌
        }
    }
}
