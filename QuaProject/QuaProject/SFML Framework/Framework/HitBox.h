#pragma once

class HitBox
{
private:

	bool isVisible;
public:
	HitBox();


	sf::RectangleShape rect;
	//sf::RectangleShape& GetRect() { return rect; }
	void UpdateTr(const sf::Transformable& tr, const sf::FloatRect& localBound);
	void Draw(sf::RenderWindow& window);

	bool IsMouseOver(const sf::Vector2f& mousePos);

	void SetVisible(bool visible);
	bool GetVisible() const;

	sf::FloatRect GetGlobalBounds() const;
};