#pragma once

#include "../../ESGLib.h"
#include "../Threatmap/Threatmap.h"

class DecoyBase
{
public:
	DecoyBase();
	virtual ~DecoyBase() {};

	void Initialize(std::vector<cstring>&,Vector3 pos, float ratio, int count);
	void Update(ThreatMap&);
	void Draw();
	void AIMap(ThreatMap&);
	void Move();
	void Animetion();
	void FixDirection();
	Rect GetCollision() const { return _collision; }

private:
	enum class Direction
	{
		None,
		Down,
		Left,
		Right,
		Up,
		Max
	};

	FONT DefaultFont;

	SPRITE        _decoy;
	Vector3       _decoy_pos;
	const Vector3 _move_direction[4];	// 4ï˚å¸Ç‘ÇÒ

	Rect _collision;
	int  _speed;
	int  _direction;

	enum { PREV_MAX = 4 };	// ëkÇÈï‡êî
	int _old_pos_x[PREV_MAX];
	int _old_pos_y[PREV_MAX];

	int _stop_count;
	int _move_count;
	Direction _move_pattern;

	float _ratio;
	float _ratio2;
	float _flame;
	float _animetion_flame;
	float _fix_positon_y;

	enum { MAP_MAX_HEIGHT = 18 };
	std::vector<float> _ai_data[MAP_MAX_HEIGHT];
};