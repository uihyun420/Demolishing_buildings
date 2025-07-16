#pragma once
#include "GameObject.h"
#include "HitBox.h"
class Building;
class StaminaBar;

class Player : public GameObject
{
protected:
	sf::Sprite body;
	std::string texIds = "graphics/stand.png";
	std::string texIdsJump = "graphics/jump.png";
	std::string texIdsAttack = "graphics/standattack.png";
	std::string texIdsJumpAttack = "graphics/jumpattack.png";
	std::string texIdsstandguard = "graphics/standguard.png";

	sf::Vector2f gravity = { 0.f, 150.f };
	sf::Vector2f velocity = { 0.f, 0.f };
	bool isGrounded = true;
	bool isAttack = false;
	bool isDefense = false;

	//bool isActive = true;
	float speed = 1000.f;

	int attack = 0;
	float attackinterval = 0.5f;
	float hitinterval = 1.f;
	int hp = 100;


	float stamina = 100.f;
	float maxstamina = 100.f;


	int score = 0;

	float staminaDecrease = 30.f;
	float staminaRicovery = 20.f;

	bool canDefense = true;

	HitBox hitBox;
	Building* building;
	StaminaBar* staminabar;

public:
	Player(const std::string& name = "");
	~Player() override = default;

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
	
	void SetBuilding(Building* b) { building = b; } 
	void BodyReset();

	void TakeDamage(int damage);
	void Die();

	void SetStamina(StaminaBar* s) { staminabar = s; }
};

