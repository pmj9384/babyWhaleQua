#include "stdafx.h"
#include "Player.h"
#include "SceneGame.h"
#include "DebugBox.h"
#include "Item.h"

Player::Player(const std::string& name)
	: GameObject(name)
{

}

void Player::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Player::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(angle);
}

void Player::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(s);
}

void Player::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(body, originPreset);
	}
}

void Player::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	body.setOrigin(origin);
}

void Player::Init()
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;
	SetOrigin(Origins::MC);

	int maxHp = 100;
	int hp = maxHp;
	healthBar.setFillColor(sf::Color::Red);
	healthBar.setSize(sf::Vector2f(static_cast<float>(hp) / maxHp * 300.f, 80.f));
	healthBar.setPosition(position.x - healthBar.getSize().x / 2, position.y + body.getGlobalBounds().height / 2 + 600.f);
}

void Player::Release()
{
}

void Player::Reset()
{
	sceneGame = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());

	body.setTexture(TEXTURE_MGR.Get(textureId), true);
	SetOrigin(originPreset);
	SetPosition({ 0.f, 0.f });
	SetRotation(0.f);
	direction = { 1.f, 0.f };
	hp = maxHp; // 체력을 최대치로 리셋
	UpdateHealthBar();


	maxHealth = 100;
	runSpeed = 1.0f;
	healthPickupBonus = 0;

}

void Player::Update(float dt)
{
	direction.x = InputMgr::GetAxis(Axis::Horizontal);
	direction.y = InputMgr::GetAxis(Axis::Vertical);
	float mag = Utils::Magnitude(direction);
	if (mag > 1.f)
	{
		 Utils::Normalize(direction);
	}

	sf::Vector2i mousePos = InputMgr::GetMousePosition();
	sf::Vector2f mouseWorldPos = SCENE_MGR.GetCurrentScene()->ScreenToWorld(mousePos);
	look = Utils::GetNormal(mouseWorldPos - position);

	SetRotation(Utils::Angle(look));
	SetPosition(position + direction * speed * dt);


	debugBox.SetBounds(body.getGlobalBounds());
	UpdateHealthBar();

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(healthBar);
	debugBox.Draw(window);
}



void Player::UpdateHealthBar()
{
	float healthRatio = static_cast<float>(hp) / maxHp;
	healthBar.setFillColor(sf::Color::Red);

	// 체력바 크기 설정
	healthBar.setSize(sf::Vector2f(healthRatio * 300.f, 80.f));

	// 체력바의 원점을 오른쪽 끝으로 설정
	healthBar.setOrigin(300.f, 0.f);

	// 체력바 위치를 플레이어 기준으로 설정하여 따라오게 함
	healthBar.setPosition(position.x - 600.f, position.y + body.getGlobalBounds().height / 2 - 550.f);
}

void Player::FixedUpdate(float dt)
{
	
}

void Player::OnDamage(int damageAmount)
{
	std::cout << "Damage taken: " << damageAmount << std::endl;
	hp -= damageAmount;
	if (hp <= 0)
	{
		hp = 0;
		sceneGame->OnPlayerDie(this);
	}
	UpdateHealthBar();


}

void Player::IncreaseHealth(int amount)
{
	hp += amount;
	if (hp > maxHp) // 체력이 최대치를 초과하지 않도록
	hp = maxHp;
	
	UpdateHealthBar();
}




void Player::OnPickup(Item* item)
{
	item->OnPickup(this);
}






