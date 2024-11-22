#pragma once
#include "Animator.h"


class AniPlayer3 : public GameObject {

protected:
    sf::Sprite body;
    bool isFacingRight = true; // ���� ����
    float animationTimer = 0.f; // �ִϸ��̼� ��ü Ÿ�̸�
    float animationInterval = 0.2f; // �ִϸ��̼� ��ü ����

    std::unordered_map<std::string, std::vector<std::string>> stateTextures; // ���º� �ؽ�ó ��� ����Ʈ
    size_t currentFrame = 0; // ���� �ִϸ��̼� ������
    std::string currentState; // ���� ����

    sf::Vector2f velocity;                                   // Die ���¿��� �������� �ӵ�
    float gravity = 100.f;                                   // �߷�
public:
    AniPlayer3(const std::string& name);

    void Init() override;
    void Update(float dt) override;
    void PlayState(const std::string& state);
    void SetLevel(int level);       // ������ �ؽ�ó ����
    void SetDirection(bool right); // ���� ����

};
