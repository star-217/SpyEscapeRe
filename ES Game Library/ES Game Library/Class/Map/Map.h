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

	std::vector<cstring> map_data;
	SPRITE bg;
	SPRITE wallhide;
	Color cl;
};