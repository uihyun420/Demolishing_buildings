#pragma once
#include "GameObject.h"
class TitleBackGround :
    public GameObject
{
protected:
	sf::Sprite Bg;
	std::string BgtexIds = "graphics/title.png";
public:
	TitleBackGround(const std::string& name = "");
	virtual ~TitleBackGround() = default;

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

