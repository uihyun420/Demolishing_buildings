#include "stdafx.h"
#include "Player.h"
#include "Scene.h"
#include "Building.h"
#include "Utils.h"
#include "StaminaBar.h"

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
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 1;

}

void Player::Release()
{
}

void Player::Reset()
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 1;

	body.setTexture(TEXTURE_MGR.Get(texIds), true);
	body.setPosition(0.f, 190.f);
	body.setScale(0.5f, 0.5f);
	SetOrigin(Origins::MC);
	SetActive(true);
	isGrounded = true;
	isAttack = false;
	isDefense = false;
	canDefense = true;

	hp = 300;
	attack = 50;
	attackinterval = 1.f;

	stamina = 100.f;
	maxstamina = 100.f;
	score = 0;

	staminaDecrease = 30.f;
	staminaRicovery = 20.f;
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
		if (!isAttack && !isDefense)
		{
			body.setTexture(TEXTURE_MGR.Get(texIds), true);
			body.setScale(0.5f, 0.5f);
			SetOrigin(Origins::MC);
			body.setPosition(body.getPosition().x, 190.f);
		}
	}

	if (isGrounded && InputMgr::GetKeyDown(sf::Keyboard::Up))
	{
		isGrounded = false;
		body.setTexture(TEXTURE_MGR.Get(texIdsJump));
		BodyReset();
		velocity.y = -3000.f;
	}

	if (!isAttack && InputMgr::GetKeyDown(sf::Keyboard::Z))
	{
		if (isGrounded)
		{
			body.setTexture(TEXTURE_MGR.Get(texIdsAttack), true); // 텍스트 사이즈가 다 달라서 하나하나 불러올 때마다 true로 설정해줘야함.
		}
		else
		{
			body.setTexture(TEXTURE_MGR.Get(texIdsJumpAttack), true);
		}
		BodyReset();
		isAttack = true;
	}

	if (isAttack && InputMgr::GetKeyUp(sf::Keyboard::Z))
	{
		body.setTexture(TEXTURE_MGR.Get(texIds), true);
		BodyReset();
		isAttack = false;
	}


	if (building) // 빌딩 객체가 설정되어 있는 경우에만 충돌 검사 진행
	{
		if (Utils::CheckCollision(hitBox.rect, building->GetHitBox()))
		{
			sf::FloatRect playerBounds = hitBox.rect.getGlobalBounds();
			sf::FloatRect buildingBounds = building->GetHitBox().getGlobalBounds();
			//std::cout << "xxxx" << std::endl; 

			sf::Vector2f push = { 0.f, 300.f };

			if (velocity.y < 0 && playerBounds.top < buildingBounds.height)
			{
				velocity = building->SetVelocity(push);
			}

			if (Utils::CheckCollision(hitBox.rect, building->GetHitBox()))
			{
				if (InputMgr::GetKeyDown(sf::Keyboard::Down))
				{
					isDefense = true;
					body.setTexture(TEXTURE_MGR.Get(texIdsstandguard), true);
					BodyReset();
					building->SetVelocity({ 0.f, -300.f });
					velocity.y = 3000.f;
				}

				if (InputMgr::GetKeyDown(sf::Keyboard::Z) && isAttack && attackinterval >= 0.5f)
				{
					attackinterval = 1.0f;
					building->TakeDamage(attack);
				}
			}
		}
	}

	if (!isDefense && canDefense && InputMgr::GetKeyDown(sf::Keyboard::Down) && stamina <= maxstamina)  // 초기 상태에서 다운 키를 누르면 
	{
		isDefense = true;
		body.setTexture(TEXTURE_MGR.Get(texIdsstandguard), true);

		BodyReset();
	}

	if (isDefense)
	{
		stamina -= staminaDecrease * dt;
		if (stamina < 0.f)
		{
			stamina = 0.f;
			canDefense = false;
			isDefense = false;
			body.setTexture(TEXTURE_MGR.Get(texIds), true);
			BodyReset();
		}
		staminabar->SetValue(stamina , 100);
	}

	if (!isDefense)
	{
		stamina += staminaRicovery * dt;
		if (stamina > 10.f)
		{
			canDefense = true;

			if (stamina > maxstamina)
			{
				stamina = maxstamina;
			}
		}
		staminabar->SetValue(stamina, 100);
	}


	if (isDefense && InputMgr::GetKeyUp(sf::Keyboard::Down))  
	{
		isDefense = false;
		body.setTexture(TEXTURE_MGR.Get(texIds), true);

		BodyReset();
	}

	SetPosition(body.getPosition());
}



void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	hitBox.Draw(window);
}

const sf::RectangleShape& Player::GetHitBox() const
{
	return hitBox.rect;
}

void Player::BodyReset()
{
	body.setScale(0.5f, 0.5f);
	SetOrigin(Origins::MC);
	body.setPosition(body.getPosition().x, body.getPosition().y);
}


void Player::TakeDamage(int damage)
{
	hp -= damage;
	if (hp <= 0)
	{
		hp = 0;
		Die();
	}
}

void Player::Die()
{
	SetActive(false);
}

void Player::SetStaminaBarGage(StaminaBar* staminabar)
	{
		this->staminabar = staminabar;
	}


