#pragma once
#include "MovementPattern.h"
class SleepMovement : public MovementPattern
{
protected:
	float sleepTimer = 0.f;       // ���� ���� Ÿ�̸�
	float sleepInterval = 3.f;    // ���� ���·� ��ȯ�Ǵ� ���� (3~5�� ����)
	float sleepDuration = 10.f;
	bool isSleeping = false;
public:
	SleepMovement(const std::string& name = "");
	~SleepMovement() = default;
	void Update(float dt, Enemy* enemy,Player* player) override;
};

