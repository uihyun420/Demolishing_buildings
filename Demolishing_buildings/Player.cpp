#include "stdafx.h"
#include "Player.h"


Player::Player(const std::string& name)
	: GameObject(name)
{
}

void Player::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	body.setPosition(pos);
}

void Player::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	body.setRotation(rot);
}

void Player::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	body.setScale(s);
}

void Player::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	body.setOrigin(o);
}

void Player::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(body, preset);
	}
}


void Player::Init()
{

}

void Player::Release()
{
}

void Player::Reset()
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 1;

	body.setTexture(TEXTURE_MGR.Get(texIds));
	body.setPosition(0.f, 190.f);
	body.setScale(0.5f, 0.5f);
	SetOrigin(Origins::MC);
}

void Player::Update(float dt)
{

	if (isGrounded && InputMgr::GetKeyDown(sf::Keyboard::Up))
	{
		isGrounded = false;
		body.setTexture(TEXTURE_MGR.Get(texIdsJump)); 
		body.setScale(0.5f, 0.5f); 
		SetOrigin(Origins::MC); 
		body.setPosition(body.getPosition().x, body.getPosition().y); 

		velocity.y = -300.f; 
		speed = 500.f; 
	}

	if (!isGrounded)
	{
		velocity += gravity * dt;
		body.move(velocity * dt);
	}
	
	SetPosition(body.getPosition()); 
}


void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}



