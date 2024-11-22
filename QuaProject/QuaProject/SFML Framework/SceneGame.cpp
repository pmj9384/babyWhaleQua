#include "stdafx.h"
#include "SceneGame.h"
#include "Player.h"
#include "Enemy.h"
#include "wave.h"
#include "UiHealthBar.h"
#include "UiHud.h"
#include "AniPlayer3.h"


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

	auto* player = new Player();
	AddGo(player);
	this->player = player;

	SetPlayerLevel(1);

	uiHud = AddGo(new UiHud("UiHud"));
	if (uiHud)
	{
		uiHud->Init();
		uiHud->SetScore(0); 
	}
	currentScore = 0; // SceneGame���� ���� ����

	GameObject* levelNum = AddGo( new SpriteGo("graphics/images/36.png", "LevelNumber"));
	levelNum->sortingLayer = SortingLayers::UI;
	levelNum->sortingOrder = -1;
	levelNum->SetPosition({ 105.0f, windowSize.y-215.f });
	levelNum->SetScale({ 2.f,3.f });
	if (TEXTURE_MGR.Load("graphics/images/36.png"))
	{
		levelNum->SetTexture(TEXTURE_MGR.Get("graphics/images/36.png"));
	}
	
	GameObject* missionUi = AddGo(new SpriteGo("graphics/sprites/UiEnermybar_89/mission1.png","MissionUi"));
	missionUi->sortingLayer = SortingLayers::UI;
	missionUi->sortingOrder = -1;
	missionUi->SetPosition({ 270.0f, windowSize.y - 250.f });
	missionUi->SetScale({ 0.8f,1.0f });

	//if (TEXTURE_MGR.Load("graphics/sprites/UiEnermybar_89/mission1.png"))
	//{
	//	missionUi->SetTexture(TEXTURE_MGR.Get("graphics/sprites/UiEnermybar_89/mission1.png"));
	//}


	spawn1.SetPosition( -100.0f, 400.0f);
	spawn1.SetSize(100.f, backgroundSize.y-700);
	spawn1.SetOrigin(Origins::MC);
	spawn1.SetDrawable(false); // �׵θ� ǥ��

	spawn2.SetPosition(1920.0f, 400.0f);
	spawn2.SetSize(100.f, backgroundSize.y- 700);
	spawn2.SetOrigin(Origins::MC);
	spawn2.SetDrawable(false); 

	spawn3.SetPosition(1920.0f / 2.0f - 300.f, 1080.0f / 2.0f -200.f); // ȭ�� �߽� ����
	spawn3.SetSize(1600.0f, 600.0f); // ���� �� ���� ũ�� ����
	spawn3.SetOrigin(Origins::MC);
	spawn3.SetDrawable(false);

	currentWave = new Wave();            
	currentWave->SetType(Wave::Types::Wave1); // ù ��° ���̺� ����
	currentWave->StartWave();
	SetPlayerLevel(1);

	uiHealthbar = AddGo(new UiHealthBar("UiHealthBar"));
	uiHealthbar->SetPlayer(player);


	isPaused = true;

	Scene::Init();
}

void SceneGame::Release()
{
	if (currentWave)
	{
		delete currentWave; // currentWave ����
		currentWave = nullptr;
	}
}

void SceneGame::Enter()
{
	TEXTURE_MGR.Load("graphics/images/Background.png");
	Scene::Enter();
}

void SceneGame::Reset()
{

	wave->Reset();
	player->Reset();
	uiHud->Reset();
	enemy->Reset();
	uiHealthbar->Reset();


}

void SceneGame::Exit()
{
	TEXTURE_MGR.Unload("graphics/images/Background.png");

	Scene::Exit();
}

