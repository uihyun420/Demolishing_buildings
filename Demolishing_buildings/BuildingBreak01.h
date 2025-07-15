#pragma once
#include "GameObject.h"
#include "Building.h"

class Building;
class BuildingBreak01 : public GameObject
{
protected:
	sf::Sprite break01;
	std::string break01texIds = "graphics/buildingbreak01.png";

	sf::Vector2f gravity = { 0.f, 150.f };
	sf::Vector2f velocity = { 0.f, 0.f };
	bool isGrounded = false;

	Building building;

public:
	BuildingBreak01(const std::string& name = "");
	virtual ~BuildingBreak01() = default;

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

