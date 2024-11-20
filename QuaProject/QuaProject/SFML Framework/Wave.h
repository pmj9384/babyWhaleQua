#pragma once
#include "GameObject.h"
#include "Enemy.h"
#include "SceneGame.h"

class Enemy;
class SceneGame;
class UiHud;
class Wave
{
public:
	enum class Types
	{
		none,
		Wave1,
		Wave2,
		Wave3,
		Wave4,
		Wave5,
		Wave6,
		Wave7,
		Wave8,
		Wave9,
		Wave10,
	};
	static const int TotalTypes = 11;
	//Wave* currentWave = nullptr;
protected:
	Types types;
	int EnemysToSpawn;
	int EnemysSpawned;
	float waveTimer;
	float spawnInterval;
	bool waveActive;
	UiHud* uiHud;
	std::map<Enemy::Types, int> targetsToKill;  // 적 타입별 목표 수
	std::map<Enemy::Types, int> enemiesKilled; // 적 타입별 처치된 수
	std::vector<Enemy::Types> spawnableTypes;
public:
	Wave();
	virtual ~Wave() = default;

	Types GetType() const { return types; }


	void SetType(Types type);
	// 업데이트 메서드
	void Update(float dt);

	// 웨이브 시작
	void StartWave();

	// 웨이브가 완료되었는지 확인
	bool IsWaveComplete() const;


	// 웨이브가 활성화 상태인지 확인
	bool IsActive() const { return waveActive; }

	void Reset();

	void AddTargetToKill(Enemy::Types type, int count);
	void EnemyKilled(Enemy::Types type);

	bool CanSpawnEnemy() const;
	void IncrementSpawnedEnemies();
	void SetUiHud(UiHud* hud) { uiHud = hud; }

	Enemy::Types GetRandomTargetType() const;
};

