/**
 * @file  Move.h
 * @brief コントローラの移動プログラム
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../../ESGLib.h"
#include "../../Map/Map.h"
#include "../../Base/ConstantList.h"


class Move
{
public:
	Move();
	virtual ~Move() {}

	void      Initialize();
	Vector3   MovePostion(Vector3 pos, float speed,int pad_number);

	Direction GetDirection() const { return _direction; }
	void SetMapData(std::vector<cstring>& map_data) { _map_data = map_data; }
	bool GetMoveCmp() { return _flag; }
	GamePadState GetPad() { return _pad; }

private:
	void PadDirection(Vector3 pos, int pad_number);

	GamePadState _pad;

	Direction _pad_direction;
	Direction _direction;

	int       _count;

	bool _flag;

	std::vector<cstring> _map_data;
};