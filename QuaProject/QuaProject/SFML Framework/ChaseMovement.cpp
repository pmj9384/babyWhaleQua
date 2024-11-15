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

    const float MIN_DISTANCE = 150.0f; // �ּҰŸ� 
    const float MAX_DISTANCE = 300.0f; //�ִ�Ÿ�
    float distance = Utils::Distance(playerPos, enemyPos);
    if (distance > MAX_DISTANCE)
    {
        return;
    }

    // �÷��̾ �ʹ� ������ ������ �̵� ����
    if (distance < MIN_DISTANCE)
    {
        return;
    }

    sf::Vector2f direction = Utils::GetNormal(playerPos - enemyPos);

    if (std::isnan(direction.x) || std::isnan(direction.y)) //������ �̵� ���� ���� ��ġ�� ���Ƽ� ���� ���Ͱ� ��� �Ұ����� ��Ȳ
    {       
        return;
    }

    enemy->SetDirection(direction);
    enemy->SetPosition(enemyPos + direction * speed * dt);

}
