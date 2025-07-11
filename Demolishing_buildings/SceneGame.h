#pragma once
#include "Scene.h"

class Player;
class SceneGame : public Scene
{
protected:
	Player* player;
public:
	SceneGame();
	~SceneGame() override = default;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

