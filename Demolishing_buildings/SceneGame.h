#pragma once
#include "Scene.h"

class Player;
class BackGround;
class Building;
class Ground;
class Sky;
class Debris;


class SceneGame : public Scene
{
protected:
	Player* player;
	BackGround* background;
	Building* building;
	Ground* ground;
	Sky* sky;
	Debris* debris;


	//bool isGrounded = false;

public:
	SceneGame();
	~SceneGame() override = default;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

