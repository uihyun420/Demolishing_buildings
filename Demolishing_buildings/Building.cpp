#include "stdafx.h"
#include "Building.h"


Building::Building(const std::string& name)
	:GameObject(name)
{
}

void Building::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	building.setPosition(pos);
}

void Building::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	building.setRotation(rot);
}

void Building::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	building.setScale(s);
}

void Building::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	building.setOrigin(o);
}

void Building::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(building, preset);
	}
}



void Building::Init()
{
}

void Building::Release()
{
}

void Building::Reset()
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;
	building.setTexture(TEXTURE_MGR.Get(texIds));
	building.setPosition(0.f, -2000.f);
	building.setScale(1.f, 1.f);
	SetOrigin(Origins::MC);
}

void Building::Update(float dt)
{
	if (!isGrounded)  
	{
		velocity.y += gravity.y * dt;
		building.move(velocity * dt);
	}

	if (building.getPosition().y >= -50.f) 
	{
		velocity.y = 0.f; 
		isGrounded = true;
	}

	building.setPosition(building.getPosition().x, building.getPosition().y);

}

void Building::Draw(sf::RenderWindow& window)
{
	window.draw(building);
}
