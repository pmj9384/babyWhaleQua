#pragma once
#include "DebugBox.h"

class SceneGame;
class DebugBox;
class Item;
class HitBox;
class Enemy;

class Player : public GameObject
{
protected:
	sf::Sprite body;
	std::string textureId = "graphics/images/91.png";

	sf::Vector2f direction;
	sf::Vector2f look;

	float speed = 200.f;

	SceneGame* sceneGame;

	DebugBox debugBox;

	sf::RectangleShape healthBar;
	int maxHp = 100;
	int hp = 100;
	int attackDamage = 10;
	std::vector<Enemy::Types> allowedEnemyTypes;

	int maxHealth;           // �ִ� ü��
	float runSpeed;          // �̵� �ӵ�

	bool isInvincible = false;           // ���� ���� ����
	float invincibleDuration = 8.f;     // ���� ���� ���� �ð� (��)
	float invincibleTimer = 0.0f;

	float healthDecreaseTimer = 0.f; // ü�� ���Ҹ� ���� Ÿ�̸�
	const float decreaseInterval = 1.f;
	Enemy* lastCollidedEnemy = nullptr;
	HitBox* hitBox;

	//sf::Sprite body;
public:
	//std::unordered_set<Enemy*> processedEnemies;  // �̹� ó���� ���� ������ ����
	Player(const std::string& name = "");
	~Player() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;


	void SetAttackDamage(int damage) { attackDamage = damage; }
	int GetAttackDamage() const { return attackDamage; }
	void AttackEnemy(Enemy* enemy);
	void UpdateHealthBar();
	void FixedUpdate(float dt) override;
	void OnDamage(int damageAmount);

	void IncreaseHealth(int amount); // ü������
	int GetHealth()const { return hp; }
	float GetMaxHealth() const { return maxHp; }
	void OnPickup(Item* item);


	void SetAllowedEnemyTypes(const std::vector<Enemy::Types>& types);

	bool CanCatchEnemy(Enemy::Types enemyType) const;
	void ConsumeEnemy(Enemy* enemy);
	void OnCollisionWithEnemy(Enemy* enemy);

	void ChangeTexture(const std::string& textureId);
	//void IncreaseSpeed(float amount);        // �̵� �ӵ� ����
	//void IncreaseMaxHealth(int amount);      // �ִ� ü�� ����


};
