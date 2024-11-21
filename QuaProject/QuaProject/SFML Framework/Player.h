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

	int maxHealth;           // 최대 체력
	float runSpeed;          // 이동 속도

	bool isInvincible = false;           // 무적 상태 여부
	float invincibleDuration = 8.f;     // 무적 상태 지속 시간 (초)
	float invincibleTimer = 0.0f;

	float healthDecreaseTimer = 0.f; // 체력 감소를 위한 타이머
	const float decreaseInterval = 1.f;
	Enemy* lastCollidedEnemy = nullptr;
	HitBox* hitBox;

	//sf::Sprite body;
public:
	//std::unordered_set<Enemy*> processedEnemies;  // 이미 처리된 적을 저장할 집합
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

	void IncreaseHealth(int amount); // 체력증가
	int GetHealth()const { return hp; }
	float GetMaxHealth() const { return maxHp; }
	void OnPickup(Item* item);


	void SetAllowedEnemyTypes(const std::vector<Enemy::Types>& types);

	bool CanCatchEnemy(Enemy::Types enemyType) const;
	void ConsumeEnemy(Enemy* enemy);
	void OnCollisionWithEnemy(Enemy* enemy);

	void ChangeTexture(const std::string& textureId);
	//void IncreaseSpeed(float amount);        // 이동 속도 증가
	//void IncreaseMaxHealth(int amount);      // 최대 체력 증가


};
