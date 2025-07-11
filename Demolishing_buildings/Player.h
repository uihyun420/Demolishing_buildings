#pragma once
#include "GameObject.h"
#include "SpriteGo.h"

class Player : public GameObject
{
protected:
	sf::Sprite body;
	std::string texIds = "graphics/stand.png";

	int attack = 0;
	int Hp = 100;

public:
	Player(const std::string& name = "");
	~Player() override = default;

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

