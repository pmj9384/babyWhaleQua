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
	std::map<Enemy::Types, int> targetsToKill;  // �� Ÿ�Ժ� ��ǥ ��
	std::map<Enemy::Types, int> enemiesKilled; // �� Ÿ�Ժ� óġ�� ��
	std::vector<Enemy::Types> spawnableTypes;
public:
	Wave();
	virtual ~Wave() = default;

	Types GetType() const { return types; }


	void SetType(Types type);
	// ������Ʈ �޼���
	void Update(float dt);

	// ���̺� ����
	void StartWave();

	// ���̺갡 �Ϸ�Ǿ����� Ȯ��
	bool IsWaveComplete() const;


	// ���̺갡 Ȱ��ȭ �������� Ȯ��
	bool IsActive() const { return waveActive; }

	void Reset();

	void AddTargetToKill(Enemy::Types type, int count);
	void EnemyKilled(Enemy::Types type);

	bool CanSpawnEnemy() const;
	void IncrementSpawnedEnemies();
	void SetUiHud(UiHud* hud) { uiHud = hud; }

	Enemy::Types GetRandomTargetType() const;
};

