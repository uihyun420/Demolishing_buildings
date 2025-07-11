#include "stdafx.h"
#include "SceneGame.h"
#include "Player.h"


SceneGame::SceneGame()
	:Scene(SceneIds::Game)
{
}

void SceneGame::Init()
{
	texIds.push_back("graphics/bg.png");
	texIds.push_back("graphics/stand.png");
	player = new Player("Player");
	AddGameObject(player);

	Scene::Init();
}
void SceneGame::Enter()
{
	auto size = FRAMEWORK.GetWindowSizeF();
	sf::Vector2f center{ size.x * 0.5f, size.y * 0.5f };
	uiView.setSize(size);
	uiView.setCenter(center);
	worldView.setSize(size);
	worldView.setCenter(player->GetPosition());

	Scene::Enter();
}

void SceneGame::Exit()
{
	Scene::Exit();
}


void SceneGame::Update(float dt)
{
}
void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}