void SceneGame::Update(float dt)
{
	//player->Update(dt);

	sf::Vector2i mousePos = InputMgr::GetMousePosition();
	sf::Vector2f worldMousePos = FRAMEWORK.GetWindow().mapPixelToCoords(mousePos, uiView);  

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (uiHud->IsButtonClicked(worldMousePos))
		{
			if (!uiHud->isMainWindowVisible)
			{
				std::cout << "MainWindow ó�� �Ϸ�." << std::endl;
			}
			if (!uiHud->isGameOverVisible)
			{
				if (wave)
					wave->Reset();
				if (player)
					player->Reset();
				if (uiHud)
					uiHud->Reset();
				if (enemy)
					enemy->Reset();
				if (uiHealthbar)
					uiHealthbar->Reset();
				for (auto& enemy : enemys)
				{
					enemy->SetActive(false); // �� ��Ȱ��ȭ
				}
				enemys.clear(); // �����̳� ����

				spawnTimer = 0.f;
				playerLevel = 1;
				currentScore = 0;
				SetPlayerLevel(playerLevel);

				if (currentWave)
				{
					currentWave->Reset();
					currentWave->SetType(Wave::Types::Wave1); // ù ��° ���̺� ����
					currentWave->StartWave();
				}
				if (uiHud)
				{
					uiHud->SetScore(currentScore);
				}
			}
			if (!uiHud->isGameClearVisible)
			{
				if (wave)
					wave->Reset();
				if (player)
					player->Reset();
				if (uiHud)
					uiHud->Reset();
				if (enemy)
					enemy->Reset();
				if (uiHealthbar)
					uiHealthbar->Reset();
				for (auto& enemy : enemys)
				{
					enemy->SetActive(false); // �� ��Ȱ��ȭ
				}
				enemys.clear(); // �����̳� ����

				spawnTimer = 0.f;
				playerLevel = 1;
				currentScore = 0;
				SetPlayerLevel(playerLevel);

				if (currentWave)
				{
					currentWave->Reset();
					currentWave->SetType(Wave::Types::Wave1); // ù ��° ���̺� ����
					currentWave->StartWave();
				}
				if (uiHud)
				{
					uiHud->SetScore(currentScore);
				}
			}
		}
	}
	if (isPaused)
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
		{
			isPaused = false;
		}
		return;
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		isPaused = true;
		return;
	}
	if (uiHealthbar)
	{
		uiHealthbar->SetCurrentHealth(player->GetHealth());
	}
	 
	itemSpawnTimer += dt;
	if (itemSpawnTimer >= itemSpawnInterval)
	{
		itemSpawnTimer -= itemSpawnInterval; // Ÿ�̸� �ʱ�ȭ
		SpawnItem(1); // ������ ����
	}

	spawnTimer += dt;
	if (spawnTimer >= spawnInterval)  // ���� �ð����� �� ����
	{
		spawnTimer -= spawnInterval; // Ÿ�̸� �ʱ�ȭ
		SpawnEnemy(1);
	}

	if (currentWave)
	{
		currentWave->Update(dt); // ���̺� ���� ����

		// �� ���� ó��
		//if (currentWave->CanSpawnEnemy())
		//{
		//	SpawnEnemy(1); // �� ����
		//	currentWave->IncrementSpawnedEnemies();
		//}

		if (currentWave->IsWaveComplete())
		{
			// ���ο� ���̺� ����
			currentWave = new Wave();

			playerLevel++; // �÷��̾� ���� ����
			SetPlayerLevel(playerLevel); // �÷��̾� ������ ���� �� ��� Ÿ�� ����
			currentWave->Reset();
			// ���� ���̺� Ÿ�� ����
			Wave::Types nextWaveType = static_cast<Wave::Types>(playerLevel);
			if (nextWaveType <= Wave::Types::Wave10) // �ִ� ���̺� Ȯ��
			{
				currentWave->SetType(nextWaveType);
				currentWave->StartWave();

				std::cout << "Started Wave " << static_cast<int>(nextWaveType) << std::endl;
			}
			else
			{
				std::cout << "No more waves! Game complete!" << std::endl;
				//currentWave = nullptr; // ���� ���� ���·� ��ȯ
				isPaused =true;
				uiHud->isGameClearVisible = true;
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
		else if (playerPos.y > bounds.top + bounds.height - 250)
		{
			playerPos.y = bounds.top + bounds.height - 250;
		}

		player->SetPosition(playerPos);

	}
	Scene::Update(dt);
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
	if (!currentWave) // currentWave�� ��ȿ���� Ȯ��
		return;
	for (int i = 0; i < count; ++i)
	{
		Enemy* enemy = enemyPool.Take();
		if (enemy == nullptr)
		{
			continue;
		}
		enemy->SetSceneGame(this);
		enemy->SetPlayer(player);

		
		Enemy::Types enemyType = currentWave->GetRandomTargetType();
		enemy->SetType(enemyType);



		// spawn1 �Ǵ� spawn2���� �����ϰ� ���� ��ġ ����
		sf::Vector2f spawnPosition;
		sf::Vector2f direction;

		if (Utils::RandomRange(0, 1) == 0)
		{
			spawnPosition = spawn1.Spawn(); // ���� ���� ��ġ
			direction = sf::Vector2f(1.f, 0.f);
		}
		else
		{
			spawnPosition = spawn2.Spawn(); // ������ ���� ��ġ
			direction = sf::Vector2f(-1.f, 0.f);
		}

		enemy->SetPosition(spawnPosition); // ���� ��ġ�� ���� ��ġ�� ����
		enemy->SetDirection(direction);
		enemys.push_back(enemy);
		AddGo(enemy);
		//enemy->SetActive(true);

	}
}

void SceneGame::OnPlayerDie(Player* player)
{
	//player->SetActive(false);
	//isPaused = true;
	if (uiHud)
	{
		uiHud->ShowGameOver(true); // ���� ���� ������ ǥ��
	}
}

void SceneGame::PauseGame()
{
	isPaused = true;
}

void SceneGame::ResumeGame()
{
	isPaused = false;
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
	std::string textureId;
	std::string levelImageId;
	std::string missionTextureId;
	switch (level)
	{
	case 1:
		allowedTypes = { Enemy::Types::smallFish }; // ���� 1������ smallFish�� ���� �� ����
	//	textureId = "graphics/images/91.png";
		levelImageId = "graphics/images/36.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/mission1.png";
		break;
	case 2:
		allowedTypes = { Enemy::Types::smallFish };
	//	textureId = "graphics/images/105.png";
		levelImageId = "graphics/images/38.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/mission1.png";
		break;
	case 3:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish };
	//	textureId = "graphics/images/116.png";
		levelImageId = "graphics/images/40.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/mission2.png";
		break;
	case 4:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish };
	//	textureId = "graphics/images/127.png";
		levelImageId = "graphics/images/42.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/mission2.png";

		break;
	case 5:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish };
	//	textureId = "graphics/images/138.png";
		levelImageId = "graphics/images/44.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/mission3.png";

		break;
	case 6:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish };
	//	textureId = "graphics/images/149.png";
		levelImageId = "graphics/images/46.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/mission3.png";

		break;
	case 7:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish };
	//	textureId = "graphics/images/160.png";
		levelImageId = "graphics/images/48.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/mission3.png";

		break;
	case 8:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
	//	textureId = "graphics/images/171.png";
		levelImageId = "graphics/images/50.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/mission4.png";

		break;
	case 9:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
	//	textureId = "graphics/images/182.png";
		levelImageId = "graphics/images/52.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/mission4.png";

		break;
	case 10:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
	//	textureId = "graphics/images/193.png";
		levelImageId = "graphics/images/54.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/mission4.png";
		break;
	default:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
		break;
	}

	player->SetAllowedEnemyTypes(allowedTypes);
	// AniPlayer3�� SetLevel ȣ��� �ؽ�ó ���� �� �ʱ�ȭ
	if (player) 
	{
		player->SetLevel(level);
		std::cout << "[DEBUG] Player level set to " << level << std::endl;
	}
	GameObject* levelNum = FindGo("LevelNumber");
	if (levelNum)
	{
		levelNum->SetTexture(TEXTURE_MGR.Get(levelImageId));
	}
	GameObject* missionUi = FindGo("MissionUi");
	if (missionUi)
	{
		missionUi->SetTexture(TEXTURE_MGR.Get(missionTextureId));
	}
	
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

	//if (!enemy->IsActive()) // OnDamage ���� ���� Ȯ��
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
	//		OnEnemyCatch(enemy); // ���� �浹 �� ó��
	//		break; // �� ���� �浹�� ó��
	//	}
	//}

}

