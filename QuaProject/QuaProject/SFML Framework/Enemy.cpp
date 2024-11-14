#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "EnemyTable.h"
Enemy::Enemy(const std::string& name) : GameObject(name)
{
	SortingLayers sortingLayer = SortingLayers::Foreground;
	int sortingOrder = 1;
}

sf::FloatRect Enemy::GetLocalBounds() const
{
	return body.getLocalBounds();
}

sf::FloatRect Enemy::GetGlobalBounds() const
{
	return body.getGlobalBounds();
}

void Enemy::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Enemy::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void Enemy::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Enemy::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(body, originPreset);
	}
}

void Enemy::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	body.setOrigin(origin);
}

void Enemy::Init()
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;

	SetType(types);

}

void Enemy::Release()
{
}

void Enemy::Reset()
{
	speed = Utils::RandomRange(min_speed, max_speed);
	const float screenWidth = 1920.f;
	const float screenHeight = 1080.f;

	// 적의 크기
	sf::FloatRect enemyBounds = body.getGlobalBounds();

	// 무작위로 왼쪽 또는 오른쪽에서 생성
	if (Utils::RandomRange(0, 1) == 0) {
		// 왼쪽에서 생성
		position = sf::Vector2f(-enemyBounds.width, Utils::RandomRange(0.f, screenHeight));
		direction = sf::Vector2f(1.f, 0.f); // 오른쪽으로 이동
	}
	else {
		// 오른쪽에서 생성
		position = sf::Vector2f(screenWidth, Utils::RandomRange(0.f, screenHeight));
		direction = sf::Vector2f(-1.f, 0.f); // 왼쪽으로 이동
	}

	SetPosition(position);
	this->direction = direction;
}

void Enemy::Update(float dt)
{
	if (active)
	{
		position += direction * speed * dt;
		SetPosition(position);

		// 화면을 벗어났는지 확인
		if (!IsWithinBounds())
		{
			// 적을 비활성화하거나 제거하는 로직 추가
			active = false;
			// 또는 필요에 따라 적을 제거하는 코드 추가
		}
	}
	else
	{
		deactivateTimer += dt;
		if (deactivateTimer >= deactivateTime)
		{
			active = true;
			deactivateTimer = 0.f;
			Reset(); // 비활성화 기간이 끝나면 다시 초기화
		}
	}
}


void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

bool Enemy::IsWithinBounds() const
{
	sf::FloatRect globalBounds = body.getGlobalBounds();

	// 화면 크기
	const float screenWidth = 1920.f;
	const float screenHeight = 1080.f;

	// 적이 화면을 벗어났는지 확인
	if (globalBounds.left + globalBounds.width < 0 || // 왼쪽으로 벗어남
		globalBounds.left > screenWidth ||            // 오른쪽으로 벗어남
		globalBounds.top + globalBounds.height < 0 || // 위로 벗어남
		globalBounds.top > screenHeight)              // 아래로 벗어남
	{
		return false;
	}
	return true;
}

void Enemy::SetType(Types type)
{

	this->types = type; // 타입저장
	const auto& data = ENEMY_TABLE->Get(type);
	textureId = data.textureId;
	min_speed = data.min_speed;
	max_speed = data.max_speed;
	damage = data.damage;

	body.setTexture(TEXTURE_MGR.Get(textureId));
}

void Enemy::OnDamage(int damage)
{
}

void Enemy::Deactivate(float duration)
{
	active = false;
	deactivateTime = duration; // 비활성화 유지 시간 설정
	deactivateTimer = 0.f;
}
