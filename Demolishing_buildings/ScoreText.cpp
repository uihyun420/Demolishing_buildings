#include "stdafx.h"
#include "ScoreText.h"

ScoreText::ScoreText(const std::string& fontIds, const std::string& name)
	:TextGo("fonts/Galmuri11-Bold.ttf", name)
{
}
void ScoreText::Init()
{
	sortingLayer = SortingLayers::UI;
	sortingOrder = 1;

	TextGo Init();
}
void ScoreText::Reset()
{
	TextGo::Reset();

	sortingLayer = SortingLayers::UI;
	sortingOrder = 1;


	score = 0;
	SetScore(0);
	SetOrigin(Origins::TL); 
	SetCharacterSize(50);
	SetFillColor(sf::Color::White);
	//SetPosition({FRAMEWORK.GetWindowSizeF().x / 2, FRAMEWORK.GetWindowSizeF().y / 2});
}

void ScoreText::SetScore(int score)
{

	this->score += score;
	SetString("SCORE: " + std::to_string(this->score));
	//std::cout << "xxxx" << std::endl;
}