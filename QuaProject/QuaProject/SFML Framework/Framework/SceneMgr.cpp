#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneDev1.h"
#include "SceneDev2.h"
#include "SceneGame.h"

void SceneMgr::Init()
{
	scenes.push_back(new SceneGame());
	scenes.push_back(new SceneDev1());
	scenes.push_back(new SceneDev2());

	for (auto scene : scenes)
	{
		scene->Init();
	}
	//database.hpp
	fz::Database::LoadFromCsv("Animations/test.csv");

	auto& table = fz::Database::GetCsvTable("Animations/test.csv");
	std::string path = table["IDLE"]["PATH"];
	float left = table["IDLE"]["LEFT"];
	std::cout << path << ", " << left << std::endl;
	fz::Database::Unload("Animations/test.csv");
	//
	currentScene = startScene;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Release()
{
	for (auto scene : scenes)
	{
		if (currentScene == scene->id)
		{
			scene->Exit();
		}
		scene->Release();
		delete scene;
	}
	scenes.clear();
}

void SceneMgr::ChangeScene(SceneIds id)
{
	nextScene = id;
}

void SceneMgr::Update(float dt)
{
	scenes[(int)currentScene]->Update(dt);
}

void SceneMgr::LateUpdate(float dt)
{
	scenes[(int)currentScene]->LateUpdate(dt);
}

void SceneMgr::FixedUpdate(float dt)
{
	scenes[(int)currentScene]->FixedUpdate(dt);
}

void SceneMgr::OnPreDraw()
{
	scenes[(int)currentScene]->OnPreDraw();
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	OnPreDraw();
	scenes[(int)currentScene]->Draw(window);
	OnPostDraw();
}

void SceneMgr::OnPostDraw()
{
	scenes[(int)currentScene]->OnPostDraw();
	if (nextScene != SceneIds::None)
	{
		scenes[(int)currentScene]->Exit();
		currentScene = nextScene;
		nextScene = SceneIds::None;
		scenes[(int)currentScene]->Enter();
	}
}
