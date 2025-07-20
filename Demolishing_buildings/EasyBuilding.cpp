#include "stdafx.h"
#include "EasyBuilding.h"
#include "HitBox.h"
#include "Player.h"
#include "Debris.h"

EasyBuilding::EasyBuilding(const std::string& name)
	:GameObject(name)
{
}

void EasyBuilding::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	easybuilding.setPosition(pos);
}

void EasyBuilding::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	easybuilding.setRotation(rot);
}

void EasyBuilding::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	easybuilding.setScale(s);
}

void EasyBuilding::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	easybuilding.setOrigin(o);
}

void EasyBuilding::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(easybuilding, preset);
	}
}

void EasyBuilding::Init()
{
}

void EasyBuilding::Release()
{
}

void EasyBuilding::Reset()
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;
	easybuilding.setTexture(TEXTURE_MGR.Get(easytexIds));
	easybuilding.setPosition(0.f, -2000.f);
	easybuilding.setScale(1.5f, 1.5f);


	SetOrigin(Origins::MC);
	SetActive(true);
	isGrounded = false;

	velocity = { 0.f, 0.f };
	gravity = { 0.f, 100.f };

	hp = 500;
	attack = 500;
}

void EasyBuilding::Update(float dt)
{
	if (!GetActive()) return; // 활성화되지 않은 경우 업데이트하지 않음

	hitBox.UpdateTransform(easybuilding, easybuilding.getLocalBounds());


	if (!isGrounded)
	{
		velocity.y += gravity.y * dt;
		easybuilding.move(velocity * dt);
	}

	if (easybuilding.getPosition().y >= -160.f)
	{
		velocity.y = 0.f;
		isGrounded = true;
	}


	if (Utils::CheckCollision(hitBox.rect, player->GetHitBox()))
	{
		sf::FloatRect buildingBounds = hitBox.rect.getGlobalBounds();
		sf::FloatRect playerBounds = player->GetHitBox().getGlobalBounds();


		if ((buildingBounds.top + buildingBounds.height) > 190)
		{
			player->TakeDamage(attack);
		}
	}
	easybuilding.setPosition(easybuilding.getPosition().x, easybuilding.getPosition().y);
}


void EasyBuilding::Draw(sf::RenderWindow& window)
{
	window.draw(easybuilding);
	hitBox.Draw(window);
}

const sf::RectangleShape& EasyBuilding::GetHitBox() const
{
	return hitBox.rect;
}

void EasyBuilding::TakeDamage02(int attack)
{
	hp -= attack;
	if (hp <= 0)
	{
		hp = 0;
		Destroy();

	}
}

void EasyBuilding::Destroy()
{
	SetActive(false);
	hitBox.SetActive(false);
	hitBox.rect.setSize({ 0.f, 0.f });
	SOUND_MGR.Play(Audio::buildingbreak);

	if (debris)
	{
		debris->SpawnDebris(easybuilding.getPosition(), 4);
	}
}

