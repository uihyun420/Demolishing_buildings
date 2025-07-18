#pragma once
#include "GameObject.h"
#include "TextGo.h"

class TextGo;

class MenuUi : public GameObject
{
protected:
	sf::Sprite chooseBar;
	std::string choosebartexIds = "graphics/choosebar.png";

	int selectIndex = 0; 
	std::vector<sf::Vector2f> barPositions; 

	sf::RectangleShape Square;
	std::vector<sf::Vector2f> squarePositions;

	TextGo* selectText;
	sf::String selecttexIds = "fonts/Galmuri11-Bold.ttf";

	
public:
	MenuUi(const std::string& name = "");
	virtual ~MenuUi() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float rot) override;
	void SetScale(const sf::Vector2f& s) override;
	void SetOrigin(const sf::Vector2f& o) override;
	void SetOrigin(Origins preset) override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

