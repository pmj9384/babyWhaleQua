#pragma once
#include "MovementPattern.h"
class SleepMovement : public MovementPattern
{
protected:
	float sleepTimer = 0.f;       // 슬립 상태 타이머
	float sleepInterval = 3.f;    // 슬립 상태로 전환되는 간격 (3~5초 랜덤)
	float sleepDuration = 10.f;
	bool isSleeping = false;
public:
	SleepMovement(const std::string& name = "");
	~SleepMovement() = default;
	void Update(float dt, Enemy* enemy,Player* player) override;
};

