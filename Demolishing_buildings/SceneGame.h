#pragma once
#include "Scene.h"

class Player;
class BackGround;
class Building;
class Ground;
class Sky;
class Debris;
class StaminaBar;
class ScoreText;



class SceneGame : public Scene
{
protected:
	Player* player;
	BackGround* background;
	Building* building;
	Ground* ground;
	Sky* sky;
	Debris* debris;
	StaminaBar* staminabar;
	ScoreText* scoreText;  // ui들도 게임씬에 그려야함 uiview라는게 따로 새로운 씬을 만들어서 하는게 아님 


public:
	SceneGame();
	~SceneGame() override = default;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

