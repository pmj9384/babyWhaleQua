#pragma once
#include"json.hpp"
#include "Scene.h"
using json = nlohmann::json;



class SceneDev1 : public Scene
{
protected:
public:
	SceneDev1();
	~SceneDev1() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

