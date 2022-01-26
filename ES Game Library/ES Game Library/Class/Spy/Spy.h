#pragma once

#include "../../ESGLib.h"
#include "Skill/SkillState.h"
#include "../Base/Move/Move.h"
#include "../Map/Map.h"
#include "../Base/HumanBase/HumanBase.h"
#include "../Base/CheckMove/CheckMove.h"

class Spy : public HumanBase
{
public:
	Spy() {};
	virtual ~Spy() {}

	void SetStartPos(Vector3& pos) { _pos = pos; }
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void OnCollisionEnter(std::string tag) override;
	void DoMove(HumanBase* human) override {};

	void SetCheckMoveClass(CheckMove* check_move) { _check_move = check_move; }

private:

	void Animetion();
	void WinAnimetion();
	void LoseAnimetion();

	Move* _move;
	CheckMove* _check_move;

	SkillState _skill;

	SPRITE _spy;
	SPRITE _win;
	SPRITE _lose;

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

	Vector3 _old_pos;
};