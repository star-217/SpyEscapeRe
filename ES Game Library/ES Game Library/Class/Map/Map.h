/**
 * @file  Map.h
 * @brief Map.cppのヘッダーファイル
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../ESGLib.h"

class Map
{
public:
	Map();
	virtual ~Map() {}

	std::vector<cstring> Initialize();
	void Update();
	void Draw();

private:
	std::vector<cstring> _map_data;
	SPRITE               _bg;
	SPRITE               _wallhide;
	Color                _color;
};