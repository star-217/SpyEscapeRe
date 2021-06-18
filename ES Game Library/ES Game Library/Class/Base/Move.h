#pragma once

#include "../../ESGLib.h"
#include "../Controller/Controller.h"

class Move
{
public:
	void Initialize();
	Vector3 MovePostion(Vector3 pos, std::vector<cstring> map_data, float speed,int pad_number);
	//Vector3 GetPosition() { return position; }
	int GetDirection() { return _direction; }

private:

	GamePadState _pad;

	Vector3 _position;

	int _block_size;
	int _pad_direction;
	int _count;
	int _direction;

};