#include "stdafx.h"
#include "MenuUi.h"

MenuUi::MenuUi(const std::string& name)
	: GameObject(name)
{
}

void MenuUi::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	chooseBar.setPosition(pos);
}

void MenuUi::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	chooseBar.setRotation(rot);
}

void MenuUi::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	chooseBar.setScale(s);
}

void MenuUi::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	chooseBar.setOrigin(o);
}

void MenuUi::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(chooseBar, preset);
	}
}

void MenuUi::Init()
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 1;
}

void MenuUi::Release()
{
}

void MenuUi::Reset()
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	SetOrigin(Origins::MC);

	chooseBar.setTexture(TEXTURE_MGR.Get(choosebartexIds));
	chooseBar.setScale(0.3f, 0.3f);

	barPositions.clear();
	barPositions.push_back({ 350.f, 195.f });
	barPositions.push_back({ 350.f, 395.f });

	Square.setSize({ 200.f, 80.f });
	Square.scale(1.f, 1.f);
	Square.setFillColor(sf::Color::Transparent);
	Square.setOutlineColor(sf::Color::Red);
	Square.setOutlineThickness(5.f);

	squarePositions.clear();
	squarePositions.push_back({ 535.f, 225.f }); 
	squarePositions.push_back({ 535.f, 425.f }); 

	selectIndex = 0;
	chooseBar.setPosition(barPositions[selectIndex]);
	Square.setPosition(squarePositions[selectIndex]);

}

void MenuUi::Update(float dt)
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	if (InputMgr::GetKeyDown(sf::Keyboard::Up))
	{
		selectIndex = (selectIndex + barPositions.size() - 1) % barPositions.size();
		chooseBar.setPosition(barPositions[selectIndex]);
		Square.setPosition(squarePositions[selectIndex]);
		SOUND_MGR.Play(Audio::click); 
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Down))
	{
		selectIndex = (selectIndex + 1) % barPositions.size();
		chooseBar.setPosition(barPositions[selectIndex]);
		Square.setPosition(squarePositions[selectIndex]);
		SOUND_MGR.Play(Audio::click);
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		if (selectIndex == 0)
		{
			SCENE_MGR.ChangeScene(SceneIds::Easy);
		}
		if (selectIndex == 1)
		{
			SCENE_MGR.ChangeScene(SceneIds::Game);
		}
	}
}


void MenuUi::Draw(sf::RenderWindow& window)
{
	window.draw(chooseBar);
	window.draw(Square);
}
