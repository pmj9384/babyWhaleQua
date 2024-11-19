#include "stdafx.h"
#include "Player.h"
#include "SceneGame.h"
#include "DebugBox.h"
#include "Item.h"

Player::Player(const std::string& name)
	: GameObject(name)
{

}

void Player::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Player::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(angle);
}

void Player::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(s);
}

void Player::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(body, originPreset);
	}
}

void Player::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	body.setOrigin(origin);
}

void Player::Init()
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;
	SetOrigin(Origins::MC);
	SetPosition({ 1920.f * 0.5f, 1080.f * 0.5f });
	int maxHp = 100;
	int hp = maxHp;
	/*healthBar.setFillColor(sf::Color::Red);
	healthBar.setSize(sf::Vector2f(static_cast<float>(hp) / maxHp * 300.f, 80.f));
	healthBar.setPosition(position.x - healthBar.getSize().x / 2, position.y + body.getGlobalBounds().height / 2 + 600.f);*/
}

void Player::Release()
{
}

void Player::Reset()
{
	sf::Vector2f windowSize(1920.f, 1080.f);
	sf::Vector2f offset = windowSize * 0.5f;
	sceneGame = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());

	body.setTexture(TEXTURE_MGR.Get(textureId), true);
	SetOrigin(originPreset);
	SetPosition({ 500.f,450.f });
	SetRotation(0.f);
	direction = { 1.f, 0.f };
	hp = maxHp; // 체력을 최대치로 리셋
	UpdateHealthBar();


	maxHealth = 100;
	runSpeed = 1.0f;

}

void Player::Update(float dt)
{
	direction.x = InputMgr::GetAxis(Axis::Horizontal);
	direction.y = InputMgr::GetAxis(Axis::Vertical);
	float mag = Utils::Magnitude(direction);
	if (mag > 1.f)
	{
		Utils::Normalize(direction);
	}
	if (direction.x != 0.f)
	{
		SetScale(direction.x > 0.f ? sf::Vector2f(1.0f, 1.0f) : sf::Vector2f(-1.f, 1.0f));
	}

	if (isInvincible)
	{
		invincibleTimer -= dt;
		if (invincibleTimer <= 0.0f) {
			isInvincible = false;
			invincibleTimer = 0.0f;
			std::cout << "Player is no longer invincible." << std::endl;
		}
	}

	healthDecreaseTimer += dt;
	if (healthDecreaseTimer >= decreaseInterval)
	{
		healthDecreaseTimer -= decreaseInterval; // 타이머 초기화
		OnDamage(1); // 체력 1 감소
		std::cout << "Health decreased by 1. Current HP: " << hp << std::endl;
	}

	SetPosition(position + direction * speed * dt);
	debugBox.SetBounds(body.getGlobalBounds());
	UpdateHealthBar();
	speed = 500.f;
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	//window.draw(healthBar);
	debugBox.Draw(window);
}



void Player::AttackEnemy(Enemy* enemy)
{
	if (enemy != nullptr && enemy->IsActive())
	{
		// 이미 처리한 적이라면 무시
		if (enemy == lastCollidedEnemy)
		{
			std::cout << "AttackEnemy: Already processed this enemy. Ignoring." << std::endl;
			return;
		}

		enemy->OnDamage(attackDamage); // 적에게 데미지 전달

		if (CanCatchEnemy(enemy->GetType()))
		{
			int restoreAmount = enemy->GetHealthRestore();
			IncreaseHealth(restoreAmount); // 체력 회복
			std::cout << "AttackEnemy: Restored health: " << restoreAmount << std::endl;
		}

		// 적을 비활성화
		enemy->SetActive(false);

		// 마지막으로 처리한 적 갱신
		lastCollidedEnemy = enemy;
	}
}

void Player::UpdateHealthBar()
{
	float healthRatio = static_cast<float>(hp) / maxHp;
	healthBar.setFillColor(sf::Color::Red);

	// 체력바 크기 설정
	healthBar.setSize(sf::Vector2f(healthRatio * 300.f, 80.f));

	// 체력바의 원점을 오른쪽 끝으로 설정
	healthBar.setOrigin(300.f, 0.f);

	// 체력바 위치를 플레이어 기준으로 설정하여 따라오게 함
	healthBar.setPosition(position.x - 600.f, position.y + body.getGlobalBounds().height / 2 - 550.f);
}

