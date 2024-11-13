#pragma once
#include "GameObject.h"

class Player;
class HitBox;
class Item : public GameObject
{
public:
	enum class Types
	{
		Health,
	};
	static const int TotalTypes = 1;
protected:
	Types types = Types::Health;

	sf::Sprite body;
	std::string textureId;
	//HitBox* hitBox;
	sf::Vector2f direction;

	Player* player = nullptr;
public:
	Item(const std::string& name = "");
	~Item() = default;

	sf::Sprite& GetBody()
	{
		return body;
	}
	const sf::Sprite& GetBody() const { return body; }
	sf::FloatRect GetLocalBounds() const;
	sf::FloatRect GetGlobalBounds() const;
	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetType(Types type);
	void OnPickup(Player* player);
};
