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
	//if (!textureId.empty())
	//{
	//	ChangeTexture(textureId);
	//}
	SetOrigin(originPreset);
	SetPosition({ 500.f,450.f });
	SetRotation(0.f);
	direction = { 1.f, 0.f };
	hp = maxHp; // ü���� �ִ�ġ�� ����
	UpdateHealthBar();
	isDead = false;
	//processedEnemies.clear(); // new
	//lastCollidedEnemy = nullptr; // new
	maxHealth = 100;
	runSpeed = 1.0f;
	SetActive(true);
}

void Player::Update(float dt)
{
	if (isDead)
	{
		// �÷��̾ ���� ��� �ٴ����� õõ�� �̵�
		deathTimer -= dt;
		if (deathTimer > 0)
		{
			position.y += deathSpeed * dt; // �״� �ӵ��� �Ʒ��� �̵�
		}
		else
		{
			// ���� ���°� ���� �� �߰� ó�� (�ʿ��ϴٸ�)
			isDead = false; // �� �̻� ������Ʈ���� ����
		}

		SetPosition(position);
		return; // ���� ���¿����� �ٸ� ������Ʈ�� �ߴ�
	}
	UpdateAnimation(dt); //animation

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

	if (hitRecoveryTimer > 0.f)
	{
		hitRecoveryTimer -= dt;
		if (hitRecoveryTimer <= 0.f)
		{
			hitRecoveryTimer = 0.f; // Hit ���� ����
		}
	}

	// �ִϸ��̼� ���� ó��
	if (recoveryTimer > 0.f) 
	{
		recoveryTimer -= dt;
		if (recoveryTimer <= 0.f) 
		{
			recoveryTimer = 0.f; // Eat ���� ����
		}
	}

	if (hitRecoveryTimer > 0.f)
	{
		PlayState("Hit"); // "Hit" ���� ����
	}
	else if (recoveryTimer > 0.f)
	{
		PlayState("Eat"); // "Eat" ���� ����
	}
	else
	{
		if (direction.x != 0.f || direction.y != 0.f)
		{
			PlayState("Run"); // �̵� ���̸� "Run"
		}
		else
		{
			PlayState("Idle"); // ���� ���¸� "Idle"
		}
	}
	if (isInvincible)
	{
		invincibleTimer -= dt;
		if (invincibleTimer <= 0.0f) {
			isInvincible = false;
			invincibleTimer = 0.0f;
			body.setColor(sf::Color(255, 255, 255, 255));
		}
	}

	healthDecreaseTimer += dt;
	if (healthDecreaseTimer >= decreaseInterval)
	{
		healthDecreaseTimer -= decreaseInterval; // Ÿ�̸� �ʱ�ȭ
		OnDamage(2); // ü�� 2 ����
	}

	SetPosition(position + direction * speed * dt);
	debugBox.SetBounds(body.getGlobalBounds());
	UpdateHealthBar();
	speed = 400.f;
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	//window.draw(healthBar);
	debugBox.Draw(window);
}



void Player::AttackEnemy(Enemy* enemy)
{
	if (isDead || enemy == nullptr || !enemy->IsActive())
	{
		return; // ���� �����̰ų� ��ȿ���� ���� ���̶�� ó�� �ߴ�
	}
	if (enemy != nullptr && enemy->IsActive())
	{
		// ���� ���� �� �ִٸ� ü�� ȸ��
		if (CanCatchEnemy(enemy->GetType()))
		{
			enemy->OnDamage(attackDamage);
			int restoreAmount = enemy->GetHealthRestore();
			IncreaseHealth(restoreAmount);  // ü�� ȸ��

			if (sceneGame)
			{
				sceneGame->OnEnemyDefeated(enemy->GetType());
			}
			enemy->SetActive(false);
			SOUND_MGR.PlaySfx("graphics/sounds/73_s_eat3.mp3", false);
			PlayState("Eat");
			recoveryTimer = eatAnimationDuration; //�Դ� �ִϸ��̼� �ð�
		}
		// ���������� ó���� �� ����
		lastCollidedEnemy = enemy;
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

	if (isDead)
	{
		return;
	}
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
			// �̹� ó���� ���̸� ����
			if (enemy == lastCollidedEnemy)
			{

				continue;
			}

			// �浹 ó��
			if (CanCatchEnemy(enemy->GetType()))
			{
				OnCollisionWithEnemy(enemy);
			}
			else
			{
			
				if (!isInvincible)
				{
					SOUND_MGR.PlaySfx("graphics/sounds/1_s_bomb2.mp3", false);
					PlayState("Hit");
					hitRecoveryTimer = hitAnimationDuration;
				}
				OnDamage(enemy->GetDamage()); // �÷��̾ ������ �������� ����
				enemy->Deactivate(0.2f);

			}

			// ������ �浹�� �� ����
			lastCollidedEnemy = enemy;
			break; // �� ���� �浹�� ó��
		}
		
		if (lastCollidedEnemy != nullptr)
		{
			auto enemyPoints = Utils::GetShapePoints(lastCollidedEnemy->GetBody());
			const sf::Transform& enemyTransform = lastCollidedEnemy->GetBody().getTransform();

			if (!Utils::PolygonsIntersect(Utils::GetShapePoints(body), body.getTransform(), enemyPoints, enemyTransform))
			{
				// �浹 ������ ����� �ʱ�ȭ
				lastCollidedEnemy = nullptr;

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

			OnPickup(item);  // �������� ȹ��
			item->SetActive(false);
			break;
		}
	}
}

