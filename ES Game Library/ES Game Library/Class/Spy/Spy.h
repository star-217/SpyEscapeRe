#pragma once

#include "../../ESGLib.h"
#include "Skill/SkillState.h"
#include "../Controller/Controller.h"
#include "../Base/Move.h"
#include "../Base/GameState.h"
#include "../Map/Map.h"

class Spy
{
public:
	Spy();
	virtual ~Spy() {}

	void Initialize(const std::vector<cstring>&, const Vector3);
	void Update();
	void Draw();
	Rect GetCollision() { return _collision; }
	Vector3 GetPostiion() { return _spy_pos; }
	void AttackHit();

private:

	void Animetion();
	void WinAnimetion();
	void LoseAnimetion();

	Move _move;
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

	const int _chara_size_width = 50.0f;
	const int _chara_size_height = 70.0f;
	const int _fix_pos_y  = 20.0f;
	const int _speed = 5.0f;

	int _state;
	int _direction;
	int _player_count;

	float _animetion_flame;
	float _win_flame;
	float _lose_flame;
	float _invisible_alpha;
};