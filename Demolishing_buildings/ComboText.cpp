#include "stdafx.h"
#include "ComboText.h"

ComboText::ComboText(const std::string& fontIds, const std::string& name)
	:TextGo("fonts/Galmuri11-Bold.ttf", name)
{
}


void ComboText::Init()
{
	sortingLayer = SortingLayers::UI;
	sortingOrder = 1;

	TextGo::Init();
}
void ComboText::Reset()
{
	TextGo::Reset();

	sortingLayer = SortingLayers::UI;
	sortingOrder = 1;
	combo = -1;

	SetCombo(0);
	SetOrigin(Origins::MC);
	SetCharacterSize(35);
	SetFillColor(sf::Color::Red);
	//SetPosition({ FRAMEWORK.GetWindowSizeF().x / 2, FRAMEWORK.GetWindowSizeF().y / 2 });
	SetPosition({120, 130 });
}



void ComboText::SetCombo(int combo)
{
	this->combo++;
	SetString("Combo: " + std::to_string(this->combo));
	std::cout << "xx" << std::endl;
}

