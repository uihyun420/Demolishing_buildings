#include "stdafx.h"
#include "Ground.h"


Ground::Ground(const std::string& name)
	: GameObject(name)
{
}

void Ground::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	ground.setPosition(pos);
}

void Ground::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	ground.setRotation(rot);
}

void Ground::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	ground.setScale(s);
}

void Ground::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	ground.setOrigin(o);
}

void Ground::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(ground, preset);
	}
}



void Ground::Init()
{
}

void Ground::Release()
{
}

void Ground::Reset()
{
	ground.setTexture(TEXTURE_MGR.Get(groundtexIds));
	ground.setPosition(0.f, 1384.f);
	ground.setScale(1.f, 1.f);
	SetOrigin(Origins::BC);
}

void Ground::Update(float dt)
{
}

void Ground::Draw(sf::RenderWindow& window)
{
	window.draw(ground);
}