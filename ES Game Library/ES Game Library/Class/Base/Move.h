#pragma once

#include "../../ESGLib.h"
#include "../Controller/Controller.h"

class CMove
{
public:
	void Initialize();
	virtual Vector3 Move(Vector3 pos, std::vector<cstring> map_data, float speed,int pad_number);
	//Vector3 GetPosition() { return position; }
	int GetDirection() { return direction; }

private:

	Vector3 position;

	int block_size;
	int pad_direction;
	int count;
	int direction;


	GamePadState pad;
};