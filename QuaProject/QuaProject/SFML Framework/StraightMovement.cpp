#include "stdafx.h"
#include "StraightMovement.h"

StraightMovement::StraightMovement(const std::string& name)
{
}

void StraightMovement::Update(float dt, Enemy* enemy, Player* player)
{
	sf::Vector2f direction = enemy->GetDirection();
	enemy->SetPosition(enemy->GetPosition() + direction * enemy->GetSpeed() * dt);
}
