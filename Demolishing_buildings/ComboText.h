#pragma once
#include "TextGo.h"
class ComboText : public TextGo
{
protected:
	int combo = 0;
public:
	ComboText(const std::string& fontIds = "", const std::string& name = "");
	~ComboText() override = default;

	void Init() override;
	void Reset() override;
	void SetCombo(int combo);
};

