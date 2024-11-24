#include "stdafx.h"
#include "SceneGame.h"
#include "Player.h"
#include "Enemy.h"
#include "wave.h"
#include "UiHealthBar.h"
#include "UiHud.h"
#include "AniPlayer3.h"
#include "SoundMgr.h"

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
	currentScore = 0; // SceneGame에서 점수 관리

	GameObject* levelNum = AddGo( new SpriteGo("graphics/images/36.png", "LevelNumber"));
	levelNum->sortingLayer = SortingLayers::UI;
	levelNum->sortingOrder = -1;
	levelNum->SetPosition({ 105.0f, windowSize.y-212.f });
	levelNum->SetScale({ 0.5f,0.7f });
	if (TEXTURE_MGR.Load("graphics/images/36.png"))
	{
		levelNum->SetTexture(TEXTURE_MGR.Get("graphics/images/36.png"));
	}
	
	GameObject* missionUi = AddGo(new SpriteGo("graphics/sprites/UiEnermybar_89/mission1.png","MissionUi"));
	missionUi->sortingLayer = SortingLayers::UI;
	missionUi->sortingOrder = -1;
	missionUi->SetPosition({ 240.0f, windowSize.y - 250.f });
	missionUi->SetScale({ 0.5f,0.5f });
	// Sound 관련 초기화 및 BGM 재생

	
	SOUNDBUFFER_MGR.Load("graphics/sounds/77_s_bg.mp3", "graphics/sounds/77_s_bg.mp3");
	//SOUNDBUFFER_MGR.Load("graphics/sounds/77_s_bg.mp3", "graphics/sounds/77_s_bg.mp3");
	SOUND_MGR.Init(); // SoundMgr 초기화
	//SOUND_MGR.PlayBgm("graphics/sounds/77_s_bg.mp3", false);

	spawn1.SetPosition( -100.0f, 400.0f);
	spawn1.SetSize(100.f, backgroundSize.y-700);
	spawn1.SetOrigin(Origins::MC);
	spawn1.SetDrawable(false); // 테두리 표시

	spawn2.SetPosition(1920.0f, 400.0f);
	spawn2.SetSize(100.f, backgroundSize.y- 700);
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


	isPaused = false;

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
				std::cout << "MainWindow 처리 완료." << std::endl;
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
				if (item)
					item->Reset();

				for (auto& item : items)
				{
					item->SetActive(false); // 적 비활성화
				}
				items.clear();
				for (auto& enemy : enemys)
				{
					enemy->SetActive(false); // 적 비활성화
				}
				enemys.clear(); // 컨테이너 비우기

				spawnTimer = 0.f;
				playerLevel = 1;
				currentScore = 0;
				SetPlayerLevel(playerLevel);

				if (currentWave)
				{
					currentWave->Reset();
					currentWave->SetType(Wave::Types::Wave1); // 첫 번째 웨이브 설정
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
				if (item)
					item->Reset();

				for (auto& item : items)
				{
					item->SetActive(false); // 적 비활성화
				}
				items.clear();
			
				for (auto& enemy : enemys)
				{
					enemy->SetActive(false); // 적 비활성화
				}
				enemys.clear(); // 컨테이너 비우기

				spawnTimer = 0.f;
				playerLevel = 1;
				currentScore = 0;
				SetPlayerLevel(playerLevel);

				if (currentWave)
				{
					currentWave->Reset();
					currentWave->SetType(Wave::Types::Wave1); // 첫 번째 웨이브 설정
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
		return; // 게임이 일시 정지 상태일 경우 업데이트 중단
	}
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

	spawnTimer += dt;
	if (spawnTimer >= spawnInterval)  // 일정 시간마다 적 스폰
	{
		spawnTimer -= spawnInterval; // 타이머 초기화
		SpawnEnemy(1);
	}

	if (currentWave)
	{
		currentWave->Update(dt); // 웨이브 상태 갱신

		// 적 스폰 처리
		//if (currentWave->CanSpawnEnemy())
		//{
		//	SpawnEnemy(1); // 적 스폰
		//	currentWave->IncrementSpawnedEnemies();
		//}

		if (currentWave->IsWaveComplete())
		{
			// 새로운 웨이브 생성
			currentWave = new Wave();

			playerLevel++; // 플레이어 레벨 증가
			SetPlayerLevel(playerLevel); // 플레이어 레벨에 따라 적 허용 타입 설정
			currentWave->Reset();
			// 다음 웨이브 타입 설정
			Wave::Types nextWaveType = static_cast<Wave::Types>(playerLevel);
			if (nextWaveType <= Wave::Types::Wave10) // 최대 웨이브 확인
			{
				currentWave->SetType(nextWaveType);
				currentWave->StartWave();
			}
			else
			{

				//currentWave = nullptr; // 게임 종료 상태로 전환
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
	if (!currentWave) // currentWave가 유효한지 확인
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
		uiHud->ShowGameOver(true); // 게임 오버 아이콘 표시
	}
	SOUND_MGR.StopBgm();
	SOUND_MGR.PlaySfx("graphics/sounds/68_s_over2.mp3", false);
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
		allowedTypes = { Enemy::Types::smallFish }; // 레벨 1에서는 smallFish만 잡을 수 있음
	//	textureId = "graphics/images/91.png";
		levelImageId = "graphics/images/score/1.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/1.png";
		break;
	case 2:
		allowedTypes = { Enemy::Types::smallFish };
	//	textureId = "graphics/images/105.png";
		levelImageId = "graphics/images/score/2.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/1.png";
		break;
	case 3:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish };
	//	textureId = "graphics/images/116.png";
		levelImageId = "graphics/images/score/3.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/2.png";
		break;
	case 4:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish };
	//	textureId = "graphics/images/127.png";
		levelImageId = "graphics/images/score/4.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/2.png";

		break;
	case 5:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish };
	//	textureId = "graphics/images/138.png";
		levelImageId = "graphics/images/score/5.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/3.png";

		break;
	case 6:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish };
	//	textureId = "graphics/images/149.png";
		levelImageId = "graphics/images/score/6.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/3.png";

		break;
	case 7:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish };
	//	textureId = "graphics/images/160.png";
		levelImageId = "graphics/images/score/7.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/3.png";

		break;
	case 8:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
	//	textureId = "graphics/images/171.png";
		levelImageId = "graphics/images/score/8.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/4.png";

		break;
	case 9:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
	//	textureId = "graphics/images/182.png";
		levelImageId = "graphics/images/score/9.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/4.png";

		break;
	case 10:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
	//	textureId = "graphics/images/193.png";
		levelImageId = "graphics/images/score/10.png";
		missionTextureId = "graphics/sprites/UiEnermybar_89/4.png";
		break;
	default:
		allowedTypes = { Enemy::Types::smallFish, Enemy::Types::redFish, Enemy::Types::buleFish,Enemy::Types::purpleFish };
		break;
	}

	player->SetAllowedEnemyTypes(allowedTypes);
	// AniPlayer3의 SetLevel 호출로 텍스처 설정 및 초기화
	if (player) 
	{
		player->SetLevel(level);
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

void SceneGame::OnPlayerScore(int scoreDelta)
{
	currentScore += scoreDelta; // 점수 갱신
	if (uiHud)
	{
		uiHud->SetScore(currentScore); // HUD에 점수 업데이트
	}
}

void SceneGame::OnEnemyDefeated(Enemy::Types enemyType)
{
	if (currentWave)
	{
		if (enemyType != Enemy::Types::none)
		{
			currentWave->EnemyKilled(enemyType); // 적 처치 카운트 증가
			currentScore += 100; // 100점 추가
			if (uiHud)
			{
				uiHud->SetScore(currentScore); // HUD 점수 업데이트
			}
		}
	}


}

void SceneGame::OnWaveComplete()
{
	// 웨이브가 끝날 때마다 처리된 적들을 리셋
	//player->processedEnemies.clear();  // `Player`에서 `processedEnemies`를 초기화

	//// 웨이브가 끝날 때 적들을 비활성화
	//for (auto& enemy : enemys)
	//{
	//	enemy->SetActive(false);  // 모든 적을 비활성화
	//}

	// 새로운 웨이브 생성
	if (currentWave)
	{
		delete currentWave;
		currentWave = nullptr;
	}

	// 새로운 웨이브 객체 생성 및 시작
	currentWave = new Wave();
	currentWave->StartWave();

	// 플레이어 레벨 증가
	playerLevel++;
	SetPlayerLevel(playerLevel);  // 플레이어 레벨에 맞는 적 허용 타입 설정


	// 새로운 웨이브의 적을 다시 활성화
	//for (auto& enemy : enemys)
	//{
	//	enemy->SetActive(true);  // 새 웨이브에서 적을 다시 활성화
	//}
}





