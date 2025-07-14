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
	
	body.setTexture(TEXTURE_MGR.Get(texIds) , true);
	//body.setTexture(TEXTURE_MGR.Get(texIdsJumpAttack));
	body.setPosition(0.f, 190.f);
	body.setScale(0.5f, 0.5f);
	SetOrigin(Origins::BC);
	isGrounded = true;
	isStandAttack = false;
	isStandDefense = false;
	isattack = false;
}

void Player::Update(float dt)

{
	attackinterval += dt;

	hitBox.UpdateTransform(body, body.getLocalBounds());

	if (!isGrounded)
	{
		velocity += gravity * dt;
		body.move(velocity * dt);
	}

	if (body.getPosition().y >= 190.f)
	{
		isGrounded = true;
		body.setTexture(TEXTURE_MGR.Get(texIds) , true);
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

	if (!isStandAttack && InputMgr::GetKeyDown(sf::Keyboard::Z))
	{
		body.setTexture(TEXTURE_MGR.Get(texIdsJumpAttack) , true); // 텍스트 사이즈가 다 달라서 하나하나 불러올 때마다 true로 설정해줘야함.
		body.setScale(0.5f, 0.5f);
		SetOrigin(Origins::MC);
		body.setPosition(body.getPosition().x, body.getPosition().y);
		isStandAttack = true;
		isGrounded = false;
	}

	if (isStandAttack && InputMgr::GetKeyUp(sf::Keyboard::Z))
	{
		attackinterval = 1.f;
		body.setTexture(TEXTURE_MGR.Get(texIds) , true);
		body.setScale(0.5f, 0.5f);
		SetOrigin(Origins::MC);
		body.setPosition(body.getPosition().x, body.getPosition().y);
		isStandAttack = false;
	}

	if (isattack)
	{
		if (isGrounded && InputMgr::GetKeyDown(sf::Keyboard::Down))
		{
			body.setTexture(TEXTURE_MGR.Get(texIdsstandguard), true);
			body.setScale(0.5f, 0.5f);
			SetOrigin(Origins::MC);
			body.setPosition(body.getPosition().x, body.getPosition().y);
		}

		if (!isStandDefense && InputMgr::GetKeyDown(sf::Keyboard::Down))
		{
			isStandDefense = true;
			body.setTexture(TEXTURE_MGR.Get(texIdsstandguard), true);
			body.setScale(0.5f, 0.5f);
			SetOrigin(Origins::MC);
			body.setPosition(body.getPosition().x, body.getPosition().y);
		}
	}
	

	if (isStandDefense && InputMgr::GetKeyUp(sf::Keyboard::Down))
	{
		isStandDefense = false;
		body.setTexture(TEXTURE_MGR.Get(texIdsJump), true);
		body.setScale(0.5f, 0.5f);
		SetOrigin(Origins::MC);
		body.setPosition(body.getPosition().x, body.getPosition().y);
	}


	if (building) // 빌딩 객체가 설정되어 있는 경우에만 충돌 검사 진행
	{
		if (Utils::CheckCollision(hitBox.rect, building ->GetHitBox())) 
		{
			sf::FloatRect playerBounds = hitBox.rect.getGlobalBounds(); 
			sf::FloatRect buildingBounds = building->GetHitBox().getGlobalBounds(); 
			//std::cout << "xxxx" << std::endl; 

			sf::Vector2f push = { 0.f, 150.f };

			if (velocity.y < 0 && playerBounds.top < buildingBounds.height)
			{
				//velocity.y = 400;
				velocity = building->SetVelocity(push);
			}

			if (Utils::CheckCollision(hitBox.rect, building->GetHitBox()))
			{
				if (InputMgr::GetKeyDown(sf::Keyboard::Down))
				{
					body.setTexture(TEXTURE_MGR.Get(texIdsstandguard), true);
					body.setScale(0.5f, 0.5f);
					SetOrigin(Origins::MC);
					body.setPosition(body.getPosition().x, body.getPosition().y);
					building->SetVelocity({0.f, -80.f});
					velocity.y = 1200.f;
				}
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

//bool Player::PlayerJump()
//{
//	return !isGrounded;
//}
