#pragma once
#include "Scene.h"
#include "SpawnArea.hpp"  // spawndraw

class Player;

class SceneGame : public Scene
{
protected:
	Player* player;
	
public:
	SceneGame();
	virtual ~SceneGame() = default;

	void Init();
	void Release();
	void Enter();
	void Exit();
	void Update(float dt);
	void Draw(sf::RenderWindow& window) override;  // spawndraw

	void SpawnItem(int count);


	
	void OnPlayerDie(Player* player);

	void PauseGame();
	void ResumeGame();

	void CheckWaveCompletion();
	void ApplyUpgrade(int selectedUpgrade);

};

