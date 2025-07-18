#pragma once
#include "Scene.h"

class TitleBackGround;
class MenuUi;


class SceneTitle : public Scene
{
protected:
	TitleBackGround* titlebackground;
	MenuUi* chooseBar;
	MenuUi* Square;

public:
	SceneTitle();
	~SceneTitle() override = default;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

