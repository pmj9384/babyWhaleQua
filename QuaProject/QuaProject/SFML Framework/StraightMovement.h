#pragma once
#include "MovementPattern.h"
class StraightMovement :  public MovementPattern
{
private:
    void LoadAnimation(const std::string& filePath);

    // �ִϸ��̼� ���� ��� ����
    std::unordered_map<std::string, std::vector<std::string>> stateTextures;
    std::string animationFilePath;
    float animationTimer = 0.f;
    float animationInterval = 0.2f; // �ִϸ��̼� ������ ����
    size_t currentFrame = 0;
public:
	StraightMovement(const std::string& name = "");
	~StraightMovement() = default;
	void Update(float dt, Enemy* enemy, Player* player) override;
};

