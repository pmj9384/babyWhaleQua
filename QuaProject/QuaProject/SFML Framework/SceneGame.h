#pragma once
#include "Scene.h"
#include "SpawnArea.hpp"  // spawndraw
#include "Enemy.h"
#include "Player.h"
#include "Wave.h"

class Player;
class Enemy;
class wave;

class SceneGame : public Scene {
	friend class Enemy;
protected:
	Player* player;
	int playerLevel = 1;

	std::list<Enemy*> enemys;
	ObjectPool<Enemy> enemyPool;

	std::list<Item*> items;
	ObjectPool<Item> itemPool;

	Wave* currentWave;

public:
	SpawnArea spawn1;
	SpawnArea spawn2;
	SpawnArea spawn3;


	SceneGame();
	virtual ~SceneGame() = default;

	void Init();
	void Release();
	void Enter();
	void Exit();
	void Update(float dt);
	void Draw(sf::RenderWindow& window) override;  // spawndraw

	void SpawnItem(int count);
	void SpawnEnemy(int count);

	const std::list<Enemy*>& GetEnemyList() const { return enemys; }


	void OnPlayerDie(Player* player);
	const std::list<Item*>& GetItemList() const { return items; }
	void PauseGame();
	void ResumeGame();

	void CheckWaveCompletion();
	void ApplyUpgrade(int selectedUpgrade);

	ObjectPool<Enemy>& GetEnemyPool() { return enemyPool; }


	// �÷��̾� ���� 
	void SetPlayerLevel(int level);
	void IncrementPlayerLevel();  // �÷��̾� ���� ����
	int GetPlayerLevel() const;
	void OnEnemyCatch(Enemy* enemy);
	void CheckCollisions();

	void OnEnemyDefeated(Enemy::Types enemyType);


};

