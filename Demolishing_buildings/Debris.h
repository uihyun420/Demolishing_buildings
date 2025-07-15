#pragma once
#include "GameObject.h"

class Debris : public GameObject
{
protected:
	std::vector<sf::Sprite> debris;
	std::string debiristexIds;

public:
	Debris(const std::string& name = "");
	virtual ~Debris() = default;

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

