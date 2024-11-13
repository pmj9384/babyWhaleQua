#include "stdafx.h"
#include "TileMap.h"

TileMap::TileMap(const std::string& name)
	: GameObject(name)
{
}

void TileMap::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	UpdateTransform();
}

void TileMap::SetRotation(float angle)
{
	rotation = angle;
	UpdateTransform();
}

void TileMap::SetScale(const sf::Vector2f& s)
{
	scale = s;
	UpdateTransform();
}

void TileMap::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		sf::FloatRect rect = GetLocalBounds();
		origin.x = rect.width * ((int)preset % 3) * 0.5f;
		origin.y = rect.height * ((int)preset / 3) * 0.5f;
	}
	UpdateTransform();
}

void TileMap::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	UpdateTransform();
}

sf::FloatRect TileMap::GetLocalBounds() const
{
	return { 0.f, 0.f, cellCount.x * cellSize.x, cellCount.y * cellSize.y };
}

sf::FloatRect TileMap::GetGlobalBounds() const
{
	sf::FloatRect bounds = GetLocalBounds();
	return transform.transformRect(bounds);
}

void TileMap::Init()
{
	sortingLayer = SortingLayers::Background;
	sortingOrder = -1;

	Set({ 30, 30 }, { 50.f, 50.f });
}

void TileMap::Release()
{
}

void TileMap::Reset()
{
	texture = &TEXTURE_MGR.Get(spriteSheetId);
	SetOrigin(Origins::MC);
	SetScale({ 1.f, 1.f });
	SetPosition( {0.f, 0.f });
}

void TileMap::Update(float dt)
{

}

void TileMap::Draw(sf::RenderWindow& window)
{
	sf::RenderStates state;
	state.texture = texture;
	state.transform = transform;
	window.draw(va, state);
}

void TileMap::Set(const sf::Vector2i& count, const sf::Vector2f& size)
{
	cellCount = count;
	cellSize = size;

	va.clear();
	va.setPrimitiveType(sf::Quads);
	va.resize(count.x * count.y * 4);

	sf::Vector2f posOffset[4] =
	{
		{ 0.f, 0.f },
		{ size.x, 0.f },
		{ size.x, size.y },
		{ 0.f, size.y },
	};

	sf::Vector2f texCoords[4] =
	{
		{ 0, 0 },
		{ 50.f, 0 },
		{ 50.f, 50.f },
		{ 0, 50.f },
	};

	for (int i = 0; i < count.y; ++i)
	{
		for (int j = 0; j < count.x; ++j)
		{
			int texIndex = Utils::RandomRange(0, 2);
			if (i == 0 || i == count.y - 1 || j == 0 || j == count.x - 1)
			{
				texIndex = 3;
			}
			
			int quadIndex = i * count.x + j;
			sf::Vector2f quadPos(j * size.x, i * size.y);

			for (int k = 0; k < 4; ++k)
			{
				int vertexIndex = quadIndex * 4 + k;
				va[vertexIndex].position = quadPos + posOffset[k];
				va[vertexIndex].texCoords = texCoords[k];
				va[vertexIndex].texCoords.y += texIndex * 50.f;
			}
		}
	}
}

void TileMap::UpdateTransform()
{
	transform = sf::Transform::Identity;
	transform.translate(position);
	transform.rotate(rotation);
	transform.scale(scale);
	transform.translate(-origin);
}

bool TileMap::CheckCollision(const sf::FloatRect& objectBounds) const
{
	for (int i = 0; i < cellCount.y; ++i)
	{
		for (int j = 0; j < cellCount.x; ++j)
		{
			// 현재 타일의 글로벌 경계 계산
			sf::FloatRect tileBounds(j * cellSize.x, i * cellSize.y, cellSize.x, cellSize.y);
			if (objectBounds.intersects(tileBounds))
			{
				return true; // 충돌 발생
			}
		}
	}
	return false; // 충돌 없음
}
