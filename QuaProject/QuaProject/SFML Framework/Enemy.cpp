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


	directionChangeInterval = 8.f; // 5초마다 방향 변경
	directionChangeTimer = 0.f;
	SetType(types);

}

void Enemy::Release()
{
}

void Enemy::Reset()
{
	// SceneGame 확인
	if (scenegame == nullptr)
	{
		scenegame = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());
	}

	// 랜덤 스폰 위치와 방향 설정
	if (scenegame)
	{
		if (Utils::RandomRange(0, 1) == 0)
		{
			position = scenegame->spawn1.Spawn();
			direction = sf::Vector2f(1.f, 0.f); // 오른쪽으로 이동
		}
		else
		{
			position = scenegame->spawn2.Spawn();
			direction = sf::Vector2f(-1.f, 0.f); // 왼쪽으로 이동
		}
	}
	else
	{
		position = { 0.f, 0.f };
		direction = { 0.f, 0.f };
	}

	// 초기 상태 설정
	SetPosition(position);
	this->direction = direction;

	hp = maxHp;                // 체력 초기화
	isActive = false;          // 비활성화 상태
	canAttack = true;          // 공격 가능 상태 초기화
	deactivateTimer = 0.f;     // 비활성화 타이머 초기화
	directionChangeTimer = 0.f; // 방향 변경 타이머 초기화

	if (movementPattern)
	{
		delete movementPattern; // 이동 패턴 초기화 (필요 시)
		movementPattern = nullptr;
	}

	std::cout << "Enemy 리셋 완료. 초기 상태로 설정되었습니다." << std::endl;
}


void Enemy::Update(float dt)
{
	if (!active)
		return;

	// 비활성화된 적은 업데이트하지 않음
	if (!canAttack)
	{
		deactivateTimer += dt;
		if (deactivateTimer >= deactivateTime)
		{
			canAttack = true; // 비활성화 시간이 지나면 다시 활성화
		}
	}
	static bool hasReachedCenter = false;

	// 중심에 가까운지 판단 (100.f은 중심 근처라고 판단하는 거리)
	if (!hasReachedCenter)
	{
		sf::Vector2f screenCenter = { player->GetPosition().x, player->GetPosition().y }; // 화면 중심 (플레이어 기준)
		float distanceToCenter = std::abs(position.x - screenCenter.x);

		// 중심에 가까운지 판단 (100.f은 중심 근처라고 판단하는 거리)
		if (distanceToCenter < 100.f)
		{
			hasReachedCenter = true; // 중앙 도달 플래그 설정
		}
		else
		{
			// 화면 중심으로 향하도록 방향 설정
			direction = position.x < screenCenter.x ? sf::Vector2f(1.f, 0.f) : sf::Vector2f(-1.f, 0.f);
		}
	}
	else
	{
		// 중심에 도달한 이후에는 자유롭게 움직임
		directionChangeTimer += dt;
		if (directionChangeTimer >= directionChangeInterval)
		{
			directionChangeTimer = 0.f;
			bool shouldChangeDirection = Utils::RandomRange(0, 1) == 0;
			if (shouldChangeDirection)
			{
				direction = sf::Vector2f(-direction.x, 0.f); // 방향 반전
			}
		}
	}
	if (direction.x != 0.f)
	{
		SetScale({ direction.x > 0.f ? 1.f : -1.f, 1.f });
		body.setOrigin(body.getLocalBounds().width / 2.f, body.getLocalBounds().height / 2.f);
	}

	position += direction * speed * dt;
	SetPosition(position);

	if (movementPattern)
	{
		movementPattern->Update(dt, this, player);
	}
	
}



void Enemy::Draw(sf::RenderWindow& window)
{
	if (!active) // 활성화된 경우에만 그리기
		return;
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
	speed = data.speed;
	damage = data.damage;
	healthRestore = data.healthRestore;

	const sf::Texture& tex = TEXTURE_MGR.Get(textureId);
	body.setTexture(tex);
	body.setTextureRect({ 0, 0, (int)tex.getSize().x, (int)tex.getSize().y });

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

void Enemy::SetSceneGame(SceneGame* game)
{
	scenegame = game;
}

void Enemy::OnDamage(int damage)
{
	hp -= damage;
	std::cout << "OnDamage: Enemy " << this << " 체력 감소, 남은 체력: " << hp << std::endl;
	if (hp <= 0)
	{
		//hp = 0;
		std::cout << "OnDamage: Enemy " << this << " 체력 0, SetActive(false) 호출" << std::endl;

	}
}

void Enemy::SetActive(bool isActive)
{
	//if (this->active == isActive) // 상태가 동일하면 무시
	//	return;

	//this->active = isActive;
	
	if (isActive)
	{
		std::cout << "Enemy 활성화됨. Obj 주소 = " << this << std::endl;
	}
	else
	{
		std::cout << "Enemy 비활성화됨. Obj 주소 = " << this << std::endl;

		if (scenegame)
		{
			std::cout << "SetActive: RemoveGo 호출 시작" << std::endl;
			scenegame->RemoveGo(this);
			std::cout << "SetActive: RemoveGo 호출 완료" << std::endl;

			std::cout << "SetActive: Return 호출 시작" << std::endl;
			scenegame->GetEnemyPool().Return(this);
			std::cout << "SetActive: Return 호출 완료" << std::endl;
		}
		else
		{
			std::cout << "SetActive: scenegame이 nullptr입니다!" << std::endl;
		}
	}
}

void Enemy::Deactivate(float duration)
{
	canAttack = false;
	deactivateTime = duration; // 비활성화 유지 시간 설정
	deactivateTimer = 0.f;
}

void Enemy::SetDirection(const sf::Vector2f& dir)
{
	direction = dir;
}

void Enemy::AddMovementPattern(MovementPattern* pattern)
{
	// 기존 패턴 삭제
	if (movementPattern)
	{
		delete movementPattern;
	}
	// 새 패턴 추가
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

int Enemy::GetHp() const
{
	return hp;
}

int Enemy::GetHealthRestore() const
{
	return healthRestore;
}

void Enemy::SetPlayer(Player* p)
{
	player = p;
}




