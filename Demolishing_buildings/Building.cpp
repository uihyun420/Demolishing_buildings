#include "stdafx.h"
#include "Building.h"
#include "HitBox.h"
#include "Player.h"

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
	building.setPosition(0.f, -2500.f);
	building.setScale(0.8f, 0.8f);
	isGrounded = false;
	SetOrigin(Origins::MC);
	SetActive(true);
	
	hp = 1000;
	attack = 1000;
}

void Building::Update(float dt)
{
	hitBox.UpdateTransform(building, building.getLocalBounds());

	if (!isGrounded)  
	{
		velocity.y += gravity.y * dt;
		building.move(velocity * dt);
	}

	if (building.getPosition().y >= -160.f) 
	{
		velocity.y = 0.f; 
		isGrounded = true;
	}


	if (Utils::CheckCollision(hitBox.rect, player->GetHitBox()))
	{
		sf::FloatRect buildingBounds = hitBox.rect.getGlobalBounds();
		sf::FloatRect playerBounds = player->GetHitBox().getGlobalBounds();


		if ((buildingBounds.top + buildingBounds.height) > 190 )
		{
			player->TakeDamage(attack);
		}
	}
	building.setPosition(building.getPosition().x, building.getPosition().y);
}


void Building::Draw(sf::RenderWindow& window)
{
	window.draw(building);
	hitBox.Draw(window);
}

const sf::RectangleShape& Building::GetHitBox() const
{
	return hitBox.rect;
}

void Building::TakeDamage(int attack)
{
	hp -= attack;
	if (hp <= 0)
	{
		hp = 0;
		Destroy();
	}
}

void Building::Destroy()
{
	SetActive(false);
}