void SceneGame::OnPlayerScore(int scoreDelta)
{
	currentScore += scoreDelta; // ���� ����
	if (uiHud)
	{
		uiHud->SetScore(currentScore); // HUD�� ���� ������Ʈ
	}
}

void SceneGame::OnEnemyDefeated(Enemy::Types enemyType)
{
	if (currentWave)
	{
		if (enemyType != Enemy::Types::none)
		{
			currentWave->EnemyKilled(enemyType); // �� óġ ī��Ʈ ����
			currentScore += 100; // 100�� �߰�
			if (uiHud)
			{
				uiHud->SetScore(currentScore); // HUD ���� ������Ʈ
			}
		}
	}


}

void SceneGame::OnWaveComplete()
{
	// ���̺갡 ���� ������ ó���� ������ ����
	//player->processedEnemies.clear();  // `Player`���� `processedEnemies`�� �ʱ�ȭ

	//// ���̺갡 ���� �� ������ ��Ȱ��ȭ
	//for (auto& enemy : enemys)
	//{
	//	enemy->SetActive(false);  // ��� ���� ��Ȱ��ȭ
	//}

	// ���ο� ���̺� ����
	if (currentWave)
	{
		delete currentWave;
		currentWave = nullptr;
	}

	// ���ο� ���̺� ��ü ���� �� ����
	currentWave = new Wave();
	currentWave->StartWave();

	// �÷��̾� ���� ����
	playerLevel++;
	SetPlayerLevel(playerLevel);  // �÷��̾� ������ �´� �� ��� Ÿ�� ����

	std::cout << "Started Wave " << playerLevel << std::endl;

	// ���ο� ���̺��� ���� �ٽ� Ȱ��ȭ
	//for (auto& enemy : enemys)
	//{
	//	enemy->SetActive(true);  // �� ���̺꿡�� ���� �ٽ� Ȱ��ȭ
	//}
}





