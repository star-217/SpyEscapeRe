/**
 * @file  Map.h
 * @brief Map.cpp�̃w�b�_�[�t�@�C��
 * @author ������
 * @date 2021/04/20
 */
#pragma once

#include "../../ESGLib.h"

class Map
{
public:
	virtual ~Map() {}

	void Initialize();
	void Draw();
	std::vector<cstring>& GetMapData() { return _map_data; }

	static Map& GetInstance()
	{
		static Map map;
		return map;
	}

private:
	Map();

	std::vector<cstring> _map_data;

	SPRITE               _bg;
	SPRITE               _wallhide;
	Color                _color;

	const int BLOCK_SIZE = 50;

	const RectWH FLOOR_RECT = RectWH(0, 50, 50, 50);
	const RectWH WALL_RECT = RectWH(0, 150, 50, 50);
	const RectWH DEST_RECT = RectWH(100, 700, 50, 50);
	const RectWH HIDE_BLOCK_RECT = RectWH(0, 0, 50, 50);
};