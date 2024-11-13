#pragma once
#include "GameObject.h"
class TextGo : public GameObject
{
protected:
	std::string fontId;
	sf::Text text;
	std::string stringId;
public:

	TextGo(const std::string& fontId, const std::string& name = "");
	~TextGo() = default;

	void SetOrigin(Origins preset);
	void SetOrigin(const sf::Vector2f& newOrigin);

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	void Set(int size, const sf::Color& color = sf::Color::White);
	void SetString(const std::string& str);
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetTextString(const std::string& str);
	void SetFillColor(sf::Color color);

	void OnLocalize(Languages lang) override;
};

