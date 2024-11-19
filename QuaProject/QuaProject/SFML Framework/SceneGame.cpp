#include "stdafx.h"
#include "SceneGame.h"
#include "Player.h"
#include "Enemy.h"
#include "wave.h"
#include "UiHealthBar.h"

SceneGame::SceneGame() : Scene(SceneIds::Game) 
{
}

void SceneGame::Init()
{
	sf::Vector2f windowSize(1920.f, 1080.f);

	worldView.setCenter(1920.f * 0.5f, 1080.f * 0.5f);
	worldView.setSize(1920.f, 1080.f);

	auto size = FRAMEWORK.GetWindowSize();
	GameObject* obj = AddGo(new SpriteGo("graphics/images/Background.png", "graphics/images/Background.png"));
	const auto& backgroundSize = TEXTURE_MGR.Get("graphics/images/Background.png").getSize();
	obj->sortingLayer = SortingLayers::Background;
	obj->sortingOrder = -1;
	obj->SetPosition({ 0.0f, 0.0f });
	obj->SetScale({ 1.0f * (1920.f / backgroundSize.x), 1.0f * (1080.f / backgroundSize.y)});


	player = AddGo(new Player("Player"));

	spawn1.SetPosition( -100.0f, 0.0f);
	spawn1.SetSize(100.f, backgroundSize.y-610);
	spawn1.SetOrigin(Origins::MC);
	spawn1.SetDrawable(false); // 테두리 표시

	spawn2.SetPosition(1920.0f, 0.0f); 
	spawn2.SetSize(100.f, backgroundSize.y-610);
	spawn2.SetOrigin(Origins::MC);
	spawn2.SetDrawable(false); 

	spawn3.SetPosition(1920.0f / 2.0f - 300.f, 1080.0f / 2.0f -200.f); // 화면 중심 설정
	spawn3.SetSize(1600.0f, 600.0f); // 가로 및 세로 크기 설정
	spawn3.SetOrigin(Origins::MC);
	spawn3.SetDrawable(false);

	currentWave = new Wave();            
	currentWave->SetType(Wave::Types::Wave1); // 첫 번째 웨이브 설정
	currentWave->StartWave();
	SetPlayerLevel(1);

	uiHealthbar = AddGo(new UiHealthBar("UiHealthBar"));
	uiHealthbar->SetPlayer(player);

	Scene::Init();
}

void SceneGame::Release()
{
	if (currentWave)
	{
		delete currentWave; // currentWave 삭제
		currentWave = nullptr;
	}
}

void SceneGame::Enter()
{
	TEXTURE_MGR.Load("graphics/images/Background.png");

	//sf::Vector2f size = FRAMEWORK.GetWindowSizeF();
	//worldView.setSize(FRAMEWORK.GetWindowSizeF());
	//uiView.setSize(FRAMEWORK.GetWindowSizeF());
	//worldView.setCenter(0.f, 0.f);
	Scene::Enter();
}

void SceneGame::Exit()
{
	TEXTURE_MGR.Unload("graphics/images/Background.png");
	for (auto enemy : enemys)
	{
		RemoveGo(enemy);
		enemyPool.Return(enemy);
	}
	enemys.clear();
	Scene::Exit();
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);
	player->Update(dt);
	if (uiHealthbar)
	{
		uiHealthbar->SetCurrentHealth(player->GetHealth());
	}
	itemSpawnTimer += dt;
	if (itemSpawnTimer >= itemSpawnInterval)
	{
		itemSpawnTimer -= itemSpawnInterval; // 타이머 초기화
		SpawnItem(1); // 아이템 스폰
	}
	if (currentWave)
	{
		currentWave->Update(dt); // 웨이브 상태 갱신

		// 적 스폰 처리
		if (currentWave->CanSpawnEnemy())
		{
			SpawnEnemy(1); // 적 스폰
			currentWave->IncrementSpawnedEnemies();
		}

		if ( currentWave->IsWaveComplete())
		{
			// 기존 웨이브 삭제
			delete currentWave;
			currentWave = nullptr;

			// 새로운 웨이브 생성
			currentWave = new Wave();
			currentWave->Reset();
			playerLevel++; // 플레이어 레벨 증가
			SetPlayerLevel(playerLevel); // 플레이어 레벨에 따라 적 허용 타입 설정

			// 다음 웨이브 타입 설정
			Wave::Types nextWaveType = static_cast<Wave::Types>(playerLevel);
			if (nextWaveType <= Wave::Types::Wave10) // 최대 웨이브 확인
			{
				currentWave->SetType(nextWaveType);
				currentWave->StartWave();
				std::cout << "Started Wave " << static_cast<int>(nextWaveType) << std::endl;
			}
			else
			{
				std::cout << "No more waves! Game complete!" << std::endl;
				currentWave = nullptr; // 게임 종료 상태로 전환
			}
		}
		GameObject* obj = static_cast<GameObject*>(FindGo("graphics/images/Background.png"));
		sf::FloatRect bounds = obj->GetGlobalBounds();
		sf::Vector2f playerPos = player->GetPosition();

		if (playerPos.x < bounds.left)
		{
			playerPos.x = bounds.left;
		}
		else if (playerPos.x > bounds.left + bounds.width)
		{
			playerPos.x = bounds.left + bounds.width;
		}

		if (playerPos.y < bounds.top)
		{
			playerPos.y = bounds.top;
		}
		else if (playerPos.y > bounds.top + bounds.height)
		{
			playerPos.y = bounds.top + bounds.height;
		}
		player->SetPosition(playerPos);
	}
}
void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	spawn1.Draw(window); // spawndraw
	spawn2.Draw(window); // spawndraw
	spawn3.Draw(window);

}



