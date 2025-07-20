#include "stdafx.h"
#include "SceneGame.h"
#include "Player.h"
#include "BackGround.h"
#include "AniPlayer.h"
#include "Building.h"
#include "Ground.h"
#include "Sky.h"
#include "Debris.h"
#include "StaminaBar.h"
#include "ScoreText.h"
#include "ComboText.h"
#include "SpecialAttack.h"

SceneGame::SceneGame()
	:Scene(SceneIds::Game)
{
}

void SceneGame::Init()
{
	fontIds.push_back("fonts/Galmuri11-Bold.ttf");

	texIds.push_back("graphics/bg.png");
	texIds.push_back("graphics/ground.png");
	texIds.push_back("graphics/sky.png");
	texIds.push_back("graphics/stand.png");
	texIds.push_back("graphics/jump.png");
	texIds.push_back("graphics/building.png");
	texIds.push_back("graphics/standattack.png");
	texIds.push_back("graphics/jumpattack.png");
	texIds.push_back("graphics/standguard.png");
	texIds.push_back("graphics/buildingbreak01.png");
	texIds.push_back("graphics/buildingbreak02.png");
	texIds.push_back("graphics/buildingbreak03.png");
	texIds.push_back("graphics/buildingbreak04.png");
	texIds.push_back("graphics/specialattack.png");
	
	player = new Player("Player");
	background = new BackGround("background");
	building = new Building("building"); 
	ground = new Ground("ground");
	sky = new Sky("sky");
	debris = new Debris("debris");
	staminabar = new StaminaBar("staminabar");
	scoreText = new ScoreText("scoreText");
	comboText = new ComboText("comboText");
	specialAttack = new SpecialAttack("specialAttack");

	
	building->SetPlayer(player);
	building->SetDebris(debris);
	scoreText->SetScore(0);
	specialAttack->SetPlayer(player);
	player->SetBuilding(building); // 플레이어와 빌딩 연결해야 충돌검사 등 진행
	player->SetScoreCombo(comboText);
	player->SetStaminaBarGage(staminabar); // 이거 반대로 했었음 플레이어가 스테미너바의 스테미너 게이지에 이어지도록
	player->SetScoreText(scoreText);
	player->SetSpecialAttack(specialAttack);

	AddGameObject(player);
	AddGameObject(background);
	AddGameObject(building); 
	AddGameObject(ground);
	AddGameObject(sky);
	AddGameObject(debris);
	AddGameObject(scoreText);
	AddGameObject(staminabar);
	AddGameObject(comboText);
	AddGameObject(specialAttack);

	Scene::Init();
}
void SceneGame::Enter()
{
	auto size = FRAMEWORK.GetWindowSizeF(); // 창 크기 가져오기
	sf::Vector2f center{ size.x * 0.5f, size.y * 0.5f }; // 중앙 위치 계산

	 //뷰 설정
	uiView.setSize(size);
	uiView.setCenter(center);

	worldView.setSize(size);
	worldView.setCenter(player->GetPosition().x, player ->GetPosition().y);

	//uiView.setSize({ FRAMEWORK.GetWindowSizeF().x, FRAMEWORK.GetWindowSizeF().y });
	//uiView.setCenter({ FRAMEWORK.GetWindowSizeF().x / 2, FRAMEWORK.GetWindowSizeF().y / 2 });

	Scene::Enter();
}

void SceneGame::Exit()
{
	Scene::Exit();
}

void SceneGame::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		isPaused = !isPaused; 
	}
	if (isPaused)
	{
		return;
	}

	worldView.setCenter(player->GetPosition().x, player->GetPosition().y); // 플레이어 위치에 따라 뷰 이동

	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		SCENE_MGR.ChangeScene(SceneIds::Game);
	}
	Scene::Update(dt);
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);	
	if (isPaused)
	{
		sf::Text pausedText;
		pausedText.setFont(FONT_MGR.Get("fonts/Galmuri11-Bold.ttf"));
		pausedText.setString("PAUSED");
		pausedText.setCharacterSize(80);
		pausedText.setFillColor(sf::Color::Black);
		pausedText.setPosition(475, 300); 
		window.draw(pausedText);
	}
}
