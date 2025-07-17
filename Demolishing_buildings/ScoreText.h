#pragma once
#include "TextGo.h"
class Player;
class ScoreText : public TextGo
{
protected:
	int score = 0;
	Player* player;
public:
	ScoreText(const std::string& fontIds = "", const std::string& name = "");
	~ScoreText() = default;

	void Init() override;
	void Reset() override;
	void SetScore(int score);

};

