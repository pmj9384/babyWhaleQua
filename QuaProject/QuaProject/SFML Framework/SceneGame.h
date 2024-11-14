#pragma once
#include "Scene.h"
#include "SpawnArea.hpp"  // spawndraw

class Player;
class Enemy;

class SceneGame : public Scene
{
protected:
	Player* player;

	std::list<Enemy*> enemy;
	ObjectPool<Enemy> enemyPool;
public:
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

	const std::list<Enemy*>& GetEnemyList() const { return enemy; }


	void OnPlayerDie(Player* player);

	void PauseGame();
	void ResumeGame();

	void CheckWaveCompletion();
	void ApplyUpgrade(int selectedUpgrade);

};

