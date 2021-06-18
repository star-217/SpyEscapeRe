#pragma once

#include "../../ESGLib.h"
#include "../Threatmap/Threatmap.h"

class DecoyBase
{
public:
	DecoyBase();
	virtual ~DecoyBase() {};

	void Initialize(Vector3 pos,float ratio,int count);
	void Update(ThreatMap);
	void Draw();
	void AIMap(ThreatMap);
	void Move();
	void Animetion();
	void FixDirection();
	Rect GetCollision() { return _collision; }

private:
	enum
	{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	FONT DefaultFont;

	SPRITE _decoy;

	Vector3 _decoy_pos;
	const Vector3 _move_direction[4];

	Rect _collision;
	int _speed;
	int _direction;
	int _old_pos_x[4];
	int _old_pos_y[4];
	int _stop_count;
	int _move_count;
	int _move_pattern;

	float _ratio;
	float _flame;
	float _animetion_flame;
	float _fix_positon_y;

	std::vector<float> _ai_data[18];

};