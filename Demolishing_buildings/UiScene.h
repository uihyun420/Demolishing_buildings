#pragma once
#include "Scene.h"

class TextGo;
class ScoreText;
class Player;
class UiScene : public Scene
{
protected:
	ScoreText* scoreText;
	Player* player;

public:
	UiScene();
	~UiScene() = default;

	void Init() override;
	void Enter() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

