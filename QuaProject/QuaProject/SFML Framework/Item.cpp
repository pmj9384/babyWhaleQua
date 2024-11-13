#include "stdafx.h"
#include "Item.h"
#include "Player.h"
#include "ItemTable.h"

Item::Item(const std::string& name) : GameObject(name)
{
}

sf::FloatRect Item::GetLocalBounds() const
{
	return body.getLocalBounds();
}

sf::FloatRect Item::GetGlobalBounds() const
{
	return body.getGlobalBounds();
}

void Item::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Item::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void Item::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Item::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(body, originPreset);
	}
}

void Item::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	body.setOrigin(origin);
}

void Item::Init()
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 1;
}

void Item::Release()
{
}

void Item::Reset()
{
	player = dynamic_cast<Player*>(SCENE_MGR.GetCurrentScene()->FindGo("Player"));
	body.setTexture(TEXTURE_MGR.Get(textureId));
	SetOrigin(Origins::MC);
	SetPosition({ 0.f,0.f });
	SetRotation({ 0.f });
	SetScale({ 1.f,1.f });
}

void Item::Update(float dt)
{

}

void Item::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Item::SetType(Types type)
{
	types = type;
	const auto& data = ITEM_TABLE->Get(type);
	textureId = data.textureId;
	//body.setTexture(TEXTURE_MGR.Get(textureId), true);
	body.setTexture(TEXTURE_MGR.Get(textureId),true);

}

void Item::OnPickup(Player* player)
{
	if (types == Types::Health) 
	{
		int healthToAdd = 20; 
		player->IncreaseHealth(healthToAdd);
	}

}
