#pragma once

#include "../../ESGLib.h"
#include "Skill/SkillState.h"
#include "../Controller/Controller.h"
#include "../Base/Move.h"
#include "../Base/GameState.h"

class Spy
{
public:
	Spy() {}
	virtual ~Spy() {}

	void Initialize(const std::vector<cstring>, const Vector3);
	Vector3 Update();
	void Draw();
	Rect GetCollision(){return }
	void Animetion();
	void WinAnimetion();
	void LoseAnimetion();

private:

	CMove move;
	SkillState skill;

	SPRITE spy;
	SPRITE attack;
	SPRITE win;
	SPRITE lose;

	Vector3 spy_pos;
	Vector3 draw_spy_pos;

	Rect collision;


	std::vector<cstring> map_data;

	enum State
	{
		DEFAULT,
		WIN,
		LOSE
	};

	int state;
	int direction;
	int pad_direction;
	int chara_size;
	int player_count;
	int player_speed;

	float animetion_flame;
	float animetion_flame_max;
	float win_flame;
	float lose_flame;
	float invisible_alpha;


};