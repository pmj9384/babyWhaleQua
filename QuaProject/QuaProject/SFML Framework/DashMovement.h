#pragma once
#include "MovementPattern.h"

class DashMovement : public MovementPattern
{
private:
    void LoadAnimation(const std::string& filePath);
    void PlayState(const std::string& state, Enemy* enemy);
    // �ִϸ��̼� ���� ��� ����
    std::unordered_map<std::string, std::vector<std::string>> stateTextures;
    std::string animationFilePath;
    std::string currentState = "Idle";
    float animationTimer = 0.f;
    float animationInterval = 0.2f; // �ִϸ��̼� ������ ����
    size_t currentFrame = 0;

    float dashTimer = 0.f;
    float dashInterval = 4.f; // 5�ʸ��� ����
    float dashDuration = 2.f;
    bool isDashing = false;
    float dashSpeedMultiplier = 3.f;
public:
    DashMovement(const std::string& name = "");
    ~DashMovement() = default;
    void Update(float dt, Enemy* enemy, Player* player) override;
};
