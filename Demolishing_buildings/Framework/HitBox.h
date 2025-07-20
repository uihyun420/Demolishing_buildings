#pragma once
class HitBox
{
public:
	HitBox();
	~HitBox() = default;

	sf::RectangleShape rect;
	bool active = true;
	bool IsActive() const { return active; }
	void SetActive(bool a) { active = a; }

	void UpdateTransform(const sf::Transformable& tr, const sf::FloatRect& localBounds);
	void Draw(sf::RenderWindow& window);

};

