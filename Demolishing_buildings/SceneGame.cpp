#include "stdafx.h"
#include "SceneGame.h"
#include "Player.h"
#include "BackGround.h"
#include "AniPlayer.h"
#include "Building.h"


SceneGame::SceneGame()
	:Scene(SceneIds::Game)
{
}

void SceneGame::Init()
{
	texIds.push_back("graphics/bg.png");
	texIds.push_back("graphics/stand.png");
	texIds.push_back("graphics/jump.png");
	texIds.push_back("graphics/building.png");


	player = new Player("Player");
	background = new BackGround("background");
	building = new Building("building"); 
	

	AddGameObject(player);
	AddGameObject(background);
	AddGameObject(building); 
	

	Scene::Init();
}
void SceneGame::Enter()
{
	auto size = FRAMEWORK.GetWindowSizeF(); // â ũ�� ��������
	sf::Vector2f center{ size.x * 0.5f, size.y * 0.5f }; // �߾� ��ġ ���

	// �� ����
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
	player->Update(dt);
	background->Update(dt); 
	building->Update(dt);

	Scene::Update(dt);
}
void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}