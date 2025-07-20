#pragma once
#include "Scene.h"

class Player;
class Ground;
class Sky;
class Debris;
class StaminaBar;
class ScoreText;
class ComboText;
class SpecialAttack;
class EasyBuilding;
class EasyBackGround;


class EasyScene : public Scene
{
protected:
	Player* player;
	EasyBackGround* easybackground;
	Ground* ground;
	Sky* sky;
	Debris* debris;
	StaminaBar* staminabar;
	ScoreText* scoreText;  // ui들도 게임씬에 그려야함 uiview라는게 따로 새로운 씬을 만들어서 하는게 아님 
	ComboText* comboText;
	SpecialAttack* specialAttack;
	EasyBuilding* easybuilding;

public:
	EasyScene();
	~EasyScene() override = default;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

