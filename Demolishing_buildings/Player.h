#pragma once
#include "GameObject.h"

class Player : public GameObject
{
protected:

	sf::Sprite body;
	std::string texIds = "graphics/stand.png";
	std::string texIdsJump = "graphics/jump.png";
	

	sf::Vector2f gravity = { 0.f, 100.f };
	sf::Vector2f velocity = { 0.f, 0.f };
	bool isGrounded = true;
	float speed = 0.f;

	
	int attack = 0;
	int hp = 100;

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

