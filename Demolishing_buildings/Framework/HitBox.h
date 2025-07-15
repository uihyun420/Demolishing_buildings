#pragma once
class HitBox
{
public:
	HitBox();
	~HitBox() = default;

	sf::RectangleShape rect;
	bool isActive = true;

	void UpdateTransform(const sf::Transformable& tr, const sf::FloatRect& localBounds);
	void Draw(sf::RenderWindow& window);


};

