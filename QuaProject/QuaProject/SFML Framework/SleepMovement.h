#pragma once
#include "MovementPattern.h"
class SleepMovement : public MovementPattern
{
protected:
	void LoadAnimation(const std::string& filePath);
	void PlayState(const std::string& state, Enemy* enemy);
	// 애니메이션 관련 멤버 변수
	std::unordered_map<std::string, std::vector<std::string>> stateTextures;
	std::string animationFilePath;
	std::string currentState = "Idle";
	float animationTimer = 0.f;
	float animationInterval = 0.2f; // 애니메이션 프레임 간격
	size_t currentFrame = 0;

	float sleepTimer = 0.f;       // 슬립 상태 타이머
	float sleepInterval = 3.f;    // 슬립 상태로 전환되는 간격 (3~5초 랜덤)
	float sleepDuration = 10.f;
	bool isSleeping = false;
public:
	SleepMovement(const std::string& name = "");
	~SleepMovement() = default;
	void Update(float dt, Enemy* enemy,Player* player) override;
};