void Player::OnDamage(int damageAmount)
{

	if (isInvincible) 
	{

		return;
	}

	hp -= damageAmount;
	if (hp <= 0)
	{
		hp = 0;
		isDead = true;
		deathTimer = deathDuration;
		PlayState("Die");
		if (sceneGame)
		{
			sceneGame->OnPlayerDie(this); // ���� ó�� ȣ��
		}
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
	isInvincible = true;
	invincibleTimer = invincibleDuration;

	body.setColor(sf::Color(255, 255, 255, 128));
	SOUND_MGR.PlaySfx("graphics/sounds/71_s_item.mp3", false);
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

void Player::ConsumeEnemy(Enemy* enemy)
{
	if (enemy != nullptr && enemy->IsActive())
	{
		// ������ �������� ����

		AttackEnemy(enemy);

		// ���� ��Ȱ��ȭ�Ǿ����� ü�� ȸ��
		if (!enemy->IsActive())
		{
			int restoreAmount = enemy->GetHealthRestore();

			IncreaseHealth(restoreAmount);
		}
		else
		{
		
		}
	}
}

void Player::OnCollisionWithEnemy(Enemy* enemy)
{
	if (enemy == nullptr || !enemy->IsActive())
		return;

	// ���� Ÿ���� ���� �������� Ȯ��
	if (CanCatchEnemy(enemy->GetType()))
	{

		ConsumeEnemy(enemy);
	}
	else
	{
		// ���� ���� �Ұ����� ��� �÷��̾�� ����
		int damage = enemy->GetDamage();

		OnDamage(damage);

		// ���� ��Ȱ��ȭ
		enemy->Deactivate(0.2f);
	}
}

void Player::ChangeTexture(const std::string& textureId)
{
	if (!textureId.empty() && TEXTURE_MGR.Load(textureId)) // �ؽ�ó �ε�
	{
		body.setTexture(TEXTURE_MGR.Get(textureId)); // �ؽ�ó ����
		const sf::Texture& tex = TEXTURE_MGR.Get(textureId); // 
		body.setTexture(tex);
		body.setTextureRect({ 0, 0, (int)tex.getSize().x, (int)tex.getSize().y });
	}
}

void Player::SetLevel(int level)
{
	std::string filePath = "animations/QuaLevel" + std::to_string(level) + ".csv";

	try {
		rapidcsv::Document doc(filePath);
		stateTextures.clear();

		for (size_t i = 0; i < doc.GetRowCount(); ++i) {
			std::string state = doc.GetCell<std::string>(0, i);       // ���� (Idle, Run ��)
			std::string texturePath = doc.GetCell<std::string>(1, i); // �ؽ�ó ���
			stateTextures[state].push_back(texturePath);
		}

		PlayState("Idle"); // �ʱ� ���¸� Idle�� ����
	}
	catch (const std::exception& e) {
		std::cerr << "[ERROR] Failed to load CSV for level " << level << ": " << e.what() << std::endl;
	}
}

void Player::PlayState(const std::string& state)
{
	if (currentState != state) {
		currentState = state;
		currentFrame = 0;
		animationTimer = 0.f;

		if (!stateTextures[state].empty()) {
			const sf::Texture& texture = TEXTURE_MGR.Get(stateTextures[state][0]);
			body.setTexture(texture);
	
			body.setTextureRect({ 0, 0, (int)texture.getSize().x, (int)texture.getSize().y });
		}
	}
}

void Player::UpdateAnimation(float dt)
{
	animationTimer += dt;

	if (animationTimer >= animationInterval) {
		animationTimer = 0.f;

		const auto& textures = stateTextures[currentState];
		if (!textures.empty()) {
			currentFrame = (currentFrame + 1) % textures.size();
			const sf::Texture& texture = TEXTURE_MGR.Get(textures[currentFrame]);
			body.setTexture(texture);
			body.setTextureRect({ 0, 0, (int)texture.getSize().x, (int)texture.getSize().y });
		}
	}
}






