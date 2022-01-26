/**
 * @file  Move.h
 * @brief Move.cppのヘッダーファイル
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../../ESGLib.h"
#include "../../Map/Map.h"


class Move
{
public:
	Move() {};
	virtual ~Move() {}

	enum class Direction //キャラが進む方向
	{
		None,
		Down,
		Left,
		Right,
		Up
	};

	void      Initialize();
	Vector3   MovePostion(Vector3 pos, float speed,int pad_number);
	Direction GetDirection() const { return _direction; }

	void SetMapData(std::vector<cstring>& map_data) { _map_data = map_data; }
	bool GetMoveCmp() { return _flag; }

private:
	const int MAXBLOCKCOUNT = 50;
	const int BLOCK_SIZE = 50;

	Direction _pad_direction;
	Direction _direction;

	int       _count;

	bool _flag;

	std::vector<cstring> _map_data;
};