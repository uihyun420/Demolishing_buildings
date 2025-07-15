#include "stdafx.h"
#include "Debris.h"


Debris::Debris(const std::string& name)
	: GameObject(name)
{
}

void Debris::Init()
{
}

void Debris::Release()
{
}

void Debris::Reset()
{
	SetType((Types)Utils::RandomRange(0, (int)Types::TypeCount));
	debris.setTexture(TEXTURE_MGR.Get(debristexIds), true);
}

void Debris::Update(float dt)
{
}

void Debris::Draw(sf::RenderWindow& window)
{
	window.draw(debris);
}

void Debris::SetType(Types type)
{
	if (type == Types::Debris1)
	{
		debristexIds = "graphics/buildingbreak01.png";
	}
	else if (type == Types::Debris2)
	{
		debristexIds = "graphics/buildingbreak02.png";
	}
	else if (type == Types::Debris3)
	{
		debristexIds = "graphics/buildingbreak03.png";
	}
	else if (type == Types::Debris4)
	{
		debristexIds = "graphics/buildingbreak04.png";
	}
}
