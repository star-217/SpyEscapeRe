#pragma once

#include "../../ESGLib.h"
#include "../Threatmap/Threatmap.h"
#include "../Map/Map.h"

class DecoyBase
{
public:
	DecoyBase();
	virtual ~DecoyBase() {};

	void Initialize(Vector3 pos);
	void Update(ThreatMap&);
	void Draw();
	void Move();

	void SetWaitCount(int& wait_count) { _wait_count = wait_count; }
	void SetPriorityRatio(float& ratio)
	{
		_ratio = ratio;
		_ratio2 = 1.0f - _ratio;
	}

	Rect GetCollision() const { return _collision; }

private:

	void FixDirection();
	void Animetion();
	void AIMap(ThreatMap&);

	enum class Direction
	{
		None,
		Down,
		Left,
		Right,
		Up,
		Max
	};

	const Vector2 CHARA_SIZE = Vector2(50, 70);
	const int  SPEED = 5;
	const Vector3 _move_direction[4] =
	{
		 Vector3_Down,
		 Vector3_Up,
		 Vector3_Right,
		 Vector3_Left
	};	// 4ï˚å¸Ç‘ÇÒ

	FONT DefaultFont;

	SPRITE        _decoy;
	Vector3       _decoy_pos;

	Direction _move_pattern;

	Rect _collision;
	int  _direction;

	enum { PREV_MAX = 4 };	// ëkÇÈï‡êî
	int _old_pos_x[PREV_MAX];
	int _old_pos_y[PREV_MAX];

	int _wait_count;
	int _move_count;

	float _ratio;
	float _ratio2;
	float _flame;
	float _animetion_flame;
	float _fix_positon_y;

	enum { MAP_MAX_HEIGHT = 18 };
	std::vector<float> _ai_data[MAP_MAX_HEIGHT];
};