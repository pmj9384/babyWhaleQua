#include "stdafx.h"
#include "SceneGame.h"
#include "Player.h"
#include "Enemy.h"

SceneGame::SceneGame() : Scene(SceneIds::Game)
{
}

void SceneGame::Init()
{
	sf::Vector2f windowSize(1920.f, 1080.f);

	worldView.setCenter(1920.f * 0.5f, 1080.f * 0.5f);
	worldView.setSize(1920.f, 1080.f);

	auto size = FRAMEWORK.GetWindowSize();
	GameObject* obj = AddGo(new SpriteGo("graphics/images/Background.png"));
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
	Scene::Init();
}

void SceneGame::Release()
{
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

	static float spawnTimer = 0.f;
	static float itemSpawnTimer = 0.f;

	const float spawnInterval = 2.f; // 2초마다 적 생성
	const float itemSpawnInterval = 5.f;

	spawnTimer += dt;
	if (spawnTimer >= spawnInterval)
	{
		SpawnEnemy(1); // 한 번에 한 개의 적 생성
		spawnTimer = 0.f;
	}

	itemSpawnTimer += dt;
	if (itemSpawnTimer >= itemSpawnInterval)
	{
		SpawnItem(1); // 한 번에 한 개의 아이템 생성
		itemSpawnTimer = 0.f;
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
	for (int i = 0; i < count; ++i)
	{
		Enemy* enemy = enemyPool.Take();
		if (enemy == nullptr)
		{
			continue;

		}
		enemys.push_back(enemy);
		Enemy::Types enemyType = static_cast<Enemy::Types>(Utils::RandomRange(0, static_cast<int>(Enemy::TotalTypes) - 1));
		enemy->SetType(enemyType);

		if (player == nullptr)
		{
		}
		else
		{
			enemy->SetPlayer(player);
		}

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
}

void SceneGame::PauseGame()
{
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


