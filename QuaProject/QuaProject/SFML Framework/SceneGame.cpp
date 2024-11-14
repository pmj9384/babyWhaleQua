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
	obj->sortingLayer = SortingLayers::Background;
	obj->sortingOrder = -1;
	obj->SetPosition({ 0.0f, 0.0f });
	obj->SetScale({ 1.0f * (1920.f / 1320.f), 1.0f });

	player = AddGo(new Player("Player"));

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
	for (auto enemy : enemy)
	{
		RemoveGo(enemy);
		enemyPool.Return(enemy);
	}
	enemy.clear();
	Scene::Exit();
}

void SceneGame::Update(float dt)
{

	Scene::Update(dt);

	static float spawnTimer = 0.f;
	const float spawnInterval = 2.f; // 2초마다 적 생성

	spawnTimer += dt;
	if (spawnTimer >= spawnInterval)
	{
		SpawnEnemy(1); // 한 번에 한 개의 적 생성
		spawnTimer = 0.f;
	}



}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}



void SceneGame::SpawnItem(int count)
{
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

		Enemy::Types enemyType = static_cast<Enemy::Types>(Utils::RandomRange(0, static_cast<int>(Enemy::TotalTypes) - 1));
		enemy->SetType(enemyType);

		sf::Vector2f position;
		sf::FloatRect bounds(0.f, 0.f, 200.f, 50.f);
		do {
			position = {
				Utils::RandomRange(bounds.left, bounds.left + bounds.width),
				Utils::RandomRange(bounds.top, bounds.top + bounds.height)
			};
		} while (Utils::Distance(position, player->GetPosition()) < 200.f);

		enemy->SetPosition(position);

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
