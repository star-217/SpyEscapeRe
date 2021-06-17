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
	Rect GetCollision() { return collision; }

private:
	enum MOVEPATTERN
	{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	FONT DefaultFont;

	SPRITE decoy;

	Vector3 decoy_pos;
	const Vector3 move_direction[4]{Vector3_Up, Vector3_Down,Vector3_Right,Vector3_Left};

	Rect collision;
	int speed;
	int direction;
	int old_pos_x[4];
	int old_pos_y[4];
	int stop_count;
	int move_count;
	int move_pattern;

	float _ratio;
	float flame;
	float animetion_flame;
	float fix_positon_y;

	std::vector<float> ai_data[18];

};