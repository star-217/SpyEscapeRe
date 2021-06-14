#pragma once

#include "../../ESGLib.h"
#include "Skill/SkillState.h"
#include "../Controller/Controller.h"
#include "../Base/Move.h"

class Spy
{
public:
	Spy() {}
	virtual ~Spy() {}

	void Initialize(const std::vector<cstring>, const Vector3);
	Vector3 Update();
	void Draw();
	//void Move();
	void Animetion();

private:

	CMove move;

	SPRITE spy;

	Vector3 spy_pos;
	std::vector<cstring> map_data;

	int direction;
	int pad_direction;
	int chara_size;
	int player_count;
	int player_speed;

	float animetion_flame;
	float animetion_flame_max;
	float invisible_alpha;
};