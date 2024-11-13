#pragma once

class TileMap : public GameObject
{
protected:

	sf::VertexArray va;
	std::string spriteSheetId = "graphics/background_sheet.png";
	sf::Texture* texture = nullptr;
	sf::Transform transform;

	sf::Vector2i cellCount;
	sf::Vector2f cellSize;

public:
	TileMap(const std::string& name = "");
	~TileMap() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	sf::FloatRect GetLocalBounds() const override;
	sf::FloatRect GetGlobalBounds() const override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void Set(const sf::Vector2i& count, const sf::Vector2f& size);
	void UpdateTransform();

	bool CheckCollision(const sf::FloatRect& objectBounds) const;
};
