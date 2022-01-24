#pragma once

#include "../../ESGLib.h"
#include "../Threatmap/Threatmap.h"
#include "../Map/Map.h"
#include "../Base/HumanBase/HumanBase.h"

class Decoy : public HumanBase
{
public:
	Decoy();
	virtual ~Decoy() {};

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Move();
	void OnCollisionEnter(std::string tag) override {};

	void SetDecoyPos(Vector3 pos) { _decoy_pos = pos; }
	void SetWaitCount(int& wait_count) { _wait_count = wait_count; }
	void SetPriorityRatio(float& ratio) { _ratio = ratio; }


private:

	void FixDirection();
	void Animetion();

	enum class Direction
	{
		None,
		Down,
		Left,
		Right,
		Up,
		Max
	};
	ThreatMap _threatmap;

	const Vector2 CHARA_SIZE = Vector2(50, 70);
	const int  SPEED = 5;
	const Vector3 _move_direction[4] =
	{
		 Vector3_Down,
		 Vector3_Up,
		 Vector3_Right,
		 Vector3_Left
	};	// 4ï˚å¸Ç‘ÇÒ

	SPRITE        _decoy;
	Vector3       _decoy_pos;

	Direction _move_pattern;

	Rect _collision;
	int  _direction;

	int _wait_count;
	int _move_count;

	float _ratio;

	float _flame;
	float _animetion_flame;
	float _fix_positon_y;

	enum { PREV_MAX = 4 };	// ëkÇÈï‡êî
	int _old_pos_x[PREV_MAX];
	int _old_pos_y[PREV_MAX];

	std::vector<float>* _threat_data;

	FONT DefaultFont;
};