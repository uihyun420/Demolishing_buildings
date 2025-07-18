#include "stdafx.h"
#include "SceneTitle.h"
#include "TitleBackGround.h"
#include "MenuUi.h"
#include "TextGo.h"

SceneTitle::SceneTitle()
	:Scene(SceneIds::Title)
{
}


void SceneTitle::Init()
{	
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	fontIds.push_back("fonts/Galmuri11-Bold.ttf");

	texIds.push_back("graphics/title.png");
	texIds.push_back("graphics/choosebar.png");


	titlebackground = new TitleBackGround("titlebackground");
	chooseBar = new MenuUi("chooseBar");


	AddGameObject(titlebackground);
	AddGameObject(chooseBar);


	TextGo* selectText_01 = new TextGo("fonts/Galmuri11-Bold.ttf");
	selectText_01->SetString("EASY");
	selectText_01->SetCharacterSize(60);
	selectText_01->SetFillColor(sf::Color::White);
	selectText_01->SetOrigin(Origins::MC);
	selectText_01->SetPosition({ bounds.width / 2.f, bounds.height / 2.f - 100.f });
	AddGameObject(selectText_01);


	TextGo* selectText_02 = new TextGo("fonts/Galmuri11-Bold.ttf");
	selectText_02->SetString("HARD");
	selectText_02->SetCharacterSize(60);
	selectText_02->SetFillColor(sf::Color::White);
	selectText_02->SetOrigin(Origins::MC);
	selectText_02->SetPosition({ bounds.width / 2.f, bounds.height / 2.f + 100.f});
	AddGameObject(selectText_02);



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
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	//if(InputMgr::GetKeyDown(sf::Keyboard::Enter))
	//{
	//	SCENE_MGR.ChangeScene(SceneIds::Game);
	//}

	Scene::Update(dt);
}

void SceneTitle::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}