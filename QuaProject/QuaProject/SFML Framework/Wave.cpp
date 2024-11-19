#include "stdafx.h"
#include "Wave.h"
#include "Enemy.h"
#include "SceneGame.h"
Wave::Wave()
{
}

void Wave::SetType(Types wavetype)
{
    types = wavetype;
    targetsToKill.clear();  // 기존 목표 초기화
    enemiesKilled.clear();  // 처치된 적 초기화
    spawnableTypes.clear();

    switch (wavetype)
    {
    case Types::Wave1:
        EnemysToSpawn = 50;
        spawnInterval = 0.8f;
        spawnableTypes = { Enemy::Types::smallFish, Enemy::Types::redFish };
        AddTargetToKill(Enemy::Types::smallFish, 2);
        break;
    case Types::Wave2:
        EnemysToSpawn = 50;
        spawnInterval = 0.8f;
        spawnableTypes = { Enemy::Types::smallFish, Enemy::Types::redFish };
        AddTargetToKill(Enemy::Types::smallFish, 3);
        break;
    case Types::Wave3:
        EnemysToSpawn = 50;
        spawnInterval = 0.8f;

        spawnableTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish };
        AddTargetToKill(Enemy::Types::smallFish, 3);
        AddTargetToKill(Enemy::Types::redFish, 3);
        break;
    case Types::Wave4:
        EnemysToSpawn = 50;
        spawnInterval = 0.8f;
       spawnableTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish };
        AddTargetToKill(Enemy::Types::smallFish, 3);
        AddTargetToKill(Enemy::Types::redFish, 4); // SmallFish 3마리
        break;
    case Types::Wave5:
        EnemysToSpawn = 50;
        spawnInterval = 0.8f;
        spawnableTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
        AddTargetToKill(Enemy::Types::redFish, 4);
        AddTargetToKill(Enemy::Types::buleFish, 4);
        break;

    case Types::Wave6:
        EnemysToSpawn = 50;
        spawnInterval = 0.8f;
        spawnableTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
        AddTargetToKill(Enemy::Types::redFish, 4);
        AddTargetToKill(Enemy::Types::buleFish, 5);
        break;
    case Types::Wave7:
        EnemysToSpawn = 50;
        spawnInterval = 0.8f;
        spawnableTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
        AddTargetToKill(Enemy::Types::redFish, 5);
        AddTargetToKill(Enemy::Types::buleFish, 5);
        break;
    case Types::Wave8:
        EnemysToSpawn = 50;
        spawnInterval = 0.8f;
        spawnableTypes = {Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish,Enemy::Types::Shark};
        AddTargetToKill(Enemy::Types::buleFish, 5);
        AddTargetToKill(Enemy::Types::purpleFish, 6);
        break;
    case Types::Wave9:
        EnemysToSpawn = 50;
        spawnInterval = 0.8f;
        spawnableTypes = {Enemy::Types::buleFish,Enemy::Types::purpleFish,Enemy::Types::Shark };
        AddTargetToKill(Enemy::Types::buleFish, 6);
        AddTargetToKill(Enemy::Types::purpleFish, 7);
        break;
    case Types::Wave10:
        EnemysToSpawn = 50;
        spawnInterval = 0.8f;
        spawnableTypes = { Enemy::Types::buleFish,Enemy::Types::purpleFish,Enemy::Types::Shark };
        AddTargetToKill(Enemy::Types::buleFish, 7);
        AddTargetToKill(Enemy::Types::purpleFish, 8);
        break;
    default:
        break;
    }
}

void Wave::Update(float dt)
{
    if (!waveActive)
        return;

    waveTimer += dt; // 타이머 업데이트

    // 모든 목표를 처치했는지 확인
    bool allTargetsCompleted = true;
    for (const auto& target : targetsToKill)
    {
        if (enemiesKilled[target.first] < target.second)
        {
            allTargetsCompleted = false;
            break;
        }
    }

    if (allTargetsCompleted)
    {
        waveActive = false; // 웨이브 종료
        Reset();
    }
}
void Wave::StartWave()
{
    waveActive = true;
    EnemysSpawned = 0;
    waveTimer = 0.f;
    for (const auto& target : targetsToKill)
    {
        enemiesKilled[target.first] = 0; // 해당 적 타입의 처치 카운트를 0으로 초기화
    }
    //enemiesKilled.clear();
}

bool Wave::IsWaveComplete() const
{
    for (const auto& target : targetsToKill)
    {
        Enemy::Types type = target.first;
        int requiredCount = target.second;

        if (enemiesKilled.at(type) < requiredCount)
        {
            std::cout << "Wave not complete. Type: " << static_cast<int>(type)
                << ", Killed: " << enemiesKilled.at(type)
                << ", Required: " << requiredCount << std::endl;
            return false;
        }
        std::cout << "Wave complete!\n";
    }
    return true;
}


void Wave::Reset()
{
    waveActive = false;
    EnemysSpawned = 0;
    waveTimer = 0.f;
    targetsToKill.clear();
    enemiesKilled.clear();
    spawnableTypes.clear();
}

void Wave::AddTargetToKill(Enemy::Types type, int count)
{
    if (targetsToKill.find(type) == targetsToKill.end())
    {
        targetsToKill[type] = count;
        enemiesKilled[type] = 0;
    }
    else
    {
        std::cout << "Enemy type already exists in targetsToKill." << std::endl;
    }
    
}

void Wave::EnemyKilled(Enemy::Types type)
{
    auto it = targetsToKill.find(type);
    if (it != targetsToKill.end())
    {
        enemiesKilled[type]++;
    }
    else
    {
        std::cout << "Invalid enemy type killed: " << static_cast<int>(type) << std::endl;
    }
}

bool Wave::CanSpawnEnemy() const
{
    return waveActive && EnemysSpawned < EnemysToSpawn && waveTimer >= spawnInterval;
}

void Wave::IncrementSpawnedEnemies()
{
    EnemysSpawned++;
    waveTimer = 0.f;
}

Enemy::Types Wave::GetRandomTargetType() const
{
    if (spawnableTypes.empty())
        return Enemy::Types::Shark;

    int randomIndex = Utils::RandomRange(0, spawnableTypes.size() - 1);
    return spawnableTypes[randomIndex];
}

