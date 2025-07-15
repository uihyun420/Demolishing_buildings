#include "stdafx.h"
#include "Debris.h"
 


	Debris::Debris(const std::string & name)
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
	}

	void Debris::Update(float dt)
	{
		for (size_t i = 0; i < debris.size(); ++i)
		{
			velocity[i] += gravity * dt;
			debris[i].move(velocity[i] * dt);
		}
	}

	void Debris::Draw(sf::RenderWindow & window)
	{
		for (const auto& d : debris)
		{
			window.draw(d);
		}
	}

	void Debris::SpawnDebris(const sf::Vector2f& pos, int count)
	{
		debris.clear();
		velocity.clear();

		float space = 50.f;
		float startX = pos.x - (space * (count - 1) / 2.f);

		for (int i = 0; i < count; ++i)
		{
			sf::Sprite d;
			int texIdx = i % debrisTexIdsList.size();
			d.setTexture(TEXTURE_MGR.Get(debrisTexIdsList[texIdx]), true);
			d.setPosition(startX + i * space, pos.y);
			debris.push_back(d);

			float vx = (i - (count - 1) / 2.f) * 100.f; // -150, -50, 50, 150 µî
			velocity.push_back({ vx, 0.f });
			//velocity.push_back({ 0.f, 0.f });
		}
	}
