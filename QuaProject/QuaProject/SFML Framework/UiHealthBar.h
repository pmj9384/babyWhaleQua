#pragma once
#include "stdafx.h"
#include "GameObject.h"
class Player;

class UiHealthBar : public GameObject
{
protected:
    Player* player;

    sf::Sprite barSprite;     // 체력 스프라이트
    sf::Texture barTexture;   // 체력 텍스처

    float maxHealth = 100.f;  // 최대 체력
    float currentHealth = 100.f; // 현재 체력
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

