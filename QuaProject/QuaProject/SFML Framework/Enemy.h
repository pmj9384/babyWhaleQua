#pragma once
#include "GameObject.h"
#include "SpawnArea.hpp"
class Player;
class SceneGame;
class MovementPattern;

class Enemy :  public GameObject
{
	public:
		enum class Types
		{
			Shark,
			smallFish,
			redFish,
			buleFish,
			purpleFish,
		};
		static const int TotalTypes = 5;
		bool dead = false;

protected:
	Types types = Types::Shark;
	sf::Sprite body;
	std::string textureId;
	sf::Vector2f direction;
	MovementPattern* movementPattern = nullptr;
	Player* player = nullptr;
	SceneGame* scenegame = nullptr;

	int maxHp = 0;
	float speed = 0.f;
	int damage = 0;
	float attackInterval = 0.f;
	int hp = 0;



	float attackTimer = 0.f;
	bool active = true; // 공격활성화
	float deactivateTime; // 비활성화 유지 시간
	float deactivateTimer;


	float directionChangeInterval;
	float directionChangeTimer;
	float effectTimer = 0.f;
public:
	Enemy(const std::string& name = "");
	~Enemy() = default;

	sf::Sprite& GetBody()
	{
		return body;
	}
	sf::FloatRect GetLocalBounds() const;
	sf::FloatRect GetGlobalBounds() const;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& s) override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	bool IsWithinBounds() const;

	void SetType(Types type);

	void OnDamage(int damage);
	int GetDamage() const { return damage; }
	bool IsActive() const { return active; }
	void Deactivate(float duration);

	void SetDirection(const sf::Vector2f& dir);

	void AddMovementPattern(MovementPattern* pattern);
	sf::Vector2f GetDirection() const;
	float GetSpeed() const;

	void SetPlayer(Player* p);


	/*SaveEnemy GetSaveData()const;
	void LoadSaveData(const SaveEnemy& data);*/
};

