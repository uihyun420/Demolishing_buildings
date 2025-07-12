#pragma once
#include "Scene.h"

class Player;
class BackGround;
class Building;

class SceneGame : public Scene
{
protected:
	Player* player;
	BackGround* background;
	Building* building;

public:
	SceneGame();
	~SceneGame() override = default;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

