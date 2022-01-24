/**
 * @file  DecoyBase.h
 * @brief DecoyBase.cppのヘッダーファイル
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../ESGLib.h"
#include "../Threatmap/Threatmap.h"
#include "../Base/ConstantList.h"

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

	Direction _move_pattern;

	SPRITE        _decoy;
	Vector3       _decoy_pos;
	const Vector3 _move_direction[4];	// 4方向ぶん
	Rect _collision;

	int  _speed;
	int  _direction;
	int _old_pos_x[PREV_MAX];
	int _old_pos_y[PREV_MAX];
	int _move_count;

	float _ratio;
	float _ratio2;
	float _flame;
	float _animetion_flame;
	float _fix_positon_y;

	std::vector<float> _ai_data[MAP_MAX_HEIGHT];
};