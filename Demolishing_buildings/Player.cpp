#include "stdafx.h"
#include "Player.h"
#include "Scene.h"
#include "Building.h"
#include "Utils.h"


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

	attackinterval = 0.2f;
	
	body.setTexture(TEXTURE_MGR.Get(texIds));
	body.setPosition(0.f, 190.f);
	body.setScale(0.5f, 0.5f);
	SetOrigin(Origins::BC);
	isGrounded = true;
	isStandAttack = false;
}

void Player::Update(float dt)
{
	hitBox.UpdateTransform(body, body.getLocalBounds());

	if (body.getPosition().y >= 190.f)
	{
		isGrounded = true;
		isStandAttack = false;
		body.setTexture(TEXTURE_MGR.Get(texIds));
		body.setScale(0.5f, 0.5f);
		SetOrigin(Origins::MC);
	}

	if (isGrounded && InputMgr::GetKeyDown(sf::Keyboard::Up))
	{
		isGrounded = false;
		body.setTexture(TEXTURE_MGR.Get(texIdsJump)); 
		body.setScale(0.5f, 0.5f); 
		SetOrigin(Origins::MC); 
		body.setPosition(body.getPosition().x, body.getPosition().y); 
		velocity.y = -1500.f; 
	}

	if (!isGrounded)
	{
		velocity += gravity * dt;
		body.move(velocity * dt);
	}
	

	if (!isStandAttack && InputMgr::GetKeyDown(sf::Keyboard::Z))
	{
		body.setTexture(TEXTURE_MGR.Get(texIdsAttack));
		body.setScale(0.5f, 0.5f);
		SetOrigin(Origins::MC);
		body.setPosition(body.getPosition().x, body.getPosition().y);
		isStandAttack = true;
	}

	if (isStandAttack && InputMgr::GetKeyUp(sf::Keyboard::Z))
	{
		body.setTexture(TEXTURE_MGR.Get(texIds));
		body.setScale(0.5f, 0.5f);
		SetOrigin(Origins::MC);
		body.setPosition(body.getPosition().x, body.getPosition().y);
		isStandAttack = false;
	}



	if (building) // 빌딩 객체가 설정되어 있는 경우에만 충돌 검사 진행
	{
		if (Utils::CheckCollision(hitBox.rect, building ->GetHitBox())) 
		{
			sf::FloatRect playerBounds = hitBox.rect.getGlobalBounds(); 
			sf::FloatRect buildingBounds = building->GetHitBox().getGlobalBounds(); 
			//std::cout << "xxxx" << std::endl; 

			if (velocity.y < 0 && playerBounds.top < buildingBounds.top + buildingBounds.height)
			{
				velocity.y = 0;
				// 플레이어와 건물이 아예 안겹치도록 해야함 건물과 플레이어의 히트박스가 닿았을 때 건물이 플레이어를 밀어내도록 
			}
		}
	}
	

	SetPosition(body.getPosition()); 
}


void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	hitBox.Draw(window);
}

bool Player::PlayerJump()
{
	return !isGrounded;
}




