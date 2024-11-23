#pragma once
#include "Scene.h"
#include "SpawnArea.hpp"  // spawndraw
#include "Enemy.h"
#include "Player.h"
#include "Wave.h"
#include "UiHealthBar.h"
#include "UiHud.h"
#include "Aniplayer3.h"

class Player;
class Enemy;
class Wave;
class UiHealthBar;
class UiHud;
class AniPlayer3;

class SceneGame : public Scene {
	friend class Enemy;
protected:
	sf::Sprite levelNumber;
	sf::Sprite missionUi;
	Player* player;
	UiHealthBar* uiHealthbar;
	Wave* wave;
	Enemy* enemy;
	Item* item;
	AniPlayer3* aniPlayer3;
	int playerLevel = 1;

	UiHud* uiHud;

	std::list<Enemy*> enemys;
	ObjectPool<Enemy> enemyPool;

	std::list<Item*> items;
	ObjectPool<Item> itemPool;

	Wave* currentWave;
	float itemSpawnTimer = 0.0f;
	float itemSpawnInterval = 20.0f;
	
	float spawnTimer = 0.0f;
	float spawnInterval = 0.5f;
	bool isPaused = false;
	int currentScore = 0;
	std::unordered_set<Enemy*> processedEnemies;
public:
	SpawnArea spawn1;
	SpawnArea spawn2;
	SpawnArea spawn3;

	SceneGame();
	virtual ~SceneGame() = default;

	void Init();
	void Release();
	void Enter();
	void Reset();
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


	// 플레이어 레벨 
	void SetPlayerLevel(int level);
	void IncrementPlayerLevel();  // 플레이어 레벨 증가
	int GetPlayerLevel() const;
	void OnEnemyCatch(Enemy* enemy);
	void CheckCollisions();

	void OnPlayerScore(int scoreDelta);

	void OnEnemyDefeated(Enemy::Types enemyType);

	void ProcessEvents();

	void OnWaveComplete();

	void RemoveEnemy(Enemy* enemy);

};

