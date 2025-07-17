#pragma once
#include "GameObject.h"
#include "HitBox.h"

class HitBox;
class Player;
class SpecialAttack : public GameObject
{
protected:
	int damage;
	bool canspecialattack = true;
	float speed;
	sf::Vector2f velocity = {0.f,0.f};

	sf::Sprite body;
	std::string specialtexIds = "graphics/specialattack.png";

	HitBox hitBox;
	Player* player;

public:
	SpecialAttack(const std::string& name = "");
	virtual ~SpecialAttack() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float rot) override;
	void SetScale(const sf::Vector2f& s) override;
	void SetOrigin(const sf::Vector2f& o) override;
	void SetOrigin(Origins preset) override;

	const sf::RectangleShape& GetHitBox() const;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void Skill(const sf::Vector2f& pos, const sf::Vector2f& dir, float spd, int dmg);
	void SetPlayer(Player* p) { player = p; }
};

