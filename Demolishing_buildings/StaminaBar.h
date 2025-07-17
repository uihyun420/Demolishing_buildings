#pragma once
#include "GameObject.h"

class Player;
class StaminaBar : public GameObject
{
protected:
	sf::RectangleShape staminaBar;
	sf::Vector2f initSize;

	Player* player;
public:
	StaminaBar(const std::string& name = "");
	virtual ~StaminaBar() = default;

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

	void SetValue(float stamina, float maxstamina); // 얘가 플레이어와 이어져야 게이지가 줄어듬 

};

