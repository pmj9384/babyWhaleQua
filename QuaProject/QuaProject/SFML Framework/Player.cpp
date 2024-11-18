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
	hp = maxHp; // ü���� �ִ�ġ�� ����
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
		enemy->OnDamage(attackDamage); // ������ ������ ����
	}
}

void Player::UpdateHealthBar()
{
	float healthRatio = static_cast<float>(hp) / maxHp;
	healthBar.setFillColor(sf::Color::Red);

	// ü�¹� ũ�� ����
	healthBar.setSize(sf::Vector2f(healthRatio * 300.f, 80.f));

	// ü�¹��� ������ ������ ������ ����
	healthBar.setOrigin(300.f, 0.f);

	// ü�¹� ��ġ�� �÷��̾� �������� �����Ͽ� ������� ��
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
			if (CanCatchEnemy(enemy->GetType()))
			{
				AttackEnemy(enemy); // Enemy���� ������ �ֱ�
				break; // �� ���� �浹�� ó��
			}
			else
			{
				OnDamage(enemy->GetDamage()); // �÷��̾ ������ �������� ����
				enemy->Deactivate(0.2f);
			}
			break; // �� ���� �浹�� ó��
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

			OnPickup(item);  // �������� ȹ��
			item->SetActive(false);
			break;
		}
	}
}

void Player::OnDamage(int damageAmount)
{
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
	if (hp > maxHp) // ü���� �ִ�ġ�� �ʰ����� �ʵ���
	hp = maxHp;
	
	UpdateHealthBar();
}




void Player::OnPickup(Item* item)
{
	item->OnPickup(this);
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
			return true; // �÷��̾ ���� �� �ִ� ���� Ÿ���̸� true
		}
	}
	return false;
}






