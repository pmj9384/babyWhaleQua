#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "EnemyTable.h"
#include "SpawnArea.hpp"
#include "MovementPattern.h"
#include "StraightMovement.h"
#include "RandomMovement.h"
#include "DashMovement.h"
#include "ChaseMovement.h"
#include "SleepMovement.h"
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

	directionChangeInterval = 8.f; // 5�ʸ��� ���� ����
	directionChangeTimer = 0.f;
	SetType(types);

}

void Enemy::Release()
{
}

void Enemy::Reset()
{
	// scenegame�� nullptr���� Ȯ���ϰ�, nullptr�̸� �������� ����
	if (scenegame == nullptr) {
		scenegame = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());
		if (scenegame == nullptr) {
			// ���� scenegame�� nullptr�̸� �⺻ ��ġ ���� �� ��ȯ
			position = { 0.f, 0.f };
			direction = sf::Vector2f(1.f, 0.f);
			SetPosition(position);
			return;
		}
	}


	// ���� �Ǵ� ������ SpawnArea �� �ϳ����� ���� ��ġ ��������
	if (Utils::RandomRange(0, 1) == 0) {
		position = scenegame->spawn1.Spawn(); // ���� SpawnArea���� ����
		direction = sf::Vector2f(1.f, 0.f); // ���������� �̵�
	}
	else {
		position = scenegame->spawn2.Spawn(); // ������ SpawnArea���� ����
		direction = sf::Vector2f(-1.f, 0.f); // �������� �̵�
	}

	SetPosition(position);
	this->direction = direction;
	directionChangeTimer = 0.f;
}

void Enemy::Update(float dt)
{
	if (active)
	{
		directionChangeTimer += dt;
		if (directionChangeTimer >= directionChangeInterval)
		{
			directionChangeTimer = 0.f;
			direction = Utils::RandomRange(0, 1) == 0 ? sf::Vector2f(1.f, 0.f) : sf::Vector2f(-1.f, 0.f);
		}
		if (direction.x != 0.f)
		{
			SetScale(direction.x > 0.f ? sf::Vector2f(1.0f, 1.0f) : sf::Vector2f(-1.f, 1.0f));
		}


		position += direction * speed * dt;
		SetPosition(position);
	}
	movementPattern->Update(dt, this, player);
	
}



void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

bool Enemy::IsWithinBounds() const
{
	sf::FloatRect globalBounds = body.getGlobalBounds();

	// ȭ�� ũ��
	const float screenWidth = 1920.f;
	const float screenHeight = 1080.f;

	// ���� ȭ���� ������� Ȯ��
	if (globalBounds.left + globalBounds.width < 0 || // �������� ���
		globalBounds.left > screenWidth ||            // ���������� ���
		globalBounds.top + globalBounds.height < 0 || // ���� ���
		globalBounds.top > screenHeight)              // �Ʒ��� ���
	{
		return false;
	}
	return true;
}

void Enemy::SetType(Types type)
{

	this->types = type; // Ÿ������
	const auto& data = ENEMY_TABLE->Get(type);
	textureId = data.textureId;
	speed = data.speed;
	damage = data.damage;
	speed = static_cast<float>(data.speed);
	body.setTexture(TEXTURE_MGR.Get(textureId));
	if (movementPattern)
	{
		delete movementPattern;
		movementPattern = nullptr;
	}
	switch (type)
	{
	case Types::smallFish:
		AddMovementPattern(new RandomMovement());
		break;
	case Types::redFish:
		AddMovementPattern(new StraightMovement());
		break;

	case Types::buleFish:
		AddMovementPattern(new SleepMovement());
		break;

	case Types::purpleFish:
		AddMovementPattern(new DashMovement());
		break;

	case Types::Shark:
		AddMovementPattern(new ChaseMovement());
		break;
	default:
		std::cout << "Unknown type, no movement pattern added." << std::endl;
		break;
	}
}

void Enemy::OnDamage(int damage)
{
}

void Enemy::Deactivate(float duration)
{
	active = false;
	deactivateTime = duration; // ��Ȱ��ȭ ���� �ð� ����
	deactivateTimer = 0.f;
}

void Enemy::SetDirection(const sf::Vector2f& dir)
{
	direction = dir;
}

void Enemy::AddMovementPattern(MovementPattern* pattern)
{
	// ���� ���� ����
	if (movementPattern)
	{
		delete movementPattern;
	}
	// �� ���� �߰�
	movementPattern = pattern;
}

sf::Vector2f Enemy::GetDirection() const
{
	return direction;
}

float Enemy::GetSpeed() const
{
	return speed;

}

void Enemy::SetPlayer(Player* p)
{
	player = p;
}




