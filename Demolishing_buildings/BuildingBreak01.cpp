#include "stdafx.h"
#include "BuildingBreak01.h"
#include "Building.h"


BuildingBreak01::BuildingBreak01(const std::string& name)
	: GameObject(name)
{
}

void BuildingBreak01::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	break01.setPosition(pos);
}

void BuildingBreak01::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	break01.setRotation(rot);
}

void BuildingBreak01::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	break01.setScale(s);
}

void BuildingBreak01::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	break01.setOrigin(o);
}

void BuildingBreak01::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(break01, preset);
	}
}

void BuildingBreak01::Init()
{
}

void BuildingBreak01::Release()
{
}

void BuildingBreak01::Reset()
{

	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;
	break01.setTexture(TEXTURE_MGR.Get(break01texIds));
	break01.setPosition(0.f, -2500.f);
	break01.setScale(0.8f, 0.8f);
	isGrounded = false;
	SetOrigin(Origins::MC);
	SetActive(false);
}

void BuildingBreak01::Update(float dt)
{
	if (!isGrounded)
	{
		velocity.y += gravity.y * dt;
		break01.move(velocity * dt);
	}

	if (break01.getPosition().y >= -160.f)
	{
		velocity.y = 0.f;
		isGrounded = true;
		SetActive(false);
	}

	break01.setPosition(building.GetPosition().x, building.GetPosition().y);
}

void BuildingBreak01::Draw(sf::RenderWindow& window)
{
	window.draw(break01);
}