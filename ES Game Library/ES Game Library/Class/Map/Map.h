#pragma once

#include "../../ESGLib.h"

class Map
{
public:
	Map();
	virtual ~Map() {}

	void Initialize(std::vector<cstring>&);
	void Update();
	void Draw();

private:

	std::vector<cstring> _map_data;
	SPRITE _bg;
	SPRITE _wallhide;
	Color _color;
};