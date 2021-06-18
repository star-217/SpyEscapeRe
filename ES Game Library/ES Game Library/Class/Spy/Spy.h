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
	Rect GetCollision() { return _collision; }
	void Animetion();
	void WinAnimetion();
	void LoseAnimetion();
	void AttackHit();

private:

	CMove _move;
	SkillState _skill;

	SPRITE _spy;
	SPRITE _attack;
	SPRITE _win;
	SPRITE _lose;

	Vector3 _spy_pos;
	Vector3 _draw_spy_pos;

	Rect _collision;


	std::vector<cstring> _map_data;

	enum
	{
		DEFAULT,
		WIN,
		LOSE
	};

	int _state;
	int _direction;
	int _chara_size_width;
	int _chara_size_height;
	int _fix_pos_y;
	int _player_count;
	int _speed;

	float _animetion_flame;
	float _animetion_flame_max;
	float _win_flame;
	float _lose_flame;
	float _invisible_alpha;


};