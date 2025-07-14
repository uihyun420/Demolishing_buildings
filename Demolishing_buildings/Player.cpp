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

	
	body.setTexture(TEXTURE_MGR.Get(texIds));
	body.setPosition(0.f, 190.f);
	body.setScale(0.5f, 0.5f);
	SetOrigin(Origins::BC);
	isGrounded = true;

}

void Player::Update(float dt)
{
	hitBox.UpdateTransform(body, body.getLocalBounds());

	//bool isCollidingWithBuilding = false; // 거눔ㄹ과 충돌 중인지 미리 체크 건물 안에 플레이어가 있다면 점프 못하게 하려고 설정 



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
	
	if (body.getPosition().y >= 190.f)
	{
		isGrounded = true;
		body.setTexture(TEXTURE_MGR.Get(texIds));
		body.setScale(0.5f, 0.5f);
		SetOrigin(Origins::MC);
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
				body.setPosition(body.getPosition() + building->GetPosition()); // 
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




