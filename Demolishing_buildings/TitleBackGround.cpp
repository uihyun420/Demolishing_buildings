#include "stdafx.h"
#include "TitleBackGround.h"


TitleBackGround::TitleBackGround(const std::string& name)
	: GameObject(name)
{
}

void TitleBackGround::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	Bg.setPosition(pos);
}

void TitleBackGround::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	Bg.setRotation(rot);
}

void TitleBackGround::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	Bg.setScale(s);
}

void TitleBackGround::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	Bg.setOrigin(o);
}

void TitleBackGround::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(Bg, preset);
	}
}

void TitleBackGround::Init()
{
	sortingLayer = SortingLayers::Background;
	sortingOrder = 0;
}

void TitleBackGround::Release()
{
}

void TitleBackGround::Reset()
{
	Bg.setTexture(TEXTURE_MGR.Get(BgtexIds), true);
	//Bg.setPosition({ 0.f,0.f });
	SetPosition({FRAMEWORK.GetWindowSizeF().x / 2, FRAMEWORK.GetWindowSizeF().y / 2});
	SetOrigin(Origins::MC);
	Bg.setScale(0.8f, 0.8f);
}

void TitleBackGround::Update(float dt)
{
}

void TitleBackGround::Draw(sf::RenderWindow& window)
{
	window.draw(Bg);
}