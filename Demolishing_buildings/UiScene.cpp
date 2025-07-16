#include "stdafx.h"
#include "UiScene.h"
#include "ScoreText.h"
#include "Player.h"

UiScene::UiScene()
	:Scene(SceneIds::Ui)
{
}

void UiScene::Init()
{
	fontIds.push_back("fonts/Galmuri11-Bold.ttf");

	scoreText = new ScoreText;
	AddGameObject(scoreText);

	worldView.setCenter(0.f, 0.f);
	worldView.setSize({ FRAMEWORK.GetWindowSizeF().x, FRAMEWORK.GetWindowSizeF().y });

	uiView.setSize({ FRAMEWORK.GetWindowSizeF().x, FRAMEWORK.GetWindowSizeF().y });
	uiView.setCenter({ FRAMEWORK.GetWindowSizeF().x , FRAMEWORK.GetWindowSizeF().y});

	scoreText->SetScore(0);

	Scene::Init();
}
void UiScene::Enter()
{
	Scene::Enter();
}
void UiScene::Update(float dt)
{
	scoreText->Update(dt);
	Scene::Update(dt);
}
void UiScene::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}