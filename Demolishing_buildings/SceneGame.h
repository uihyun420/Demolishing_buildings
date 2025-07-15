#pragma once
#include "Scene.h"

class Player;
class BackGround;
class Building;
class Ground;
class Sky;
class BuildingBreak01;

class SceneGame : public Scene
{
protected:
	Player* player;
	BackGround* background;
	Building* building;
	Ground* ground;
	Sky* sky;
	BuildingBreak01* buildingbreak01;



	bool isGrounded = false;

public:
	SceneGame();
	~SceneGame() override = default;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

