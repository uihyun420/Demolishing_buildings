#pragma once
#include "GameObject.h"
class Debris : public GameObject
{
protected:
	std::list<sf::Sprite*> debris;
	std::string debristexIds;

public:
	Debris(const std::string& name = "");
	virtual ~Debris() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float rot) override;
	void SetScale(const sf::Vector2f& s) override;
	void SetOrigin(const sf::Vector2f& o) override;
	void SetOrigin(Origins preset) override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

// 건물 잔해들을 리스트 or 배열에 담고 
// 포지션을 각각 준다음 building SetActive = false 일때 그 자리에 랜덤으로 생성되어 중력 적용 해서 떨어지도록 하기 