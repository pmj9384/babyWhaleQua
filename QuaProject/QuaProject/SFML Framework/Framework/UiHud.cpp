#include "stdafx.h"
#include "UiHud.h"

UiHud::UiHud(const std::string& name)
	: GameObject(name)
{
}

void UiHud::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
}

void UiHud::SetRotation(float angle)
{
	rotation = angle;
}

void UiHud::SetScale(const sf::Vector2f& s)
{
	scale = s;
}

void UiHud::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{

	}
}

void UiHud::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
}

void UiHud::Init()
{
	sortingLayer = SortingLayers::UI;
	sortingOrder = 0;
}

void UiHud::Release()
{
}

void UiHud::Reset()
{
	float textSize = 50.f;
	sf::Font& font = FONT_MGR.Get("fonts/zombiecontrol.ttf");
	textScore.setFont(font);
	textScore.setCharacterSize(textSize);
	textScore.setFillColor(sf::Color::White);
	Utils::SetOrigin(textScore, Origins::TL);

	textHighScore.setFont(font);
	textHighScore.setCharacterSize(textSize);
	textHighScore.setFillColor(sf::Color::White);
	Utils::SetOrigin(textHighScore, Origins::TR);

	textAmmo.setFont(font);
	textAmmo.setCharacterSize(textSize);
	textAmmo.setFillColor(sf::Color::White);
	Utils::SetOrigin(textAmmo, Origins::BL);

	textWave.setFont(font);
	textWave.setCharacterSize(textSize);
	textWave.setFillColor(sf::Color::White);
	Utils::SetOrigin(textWave, Origins::BR);

	textZombieCount.setFont(font);
	textZombieCount.setCharacterSize(textSize);
	textZombieCount.setFillColor(sf::Color::White);
	Utils::SetOrigin(textZombieCount, Origins::BR);

	gaugeHp.setFillColor(sf::Color::Red);
	gaugeHp.setSize(gaugeHpMaxSize);
	Utils::SetOrigin(gaugeHp, Origins::BL);

	iconAmmoIcon.setTexture(TEXTURE_MGR.Get("graphics/ammo_icon.png"));
	Utils::SetOrigin(iconAmmoIcon, Origins::BL);

	sf::Vector2f size = FRAMEWORK.GetWindowSizeF();

	float topY = 25.f;
	float BottomY = size.y - 25.f;

	textScore.setPosition(25.f, topY);
	textHighScore.setPosition(size.x - 25.f, topY);

	iconAmmoIcon.setPosition(25.f, BottomY);
	gaugeHp.setPosition(300.f, BottomY);

	textAmmo.setPosition(100.f, BottomY);

	textWave.setPosition(size.x - 400.f, BottomY);
	textZombieCount.setPosition(size.x - 25.f, BottomY);


	SetScore(0);
	SetHiScore(0);
	SetAmmo(0, 0);
	SetHp(1.f, 1.f);
	SetWave(0);
	SetZombieCount(0);
}

void UiHud::Update(float dt)
{
}

void UiHud::Draw(sf::RenderWindow& window)
{
	window.draw(textScore);
	window.draw(textHighScore);
	window.draw(iconAmmoIcon);
	window.draw(gaugeHp);
	window.draw(textAmmo);
	window.draw(textWave);
	window.draw(textZombieCount);
}

void UiHud::SetScore(int s)
{
	textScore.setString("SCORE: " + std::to_string(s));
	Utils::SetOrigin(textScore, Origins::TL);
}

void UiHud::SetHiScore(int s)
{
	textHighScore.setString("HI SCORE: " + std::to_string(s));
	Utils::SetOrigin(textHighScore, Origins::TR);
}

void UiHud::SetAmmo(int current, int total)
{
	textAmmo.setString(std::to_string(current) + " / " + std::to_string(total));
	Utils::SetOrigin(textAmmo, Origins::BL);
}

void UiHud::SetHp(int hp, int max)
{
	float value = (float)hp / max;
	gaugeHp.setSize({ gaugeHpMaxSize.x * value, gaugeHpMaxSize.y });
}

void UiHud::SetWave(int w)
{
	textWave.setString("WAVE: " + std::to_string(w));
	Utils::SetOrigin(textWave, Origins::BR);
}

void UiHud::SetZombieCount(int count)
{
	textZombieCount.setString("ZOMBIES: " + std::to_string(count));
	Utils::SetOrigin(textZombieCount, Origins::BR);
}
