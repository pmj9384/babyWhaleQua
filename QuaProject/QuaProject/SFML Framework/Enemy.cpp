#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "EnemyTable.h"
Enemy::Enemy(const std::string& name) : GameObject(name)
{
	SortingLayers sortingLayer = SortingLayers::Foreground;
	int sortingOrder = 1;
}

sf::FloatRect Enemy::GetLocalBounds() const
{
	return body.getLocalBounds();
}

sf::FloatRect Enemy::GetGlobalBounds() const
{
	return body.getGlobalBounds();
}

void Enemy::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Enemy::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void Enemy::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Enemy::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(body, originPreset);
	}
}

void Enemy::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	body.setOrigin(origin);
}

void Enemy::Init()
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;

	SetType(types);

}

void Enemy::Release()
{
}

void Enemy::Reset()
{
	speed = Utils::RandomRange(min_speed, max_speed);
	const float screenWidth = 1920.f;
	const float screenHeight = 1080.f;

	// ���� ũ��
	sf::FloatRect enemyBounds = body.getGlobalBounds();

	// �������� ���� �Ǵ� �����ʿ��� ����
	if (Utils::RandomRange(0, 1) == 0) {
		// ���ʿ��� ����
		position = sf::Vector2f(-enemyBounds.width, Utils::RandomRange(0.f, screenHeight));
		direction = sf::Vector2f(1.f, 0.f); // ���������� �̵�
	}
	else {
		// �����ʿ��� ����
		position = sf::Vector2f(screenWidth, Utils::RandomRange(0.f, screenHeight));
		direction = sf::Vector2f(-1.f, 0.f); // �������� �̵�
	}

	SetPosition(position);
	this->direction = direction;
}

void Enemy::Update(float dt)
{
	if (active)
	{
		position += direction * speed * dt;
		SetPosition(position);

		// ȭ���� ������� Ȯ��
		if (!IsWithinBounds())
		{
			// ���� ��Ȱ��ȭ�ϰų� �����ϴ� ���� �߰�
			active = false;
			// �Ǵ� �ʿ信 ���� ���� �����ϴ� �ڵ� �߰�
		}
	}
	else
	{
		deactivateTimer += dt;
		if (deactivateTimer >= deactivateTime)
		{
			active = true;
			deactivateTimer = 0.f;
			Reset(); // ��Ȱ��ȭ �Ⱓ�� ������ �ٽ� �ʱ�ȭ
		}
	}
}


void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

bool Enemy::IsWithinBounds() const
{
	sf::FloatRect globalBounds = body.getGlobalBounds();

	// ȭ�� ũ��
	const float screenWidth = 1920.f;
	const float screenHeight = 1080.f;

	// ���� ȭ���� ������� Ȯ��
	if (globalBounds.left + globalBounds.width < 0 || // �������� ���
		globalBounds.left > screenWidth ||            // ���������� ���
		globalBounds.top + globalBounds.height < 0 || // ���� ���
		globalBounds.top > screenHeight)              // �Ʒ��� ���
	{
		return false;
	}
	return true;
}

void Enemy::SetType(Types type)
{

	this->types = type; // Ÿ������
	const auto& data = ENEMY_TABLE->Get(type);
	textureId = data.textureId;
	min_speed = data.min_speed;
	max_speed = data.max_speed;
	damage = data.damage;

	body.setTexture(TEXTURE_MGR.Get(textureId));
}

void Enemy::OnDamage(int damage)
{
}

void Enemy::Deactivate(float duration)
{
	active = false;
	deactivateTime = duration; // ��Ȱ��ȭ ���� �ð� ����
	deactivateTimer = 0.f;
}
