#pragma once
#include "MovementPattern.h"
class StraightMovement :  public MovementPattern
{
private:
    void LoadAnimation(const std::string& filePath);

    // 애니메이션 관련 멤버 변수
    std::unordered_map<std::string, std::vector<std::string>> stateTextures;
    std::string animationFilePath;
    float animationTimer = 0.f;
    float animationInterval = 0.2f; // 애니메이션 프레임 간격
    size_t currentFrame = 0;
public:
	StraightMovement(const std::string& name = "");
	~StraightMovement() = default;
	void Update(float dt, Enemy* enemy, Player* player) override;
};

