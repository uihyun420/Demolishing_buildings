#pragma once
#include "GameObject.h"
class BackGround : public GameObject
{
protected:
	sf::Sprite Background;
	std::string texIds = "graphics/bg.png";

public:
	BackGround(const std::string& name = "");
	virtual ~BackGround() = default;

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

