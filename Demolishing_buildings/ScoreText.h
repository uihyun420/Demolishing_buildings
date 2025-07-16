#pragma once
#include "TextGo.h"
class ScoreText : public TextGo
{
protected:
	int score = 0;

public:
	ScoreText(const std::string& fontIds = "", const std::string& name = "");
	~ScoreText() = default;

	void Init() override;
	void Reset() override;
	void SetScore(int score);
};

