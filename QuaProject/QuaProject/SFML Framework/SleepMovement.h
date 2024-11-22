#pragma once
#include "MovementPattern.h"
class SleepMovement : public MovementPattern
{
protected:
	void LoadAnimation(const std::string& filePath);
	void PlayState(const std::string& state, Enemy* enemy);
	// �ִϸ��̼� ���� ��� ����
	std::unordered_map<std::string, std::vector<std::string>> stateTextures;
	std::string animationFilePath;
	std::string currentState = "Idle";
	float animationTimer = 0.f;
	float animationInterval = 0.2f; // �ִϸ��̼� ������ ����
	size_t currentFrame = 0;

	float sleepTimer = 0.f;       // ���� ���� Ÿ�̸�
	float sleepInterval = 3.f;    // ���� ���·� ��ȯ�Ǵ� ���� (3~5�� ����)
	float sleepDuration = 10.f;
	bool isSleeping = false;
public:
	SleepMovement(const std::string& name = "");
	~SleepMovement() = default;
	void Update(float dt, Enemy* enemy,Player* player) override;
};