void SceneGame::SpawnItem(int count)
{
	for (int i = 0; i < count; ++i)
	{
		Item* item = itemPool.Take();
		items.push_back(item);

		Item::Types itemType = (Item::Types)Utils::RandomRange(0, Item::TotalTypes - 1);
		item->SetType(itemType);

		sf::Vector2f pos;
		pos = spawn3.Spawn();
		item->SetPosition(pos);

		AddGo(item);
		item->SetActive(true);
	}
}

void SceneGame::SpawnEnemy(int count)
{
	if (!currentWave) // currentWave가 유효한지 확인
		return;
	for (int i = 0; i < count; ++i)
	{
		Enemy* enemy = enemyPool.Take();
		if (enemy == nullptr)
		{
			continue;
		}
		enemys.push_back(enemy);

		enemy->SetSceneGame(this);
		Enemy::Types enemyType = currentWave->GetRandomTargetType();
		enemy->SetType(enemyType);
		enemy->SetPlayer(player);


		// spawn1 또는 spawn2에서 랜덤하게 스폰 위치 선택
		sf::Vector2f spawnPosition;
		sf::Vector2f direction;

		if (Utils::RandomRange(0, 1) == 0) 
		{
			spawnPosition = spawn1.Spawn(); // 왼쪽 스폰 위치
			direction = sf::Vector2f(1.f, 0.f);
		}
		else
		{
			spawnPosition = spawn2.Spawn(); // 오른쪽 스폰 위치
			direction = sf::Vector2f(-1.f, 0.f);
		}

		enemy->SetPosition(spawnPosition); // 적의 위치를 스폰 위치로 설정
		enemy->SetDirection(direction);

		AddGo(enemy);
		enemy->SetActive(true);

	}
}

void SceneGame::OnPlayerDie(Player* player)
{
	player->SetActive(false);
	isPaused = true;
}

void SceneGame::PauseGame()
{
	isPaused = true;
}

void SceneGame::ResumeGame()
{
}

void SceneGame::CheckWaveCompletion()
{
}

void SceneGame::ApplyUpgrade(int selectedUpgrade)
{
}

void SceneGame::SetPlayerLevel(int level)
{
	std::vector<Enemy::Types> allowedTypes;

	switch (level)
	{
	case 1:
		allowedTypes = { Enemy::Types::smallFish }; // 레벨 1에서는 smallFish만 잡을 수 있음
		break;
	case 2:
		allowedTypes = { Enemy::Types::smallFish };
		break;
	case 3:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish };
		break;
	case 4:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish };
		break;
	case 5:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish };
		break;
	case 6:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish };
		break;
	case 7:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish };
		break;
	case 8:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
		break;
	case 9:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };

		break;
	case 10:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };

		break;
	default:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
		break;
	}

	player->SetAllowedEnemyTypes(allowedTypes);
}

void SceneGame::IncrementPlayerLevel()
{
	playerLevel++;
	SetPlayerLevel(playerLevel);
}

int SceneGame::GetPlayerLevel() const
{
	return playerLevel;
}

void SceneGame::OnEnemyCatch(Enemy* enemy)
{
	//if (!enemy->IsActive())
	//{
	//	return;
	//}
	//int playerDamage = player->GetAttackDamage(); 
	//enemy->OnDamage(playerDamage); 

	//if (!enemy->IsActive()) // OnDamage 이후 상태 확인
	//{
	//	currentWave->EnemyKilled(enemy->GetType());
	//}
}

void SceneGame::CheckCollisions()
{
	//for (Enemy* enemy : enemys)
	//{
	//	if (!enemy->IsActive())
	//		continue;

	//	if (player->GetGlobalBounds().intersects(enemy->GetGlobalBounds()))
	//	{
	//		OnEnemyCatch(enemy); // 적과 충돌 시 처리
	//		break; // 한 번의 충돌만 처리
	//	}
	//}

}

void SceneGame::OnEnemyDefeated(Enemy::Types enemyType)
{
	if (currentWave)
	{
		if (enemyType != Enemy::Types::none)
		{
			currentWave->EnemyKilled(enemyType); // 적 처치 카운트 증가
		}
	}


}