void Player::FixedUpdate(float dt)
{
	if (sceneGame == nullptr)
		return;


	const auto& enemyList = sceneGame->GetEnemyList();

	for (auto enemy : enemyList)
	{
		if (!enemy->IsActive())
			continue;

		auto playerPoints = Utils::GetShapePoints(body);
		auto enemyPoints = Utils::GetShapePoints(enemy->GetBody());

		const sf::Transform& playerTransform = body.getTransform();
		const sf::Transform& enemyTransform = enemy->GetBody().getTransform();

		if (Utils::PolygonsIntersect(playerPoints, playerTransform, enemyPoints, enemyTransform))
		{
			// 이미 처리된 적이면 무시
			if (enemy == lastCollidedEnemy)
			{
				std::cout << "Already processed this enemy. Ignoring." << std::endl;
				continue;
			}

			// 충돌 처리
			if (CanCatchEnemy(enemy->GetType()))
			{
				OnCollisionWithEnemy(enemy);
			}
			else
			{
				OnDamage(enemy->GetDamage()); // 플레이어가 적에게 데미지를 받음
				enemy->Deactivate(0.2f);
			}

			// 마지막 충돌한 적 갱신
			lastCollidedEnemy = enemy;
			break; // 한 번의 충돌만 처리
		}
		
		if (lastCollidedEnemy != nullptr)
		{
			auto enemyPoints = Utils::GetShapePoints(lastCollidedEnemy->GetBody());
			const sf::Transform& enemyTransform = lastCollidedEnemy->GetBody().getTransform();

			if (!Utils::PolygonsIntersect(Utils::GetShapePoints(body), body.getTransform(), enemyPoints, enemyTransform))
			{
				// 충돌 범위를 벗어나면 초기화
				lastCollidedEnemy = nullptr;
				std::cout << "Resetting lastCollidedEnemy after collision ended." << std::endl;
			}
		}
	}

	const auto& itemList = sceneGame->GetItemList();

	for (auto item : itemList)
	{
		if (!item->IsActive())
			continue;

		auto playerPoints = Utils::GetShapePoints(body);
		auto itemPoints = Utils::GetShapePoints(item->GetBody());

		const sf::Transform& playerTransform = body.getTransform();
		const sf::Transform& itemTransform = item->GetBody().getTransform();

		if (Utils::PolygonsIntersect(playerPoints, playerTransform, itemPoints, itemTransform))
		{

			OnPickup(item);  // 아이템을 획득
			item->SetActive(false);
			break;
		}
	}
}

void Player::OnDamage(int damageAmount)
{
	if (isInvincible) 
	{
		std::cout << "Player is invincible. No damage taken." << std::endl;
		return;
	}


	std::cout << "Damage taken: " << damageAmount << std::endl;
	hp -= damageAmount;
	if (hp <= 0)
	{
		hp = 0;
		sceneGame->OnPlayerDie(this);
	}
	UpdateHealthBar();
}

void Player::IncreaseHealth(int amount)
{
	hp += amount;
	if (hp > maxHp) // 체력이 최대치를 초과하지 않도록
	hp = maxHp;
	
	UpdateHealthBar();
}

void Player::OnPickup(Item* item)
{
	item->OnPickup(this);
	isInvincible = true;
	invincibleTimer = invincibleDuration;
	std::cout << "Player is now invincible for " << invincibleDuration << " seconds." << std::endl;
}

void Player::SetAllowedEnemyTypes(const std::vector<Enemy::Types>& types)
{
	allowedEnemyTypes = types;
}

bool Player::CanCatchEnemy(Enemy::Types enemyType) const
{
	for (const auto& allowedType : allowedEnemyTypes)
	{
		if (allowedType == enemyType)
		{
			return true; // 플레이어가 잡을 수 있는 적의 타입이면 true
		}
	}
	return false;
}

void Player::ConsumeEnemy(Enemy* enemy)
{
	if (enemy != nullptr && enemy->IsActive())
	{
		// 적에게 데미지를 전달
		std::cout << "ConsumeEnemy: Attacking enemy." << std::endl;
		AttackEnemy(enemy);

		// 적이 비활성화되었으면 체력 회복
		if (!enemy->IsActive())
		{
			int restoreAmount = enemy->GetHealthRestore();
			std::cout << "ConsumeEnemy: Enemy is inactive. Restoring health: " << restoreAmount << std::endl;
			IncreaseHealth(restoreAmount);
		}
		else
		{
			std::cout << "ConsumeEnemy: Enemy is still active!" << std::endl;
		}
	}
}

void Player::OnCollisionWithEnemy(Enemy* enemy)
{
	if (enemy == nullptr || !enemy->IsActive())
		return;

	// 적의 타입이 섭취 가능한지 확인
	if (CanCatchEnemy(enemy->GetType()))
	{
		std::cout << "OnCollisionWithEnemy: Consuming enemy." << std::endl;
		ConsumeEnemy(enemy);
	}
	else
	{
		// 적이 섭취 불가능한 경우 플레이어에게 피해
		int damage = enemy->GetDamage();
		std::cout << "OnCollisionWithEnemy: Taking damage from enemy. Damage: " << damage << std::endl;
		OnDamage(damage);

		// 적을 비활성화
		enemy->Deactivate(0.2f);
	}
}






