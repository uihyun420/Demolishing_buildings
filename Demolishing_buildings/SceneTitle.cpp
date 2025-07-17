#include "stdafx.h"
#include "SceneTitle.h"
#include "TitleBackGround.h"
#include "MenuUi.h"

SceneTitle::SceneTitle()
	:Scene(SceneIds::Title)
{
}


void SceneTitle::Init()
{	
	texIds.push_back("graphics/title.png");
	texIds.push_back("graphics/choosebar.png");


	titlebackground = new TitleBackGround("titlebackground");
	chooseBar = new MenuUi("chooseBar");

	AddGameObject(titlebackground);
	AddGameObject(chooseBar);

	Scene::Init();
}

void SceneTitle::Enter()
{
	auto size = FRAMEWORK.GetWindowSizeF(); // 창 크기 가져오기
	sf::Vector2f center{ size.x * 0.5f, size.y * 0.5f }; // 중앙 위치 계산

	//뷰 설정
	uiView.setSize(size);
	uiView.setCenter(center);

	worldView.setSize(size);
	worldView.setCenter(center);

	Scene::Enter();
}

void SceneTitle::Exit()
{
	Scene::Exit();
}

void SceneTitle::Update(float dt)
{
	if(InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		SCENE_MGR.ChangeScene(SceneIds::Game);
	}
	Scene::Update(dt);
}

void SceneTitle::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}