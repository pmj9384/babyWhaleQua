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

	std::unordered_map<std::string, std::vector<std::string>> stateTextures;
	std::string currentState;




	float animationTimer = 0.f;
	float animationInterval = 0.2f; // 애니메이션 프레임 간격

	size_t currentFrame = 0;
	float recoveryTimer = 0.f;           // "Eat" 상태에서 원래 상태로 돌아가기 위한 타이머
	const float eatAnimationDuration = 0.25f;

	float hitRecoveryTimer = 0.f;               // "Hit" 상태에서 원래 상태로 복귀하기 위한 타이머
	const float hitAnimationDuration = 0.8f;

	bool isDead = false;                // 사망 여부
	float deathTimer = 0.f;             // 사망 후 타이머
	const float deathDuration = 50.f;    // 사망 애니메이션 지속 시간
	const float deathSpeed = 50.f;      // 사망 시 천천히 내려가는 속도
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

	void SetLevel(int level); // 레벨에 따른 애니메이션 초기화
	void PlayState(const std::string& state); // 상태 전환
	void UpdateAnimation(float dt); // 애니메이션 업데이트

};
