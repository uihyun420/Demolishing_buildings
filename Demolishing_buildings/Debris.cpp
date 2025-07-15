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
	for (int i = 0; i < 4; ++i)
	{
		debris[i].setTexture(TEXTURE_MGR.Get(debiristexIds));
	}
}

void Debris::Update(float dt)
{
}

void Debris::Draw(sf::RenderWindow& window)
{
}