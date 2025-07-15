#pragma once
#include "GameObject.h"
#include "HitBox.h"

class Player;
class BuildingBreak01;
class Building :  public GameObject
{
protected:
	sf::Sprite building;
	std::string texIds = "graphics/building.png";

	sf::Vector2f gravity = { 0.f, 150.f };
	sf::Vector2f velocity = { 0.f, 0.f }; 
	bool isGrounded = false;

	int attack = 0;
	int hp = 0;


	HitBox hitBox;
	BuildingBreak01* buildingbreak01;
	Player* player;

public:
	

	Building(const std::string& name = "");
	~Building() override = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float rot) override;
	void SetScale(const sf::Vector2f& s) override;
	void SetOrigin(const sf::Vector2f& o) override;
	void SetOrigin(Origins preset) override;


	// GameObject을(를) 통해 상속됨
	void Init() override;

	void Release() override;

	void Reset() override;

	void Update(float dt) override;

	void Draw(sf::RenderWindow& window) override;

	const sf::RectangleShape& GetHitBox() const;

	sf::Vector2f SetVelocity(const sf::Vector2f& vel) { return velocity = vel; }

	void TakeDamage(int damage);
	void Destroy();
	void SetPlayer(Player* p) { player = p; }


	void SetBuildingBreak01(BuildingBreak01* b) { buildingbreak01 = b; }
	

};

