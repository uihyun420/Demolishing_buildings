#include "stdafx.h"
#include "Sky.h"


Sky::Sky(const std::string& name)
	: GameObject(name)
{
}

void Sky::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	sky.setPosition(pos);
}

void Sky::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	sky.setRotation(rot);
}

void Sky::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	sky.setScale(s);
}

void Sky::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	sky.setOrigin(o);
}

void Sky::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(sky, preset);
	}
}

void Sky::Init()
{
}

void Sky::Release()
{
}

void Sky::Reset()
{
	sortingLayer = SortingLayers::Background;
	sortingOrder = 0;
	sky.setTexture(TEXTURE_MGR.Get(skytexIds));
	sky.setPosition(0.f, -1900.f);
	sky.setScale(1.f, 1.f);
	SetOrigin(Origins::MC);
}

void Sky::Update(float dt)
{
}

void Sky::Draw(sf::RenderWindow& window)
{
	window.draw(sky);
}