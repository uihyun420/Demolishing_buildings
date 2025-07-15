#include "stdafx.h"
#include "Debris.h"


	Debris::Debris(const std::string & name)
		: GameObject(name)
	{
	}

	void Debris::SetPosition(const sf::Vector2f & pos)
	{
		GameObject::SetPosition(pos);
		debris.setPosition(pos);
	}

	void Debris::SetRotation(float rot)
	{
		GameObject::SetRotation(rot);
		debris.setRotation(rot);
	}

	void Debris::SetScale(const sf::Vector2f & s)
	{
		GameObject::SetScale(s);
		debris.setScale(s);
	}

	void Debris::SetOrigin(const sf::Vector2f & o)
	{
		GameObject::SetOrigin(o);
		debris.setOrigin(o);
	}

	void Debris::SetOrigin(Origins preset)
	{
		GameObject::SetOrigin(preset);
		if (preset != Origins::Custom)
		{
			Utils::SetOrigin(debris, preset);
		}
	}

	void Debris::Init()
	{
	}

	void Debris::Release()
	{
	}

	void Debris::Reset()
	{
	}

	void Debris::Update(float dt)
	{
	}

	void Debris::Draw(sf::RenderWindow & window)
	{
		window.draw(debris);
	}
