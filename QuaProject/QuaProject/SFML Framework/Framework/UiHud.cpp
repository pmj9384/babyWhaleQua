#include "stdafx.h"
#include "UiHud.h"
#include "Enemy.h"
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
	sf::Font& font = FONT_MGR.Get("fonts/malgunbd.ttf");
	textScore.setFont(font);
	textScore.setCharacterSize(textSize);
	textScore.setFillColor(sf::Color::White);
	Utils::SetOrigin(textScore, Origins::TL);
	//
	//textHighScore.setFont(font);
	//textHighScore.setCharacterSize(textSize);
	//textHighScore.setFillColor(sf::Color::White);
	//Utils::SetOrigin(textHighScore, Origins::TR);
	//
	//textAmmo.setFont(font);
	//textAmmo.setCharacterSize(textSize);
	//textAmmo.setFillColor(sf::Color::White);
	//Utils::SetOrigin(textAmmo, Origins::BL);
	//
	//textWave.setFont(font);
	//textWave.setCharacterSize(textSize);
	//textWave.setFillColor(sf::Color::White);
	//Utils::SetOrigin(textWave, Origins::BR);
	//
	//textZombieCount.setFont(font);
	//textZombieCount.setCharacterSize(textSize);
	//textZombieCount.setFillColor(sf::Color::White);
	//Utils::SetOrigin(textZombieCount, Origins::BR);
	//
	//gaugeHp.setFillColor(sf::Color::Red);
	//gaugeHp.setSize(gaugeHpMaxSize);
	//Utils::SetOrigin(gaugeHp, Origins::BL);
	//
	//iconAmmoIcon.setTexture(TEXTURE_MGR.Get("graphics/ammo_icon.png"));
	//Utils::SetOrigin(iconAmmoIcon, Origins::BL);

	iconGameOver.setTexture(TEXTURE_MGR.Get("graphics/sprites/GameOver_214/1.png"));
	Utils::SetOrigin(iconGameOver, Origins::MC);

	iconGameClear.setTexture(TEXTURE_MGR.Get("graphics/sprites/AllClear_221/10.png"));
	Utils::SetOrigin(iconGameClear, Origins::MC);

	iconGameDoum.setTexture(TEXTURE_MGR.Get("graphics/sprites/Doum_64/9.png"));
	Utils::SetOrigin(iconGameClear, Origins::MC);

	MainWindow.setTexture(TEXTURE_MGR.Get("graphics/frames/main.png"));
	Utils::SetOrigin(MainWindow, Origins::MC);
	sf::Vector2f size = FRAMEWORK.GetWindowSizeF();

	float topY = 10.f;
	float BottomY = size.y - 25.f;

	textScore.setPosition(820.f, topY );
	//textHighScore.setPosition(size.x - 80.f, topY );

//	iconAmmoIcon.setPosition(25.f, BottomY);

	iconGameOver.setPosition(500.f, 500.f);
	iconGameOver.setScale({ 1.0f,1.0f });


	iconGameClear.setPosition(500.f, 500.f);
	iconGameClear.setScale({ 1.0f,1.0f });


	MainWindow.setPosition(500.f, 500.f);
	MainWindow.setScale({ 0.5f,0.7f });
	
	iconGameDoum.setPosition(450.f, 200.f);
	iconGameDoum.setScale({ 0.8f,0.8f });

	sf::FloatRect buttonArea = { 330.f, 950.f, 350.f, 120.f };
	buttonHitBox.UpdateTr(MainWindow, buttonArea);
	buttonHitBox.SetVisible(false);
	buttonHitBox.SetActive(false);

	sf::FloatRect buttonArea5 = { 520.f, 950.f, 350.f, 120.f };
	buttonHitBox5.UpdateTr(MainWindow, buttonArea5);
	buttonHitBox5.SetVisible(false);
	buttonHitBox5.SetActive(false);

	sf::FloatRect buttonArea2 = { 40.f, 125.f, 150.f, 60.f };
	buttonHitBox2.UpdateTr(iconGameOver, buttonArea2);
	buttonHitBox2.SetVisible(false);
	buttonHitBox2.SetActive(false);
	sf::FloatRect buttonArea3 = { 240.f, 125.f, 150.f, 60.f };
	buttonHitBox3.UpdateTr(iconGameOver, buttonArea3);
	buttonHitBox3.SetVisible(false);
	buttonHitBox3.SetActive(false);

	sf::FloatRect buttonArea4 = { 450.f, 587.f, 180.f, 80.f };
	buttonHitBox4.UpdateTr(iconGameClear, buttonArea4);
	buttonHitBox4.SetVisible(false);
	buttonHitBox4.SetActive(false);
