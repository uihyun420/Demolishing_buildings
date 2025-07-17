#pragma once
#include "Scene.h"

class TitleBackGround;

class SceneTitle : public Scene
{
protected:
	TitleBackGround* titlebackground;
public:
	SceneTitle();
	~SceneTitle() override = default;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

