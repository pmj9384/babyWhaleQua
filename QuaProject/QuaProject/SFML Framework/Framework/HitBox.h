#pragma once

class HitBox
{
private:

	bool isVisible;
	bool isActive;
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

	// 활성화 상태 설정
	void SetActive(bool active); // 값을 설정하기 위한 함수
	bool GetActive() const;      // 활성화 상태를 반환
};