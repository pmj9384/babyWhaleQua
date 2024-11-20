#include "stdafx.h"
#include "HitBox.h"

HitBox::HitBox() : isVisible(false) 
{
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color::Green);
	rect.setOutlineThickness(1.f);
}

void HitBox::UpdateTr(const sf::Transformable& tr, const sf::FloatRect& localBounds)
{
	rect.setOutlineColor(sf::Color::Green);
	rect.setSize({ localBounds.width, localBounds.height });
	rect.setOrigin(tr.getOrigin());
	/*rect.setPosition(tr.getPosition());*/
	rect.setPosition(tr.getPosition() + sf::Vector2f(localBounds.left, localBounds.top));
	rect.setScale(tr.getScale());
	rect.setRotation(tr.getRotation());
}

void HitBox::Draw(sf::RenderWindow& window)
{
	//if (Variables::isDrawHitBox)
	//	window.draw(rect);
	if (isVisible)
	{
		window.draw(rect); // 디버깅 시 히트박스를 화면에 표시
	}
}

bool HitBox::IsMouseOver(const sf::Vector2f& mousePos)
{
	return rect.getGlobalBounds().contains(mousePos);
}

void HitBox::SetVisible(bool visible)
{
	isVisible = visible;
}

bool HitBox::GetVisible() const
{
	return isVisible;

}

sf::FloatRect HitBox::GetGlobalBounds() const
{
	return rect.getGlobalBounds();
}
