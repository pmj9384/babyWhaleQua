#include "stdafx.h"
#include "ChaseMovement.h"
#include "Enemy.h"
#include "Player.h"


ChaseMovement::ChaseMovement(const std::string& name)
{
}

void ChaseMovement::Update(float dt, Enemy* enemy, Player* player)
{
    if (player == nullptr)
    {
        return;
    }

    sf::Vector2f playerPos = player->GetPosition();
    sf::Vector2f enemyPos = enemy->GetPosition();
    float speed = enemy->GetSpeed();

    speed = 0.8f;

    const float MIN_DISTANCE = 150.0f; // 최소거리 
    const float MAX_DISTANCE = 300.0f; //최대거리
    float distance = Utils::Distance(playerPos, enemyPos);
    if (distance > MAX_DISTANCE)
    {
        return;
    }

    // 플레이어가 너무 가까이 있으면 이동 중지
    if (distance < MIN_DISTANCE)
    {
        return;
    }

    sf::Vector2f direction = Utils::GetNormal(playerPos - enemyPos);

    if (std::isnan(direction.x) || std::isnan(direction.y)) //비정상 이동 방지 적의 위치가 같아서 방향 벡터가 계산 불가능한 상황
    {       
        return;
    }

    enemy->SetDirection(direction);
    enemy->SetPosition(enemyPos + direction * speed * dt);

}
