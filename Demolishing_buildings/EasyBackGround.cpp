#include "stdafx.h"
#include "EasyBackGround.h"



EasyBackGround::EasyBackGround(const std::string& name)
	: GameObject(name)
{
}

void EasyBackGround::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	easyBackground.setPosition(pos);
}

void EasyBackGround::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	easyBackground.setRotation(rot);
}

void EasyBackGround::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	easyBackground.setScale(s);
}

void EasyBackGround::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	easyBackground.setOrigin(o);
}

void EasyBackGround::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(easyBackground, preset);
	}
}

void EasyBackGround::Init()
{
	sortingLayer = SortingLayers::Background;
	sortingOrder = 0;
}

void EasyBackGround::Release()
{
}

void EasyBackGround::Reset()
{
	easyBackground.setTexture(TEXTURE_MGR.Get(texIds));
	easyBackground.setPosition(0.f, 360);
	easyBackground.setScale(2.f, 2.f);
	SetOrigin(Origins::BC);
}

void EasyBackGround::Update(float dt)
{
}

void EasyBackGround::Draw(sf::RenderWindow& window)
{
	window.draw(easyBackground);
}