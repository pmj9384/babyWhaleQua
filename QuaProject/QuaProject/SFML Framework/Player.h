#pragma once
#include "DebugBox.h"

class SceneGame;
class DebugBox;
class Item;
class HitBox;

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



	int maxHealth;           // �ִ� ü��
	float runSpeed;          // �̵� �ӵ�
	//int healthPickupBonus;   // ü�� ������ ȿ��


	HitBox* hitBox;
public:

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


	void UpdateHealthBar();
	void FixedUpdate(float dt) override;
	void OnDamage(int damageAmount);

	void IncreaseHealth(int amount); // ü������
	int GetHealth()const { return hp; }

	void OnPickup(Item* item);

	//void IncreaseSpeed(float amount);        // �̵� �ӵ� ����
	//void IncreaseMaxHealth(int amount);      // �ִ� ü�� ����


};
