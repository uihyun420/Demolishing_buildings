#include "stdafx.h"
#include "SpecialAttack.h"
#include "HitBox.h"
#include "Player.h"


SpecialAttack::SpecialAttack(const std::string& name)
	: GameObject(name)
{
}

void SpecialAttack::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	body.setPosition(pos);
}

void SpecialAttack::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	body.setRotation(rot);
}

void SpecialAttack::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	body.setScale(s);
}

void SpecialAttack::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	body.setOrigin(o);
}

void SpecialAttack::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(body, preset);
	}
}

void SpecialAttack::Init()
{
	SetActive(false); // 얘가 트루로 되어있었어서 게임 키면 한번 지가 알아서 날라가버림 false로 설정해놓고 사용할때 true로 설정되도록
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 1;

}

void SpecialAttack::Release()
{
}

void SpecialAttack::Reset()
{
	body.setTexture(TEXTURE_MGR.Get(specialtexIds), true);	
	body.setScale(2.f, 2.f);
	SetOrigin(Origins::ML);

	damage = 1000; 
	canspecialattack = true;
	speed = 4.f;
	velocity = { 0.f , -400.f };
}

void SpecialAttack::Update(float dt)
{
	SetPosition(position + velocity * speed * dt);
	hitBox.UpdateTransform(body, GetGlobalBounds()); 
}

void SpecialAttack::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	hitBox.Draw(window);
}

void SpecialAttack::Skill(const sf::Vector2f& pos, const sf::Vector2f& vel, float spd, int dmg)
{
	SetPosition(pos);
	velocity = vel;
	speed = spd;
	damage = dmg;
}

const sf::RectangleShape& SpecialAttack::GetHitBox() const
{
	return hitBox.rect;
}