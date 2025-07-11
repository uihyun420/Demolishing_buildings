#pragma once
#include "Scene.h"

class TextGo;
class SceneStart : public Scene
{
protected:
	sf::Sprite Background;
	sf::Text text;
	std::string textId;


public:
	SceneStart();

};

