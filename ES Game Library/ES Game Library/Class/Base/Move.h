/**
 * @file  Move.h
 * @brief Move.cppのヘッダーファイル
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../ESGLib.h"
#include "../Controller/Controller.h"
#include "ConstantList.h"

class Move
{
public:

	Move() = default;
	virtual ~Move() {}

	void      Initialize();
	Vector3   MovePostion(Vector3 pos, std::vector<cstring>& map_data, float speed,int pad_number);
	Direction GetDirection() const { return _direction; }

private:

	Direction _pad_direction;
	int       _count;
	Direction _direction;

	const int MAXBLOCKCOUNT = 50;
};