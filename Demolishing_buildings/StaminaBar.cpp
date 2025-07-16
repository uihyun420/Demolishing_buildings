#include "stdafx.h"
#include "StaminaBar.h"


StaminaBar::StaminaBar(const std::string& name)
	: GameObject(name)
{
}

void StaminaBar::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	staminaBar.setPosition(pos);
}

void StaminaBar::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	staminaBar.setRotation(rot);
}

void StaminaBar::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	staminaBar.setScale(s);
}

void StaminaBar::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	staminaBar.setOrigin(o);
}

void StaminaBar::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(staminaBar, preset);
	}
}

void StaminaBar::Init()
{
	initSize = { 400.f, 80.f };
	sortingLayer = (SortingLayers::UI);
	sortingOrder = 0;
	SetOrigin(Origins::MC);
}

void StaminaBar::Release()
{
}

void StaminaBar::Reset()
{
	initSize = { 400.f, 80.f };
	staminaBar.setFillColor(sf::Color::Red);
	staminaBar.setSize(initSize);

	SetPosition({ FRAMEWORK.GetWindowSizeF().x / 2 ,FRAMEWORK.GetWindowSizeF().y - 100.f });
}

void StaminaBar::Update(float dt)
{
}

void StaminaBar::Draw(sf::RenderWindow& window)
{
	window.draw(staminaBar);
}

//void StaminaBar::SetStaminaBar(float stamina, float maxstamina)
//{
//	staminaBar.setSize({ initSize.x * (stamina / (float)maxstamina) , initSize.y });
//}
