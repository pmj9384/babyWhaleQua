#pragma once
#include "Animator.h"


class AniPlayer3 : public GameObject {

protected:
    sf::Sprite body;
    bool isFacingRight = true; // 현재 방향
    float animationTimer = 0.f; // 애니메이션 교체 타이머
    float animationInterval = 0.2f; // 애니메이션 교체 간격

    std::unordered_map<std::string, std::vector<std::string>> stateTextures; // 상태별 텍스처 경로 리스트
    size_t currentFrame = 0; // 현재 애니메이션 프레임
    std::string currentState; // 현재 상태

    sf::Vector2f velocity;                                   // Die 상태에서 내려가는 속도
    float gravity = 100.f;                                   // 중력
public:
    AniPlayer3(const std::string& name);

    void Init() override;
    void Update(float dt) override;
    void PlayState(const std::string& state);
    void SetLevel(int level);       // 레벨별 텍스처 설정
    void SetDirection(bool right); // 방향 설정

};
