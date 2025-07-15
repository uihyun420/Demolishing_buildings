#pragma once
#include "GameObject.h"
class Debris : public GameObject
{
protected:
	std::vector<sf::Sprite> debris;
	std::string debrisTexIds;

	std::vector<sf::Vector2f> velocity;
	sf::Vector2f gravity = { 0.f, 500.f };

	std::vector<std::string> debrisTexIdsList = 
	{
		"graphics/buildingbreak01.png",
		"graphics/buildingbreak02.png",
		"graphics/buildingbreak03.png",
		"graphics/buildingbreak04.png"
	};
public:
	Debris(const std::string& name = "");
	virtual ~Debris() = default;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SpawnDebris(const sf::Vector2f& pos, int count);
};

