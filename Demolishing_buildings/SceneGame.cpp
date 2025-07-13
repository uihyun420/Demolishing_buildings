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
	fontIds.push_back("fonts/zombiecontrol.ttf");	


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
	//	// 착지 순간: 뷰를 초기 위치(예: 맵 중앙)로 복귀
	//	worldView.setCenter(0.f, 0.f); 	
	//}
	Scene::Update(dt);
}
void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}