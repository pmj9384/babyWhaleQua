#include "stdafx.h"
#include "Wave.h"
#include "Enemy.h"
#include "SceneGame.h"
#include "UiHud.h"
Wave::Wave()
{
}

void Wave::SetType(Types wavetype)
{
    Reset();
    types = wavetype;


    switch (wavetype)
    {
    case Types::Wave1:
 /*       EnemysToSpawn = 30;*/
        spawnInterval = 0.5f;
        spawnableTypes = { Enemy::Types::smallFish, Enemy::Types::redFish };
        AddTargetToKill(Enemy::Types::smallFish, 2);
        break;
    case Types::Wave2:
       /* EnemysToSpawn = 30;*/
        spawnInterval = 0.5f;
        spawnableTypes = { Enemy::Types::smallFish, Enemy::Types::redFish };
        AddTargetToKill(Enemy::Types::smallFish, 3);
        break;
    case Types::Wave3:
      /*  EnemysToSpawn = 30;*/
        spawnInterval = 0.5f;

        spawnableTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish };
        AddTargetToKill(Enemy::Types::smallFish, 3);
        AddTargetToKill(Enemy::Types::redFish, 3);
        break;
    case Types::Wave4:
      /*  EnemysToSpawn = 30;*/
        spawnInterval = 0.5f;
       spawnableTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish };
        AddTargetToKill(Enemy::Types::smallFish, 3);
        AddTargetToKill(Enemy::Types::redFish, 4); // SmallFish 3마리
        break;
    case Types::Wave5:
        //EnemysToSpawn = 30;
        spawnInterval = 0.5f;
        spawnableTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
        AddTargetToKill(Enemy::Types::redFish, 4);
        AddTargetToKill(Enemy::Types::buleFish, 4);
        break;

    case Types::Wave6:
       /* EnemysToSpawn = 30;*/
        spawnInterval = 0.2f;
        spawnableTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
        AddTargetToKill(Enemy::Types::redFish, 4);
        AddTargetToKill(Enemy::Types::buleFish, 5);
        break;
    case Types::Wave7:
        //EnemysToSpawn = 30;
        spawnInterval = 0.5f;
        spawnableTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
        AddTargetToKill(Enemy::Types::redFish, 5);
        AddTargetToKill(Enemy::Types::buleFish, 5);
        break;
    case Types::Wave8:
     /*   EnemysToSpawn = 30;*/
        spawnInterval = 0.5f;
        spawnableTypes = {Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish,Enemy::Types::Shark};
        AddTargetToKill(Enemy::Types::buleFish, 5);
        AddTargetToKill(Enemy::Types::purpleFish, 6);
        break;
    case Types::Wave9:
        //EnemysToSpawn = 30;
        spawnInterval = 0.5f;
        spawnableTypes = {Enemy::Types::buleFish,Enemy::Types::purpleFish,Enemy::Types::Shark };
        AddTargetToKill(Enemy::Types::buleFish, 6);
        AddTargetToKill(Enemy::Types::purpleFish, 7);
        break;
    case Types::Wave10:
       /* EnemysToSpawn = 30;*/
        spawnInterval = 0.5f;
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
            return false;
        }

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
     
    }
}

void Wave::EnemyKilled(Enemy::Types type)
{
    auto it = targetsToKill.find(type);
    if (it != targetsToKill.end())
    {
        enemiesKilled[type]++;
        int remaining = targetsToKill[type] - enemiesKilled[type];
    }
    else
    {
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

void Wave::OnEnemyDefeated(Enemy::Types type)
{
    if (targetsToKill.find(type) != targetsToKill.end())
    {
        targetsToKill[type]--; // 목표 수 감소

        if (targetsToKill[type] <= 0)
        {
            targetsToKill.erase(type); // 목표 완료 시 제거
        }

        // UI 갱신
        if (uiHud != nullptr)
        {
            uiHud->Reset(); // Reset 호출로 UI 갱신
        }
    }
}