//	gaugeHp.setPosition(300.f, BottomY);

//	textAmmo.setPosition(100.f, BottomY);

//	textWave.setPosition(size.x - 400.f, BottomY);
//	textZombieCount.setPosition(size.x - 25.f, BottomY);

	isGameOverVisible = false;
	isGameClearVisible = false;
	//isMainWindowVisible = true;
	SetScore(0);
//	SetHiScore(0);
//	SetAmmo(0, 0);
//	SetHp(1.f, 1.f);
//	SetWave(0);
//	SetZombieCount(0);
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


	if (isGameOverVisible)
	{
		window.draw(iconGameOver);

		buttonHitBox2.Draw(window);
		buttonHitBox3.Draw(window);
		buttonHitBox2.SetActive(true);  // 버튼 활성화
		buttonHitBox3.SetActive(true);  // 버튼 활성화
	}

	if (isMainWindowVisible) // MainWindow의 가시성 확인
	{
		window.draw(MainWindow);
		buttonHitBox.Draw(window);
		buttonHitBox5.Draw(window);
		buttonHitBox.SetActive(true);  // 버튼 활성화
		buttonHitBox5.SetActive(true);  // 버튼 활성화
	}
	if (isGameClearVisible)
	{
		window.draw(iconGameClear);
		buttonHitBox4.Draw(window);
		buttonHitBox4.SetActive(true);  // 버튼 활성화

	}
	if (isGameDoumVisible)
	{
		window.draw(iconGameDoum);
	}
}

void UiHud::SetScore(int s)
{
	textScore.setString("" + std::to_string(s));
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

void UiHud::SetMainWindow(int m)
{
	MainWindow.setScale({ 0.2f,0.2f });
}

bool UiHud::IsButtonClicked(const sf::Vector2f& mousePos)
{
	// MainWindow 버튼 클릭 처리
	if (buttonHitBox.IsMouseOver(mousePos))
	{
		isMainWindowVisible = false;  // MainWindow 비활성화
		isGameDoumVisible = false;
		return true;
	}

	// GameOver 버튼 클릭 처리
	if (buttonHitBox2.IsMouseOver(mousePos))
	{
		isGameOverVisible = false;  // GameOver UI 비활성화

		return true;
	}
	if (buttonHitBox3.IsMouseOver(mousePos))
	{
		isGameOverVisible = false;  // GameOver UI 비활성화
		isMainWindowVisible = true;

		return true;
	}
	if (buttonHitBox4.IsMouseOver(mousePos))
	{
		isGameClearVisible = false;  // GameOver UI 비활성화
		isMainWindowVisible = true;

		return true;
	}
	if (buttonHitBox5.IsMouseOver(mousePos))
	{
		isGameDoumVisible = true;
		return true;
	}
	return false;
}

void UiHud::HandleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		std::cout << "MouseButtonPressed event detected!" << std::endl;  // 로그 추가
		sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
		std::cout << "Mouse Position: " << mousePos.x << ", " << mousePos.y << std::endl;  // 로그로 확인
		if (buttonHitBox.IsMouseOver(sf::Vector2f(mousePos.x, mousePos.y)))
		{
			std::cout << "Button clicked! Disabling MainWindow." << std::endl;
			isMainWindowVisible = false; // MainWindow를 비활성화
		}
	}
}

void UiHud::ShowGameOver(bool show)
{
	isGameOverVisible = show;
}




