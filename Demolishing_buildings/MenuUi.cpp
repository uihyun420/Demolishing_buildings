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
	chooseBar.setTexture(TEXTURE_MGR.Get(choosebartexIds));
	chooseBar.setPosition(FRAMEWORK.GetWindowSizeF().x /2 - 300.f, FRAMEWORK.GetWindowSizeF().y / 2);
	chooseBar.setScale(0.3f, 0.3f);
	SetOrigin(Origins::MC);
}

void MenuUi::Update(float dt)
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	

	if (InputMgr::GetKeyDown(sf::Keyboard::Up));
	{
		chooseBar.setPosition({ FRAMEWORK.GetWindowSizeF().x / 2 - 300.f, bounds.height / 2.f - 100.f });
	}


	if (InputMgr::GetKeyDown(sf::Keyboard::Down));
	{
		chooseBar.setPosition({ FRAMEWORK.GetWindowSizeF().x / 2 - 300.f, bounds.height / 2.f + 100.f });
	}

}

void MenuUi::Draw(sf::RenderWindow& window)
{
	window.draw(chooseBar);
}