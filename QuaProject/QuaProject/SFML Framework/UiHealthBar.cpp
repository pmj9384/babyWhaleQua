#include "stdafx.h"
#include "UiHealthBar.h"
#include "Player.h"
#include "SceneGame.h"

UiHealthBar::UiHealthBar(const std::string& name)
    : GameObject(name), maxHealth(100.f), currentHealth(100.f)
{
  
}

void UiHealthBar::Init()
{
    if (!barTexture.loadFromFile("graphics/images/227.png"))
    {
        throw std::runtime_error("Failed to load health bar texture");
    }
    barSprite.setTexture(barTexture);
    barSprite.setOrigin(0.f, 0.f);
    barSprite.setPosition(175.f, 15.f);
    barSprite.setScale(3.5f, 2.3f);
    barSprite.setTextureRect(sf::IntRect(0, 0, barTexture.getSize().x, barTexture.getSize().y));
    
}

void UiHealthBar::Reset()
{
    currentHealth = maxHealth;
    healthDecreaseTimer = 0.f;
    UpdateHealthBar();
}

void UiHealthBar::Update(float dt)
{
    if (player != nullptr) 
    {
        currentHealth = player->GetHealth();
        UpdateHealthBar();
    }
}


void UiHealthBar::Draw(sf::RenderWindow& window)
{
    window.draw(barSprite);
}

void UiHealthBar::Release()
{
}

void UiHealthBar::SetPlayer(Player* player)
{
    this->player = player;
    if (player != nullptr)
    {
        maxHealth = player->GetMaxHealth();
        currentHealth = player->GetHealth();
        UpdateHealthBar();
    }
}

void UiHealthBar::SetMaxHealth(float health)
{
    maxHealth = health;
    UpdateHealthBar();
}

void UiHealthBar::SetCurrentHealth(float health)
{
    currentHealth = std::max(0.f, std::min(maxHealth, health)); // 0 ~ maxHealth·Î Á¦ÇÑ
    UpdateHealthBar();
}

void UiHealthBar::UpdateHealthBar()
{
    float healthRatio = (maxHealth > 0) ? (currentHealth / maxHealth) : 0.f;
    int newWidth = static_cast<int>(barTexture.getSize().x * healthRatio);
    barSprite.setTextureRect(sf::IntRect(0, 0, newWidth, barTexture.getSize().y));
}
