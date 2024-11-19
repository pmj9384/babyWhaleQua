#pragma once
#include "stdafx.h"
#include "GameObject.h"
class Player;

class UiHealthBar : public GameObject
{
protected:
    Player* player;

    sf::Sprite barSprite;     // ü�� ��������Ʈ
    sf::Texture barTexture;   // ü�� �ؽ�ó

    float maxHealth = 100.f;  // �ִ� ü��
    float currentHealth = 100.f; // ���� ü��
    float healthDecreaseTimer = 0.f; 
    const float decreaseInterval = 1.f; 
public:
    UiHealthBar(const std::string& name = "");
    ~UiHealthBar() override = default;

    void Init() override;
    void Reset() override;
    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;
    void Release() override;

    void SetPlayer(Player* player);
    void SetMaxHealth(float health);
    void SetCurrentHealth(float health);
    void UpdateHealthBar();
};

