#pragma once

#include "../../ESGLib.h"
#include "../Controller/Controller.h"

class Move
{
public:
	enum class Direction
	{
		None,
		Down,
		Left,
		Right,
		Up,
		Max
	};

	Move() = default;
	virtual ~Move() {}

	void      Initialize();
	Vector3   MovePostion(Vector3 pos, std::vector<cstring>& map_data, float speed,int pad_number);
	Direction GetDirection() const { return _direction; }

private:
	enum class Direction
	{
		None,
		Down,
		Left,
		Right,
		Up
	};

	int       _block_size;
	Direction _pad_direction;
	int       _count;
	Direction _direction;
};