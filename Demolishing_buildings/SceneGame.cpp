#include "stdafx.h"
#include "SceneGame.h"
#include "Player.h"
#include "BackGround.h"
#include "AniPlayer.h"
#include "Building.h"
#include "Ground.h"
#include "Sky.h"


SceneGame::SceneGame()
	:Scene(SceneIds::Game)
{
}

void SceneGame::Init()
{
	texIds.push_back("graphics/bg.png");
	texIds.push_back("graphics/ground.png");
	texIds.push_back("graphics/sky.png");
	texIds.push_back("graphics/stand.png");
	texIds.push_back("graphics/jump.png");
	texIds.push_back("graphics/building.png");
	
	player = new Player("Player");
	background = new BackGround("background");
	building = new Building("building"); 
	ground = new Ground("ground");
	sky = new Sky("sky");
	
	player->SetBuilding(building); // 플레이어와 빌딩 연결해야 충돌검사 등 진행

	AddGameObject(player);
	AddGameObject(background);
	AddGameObject(building); 
	AddGameObject(ground);
	AddGameObject(sky);

	Scene::Init();
}
void SceneGame::Enter()
{
	auto size = FRAMEWORK.GetWindowSizeF(); // 창 크기 가져오기
	sf::Vector2f center{ size.x * 0.5f, size.y * 0.5f }; // 중앙 위치 계산

	// 뷰 설정
	uiView.setSize(size);
	uiView.setCenter(center);
	worldView.setSize(size);
	worldView.setCenter(player->GetPosition().x, player ->GetPosition().y);

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
	worldView.setCenter(player->GetPosition().x, player->GetPosition().y); // 플레이어 위치에 따라 뷰 이동
	
	//if (player->PlayerJump())
	//{
	//	worldView.setCenter(player->GetPosition().x, player->GetPosition().y);
	//}
	//else
	//{
	//	worldView.setCenter(0.f, 0.f); 	
	//}
	Scene::Update(dt);
}
void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}