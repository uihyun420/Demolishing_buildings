#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround(const std::string& name)
	: GameObject(name)
{
}

void BackGround::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	Background.setPosition(pos);
}

void BackGround::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	Background.setRotation(rot);
}

void BackGround::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	Background.setScale(s);
}

void BackGround::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	Background.setOrigin(o);
}

void BackGround::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(Background, preset);
	}
}



void BackGround::Init()
{
	sortingLayer = SortingLayers::Background;
	sortingOrder = 0;
}

void BackGround::Release()
{
}

void BackGround::Reset()
{
	Background.setTexture(TEXTURE_MGR.Get(texIds));
	Background.setPosition(0.f, 360);
	SetOrigin(Origins::BC);
}

void BackGround::Update(float dt)
{
}

void BackGround::Draw(sf::RenderWindow& window)
{
	window.draw(Background);
}