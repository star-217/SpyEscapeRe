#pragma once

#include "../../ESGLib.h"
#include "Skill/SkillState.h"
#include "../Base/Move/Move.h"
#include "../Base/GameState.h"
#include "../Map/Map.h"
#include "../Base/HumanBase/HumanBase.h"

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

private:

	void Animetion();
	void WinAnimetion();
	void LoseAnimetion();

	Move _move;
	SkillState _skill;

	SPRITE _spy;
	SPRITE _win;
	SPRITE _lose;

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