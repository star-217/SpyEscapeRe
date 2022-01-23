#include <fstream>

#include "Map.h"

Map::Map() : _bg(nullptr), _wallhide(nullptr)
{
}

void Map::Initialize()
{
	_bg       = GraphicsDevice.CreateSpriteFromFile(_T("deza.png"));
	_wallhide = GraphicsDevice.CreateSpriteFromFile(_T("ton.png"));
	_color    = Color(255, 255, 255);

	std::ifstream file("map.txt");

	cstring line_buffer;
	while (true) {
		if (file.eof())
			break;

		std::getline(file, line_buffer);
		_map_data.push_back(line_buffer);
	}

}

void Map::Draw()
{

	for (int y = 0; y < _map_data.size(); ++y) {
		for (int x = 0; x < _map_data[y].size(); ++x) {
			Vector3 bg_pos = Vector3(x * BLOCK_SIZE, y * BLOCK_SIZE, 0);
			Vector3 hide_bg_pos = Vector3(x * BLOCK_SIZE, y * BLOCK_SIZE, -1);

			switch (_map_data[y][x]) {
			case '#':
				SpriteBatch.Draw(*_bg, bg_pos, WALL_RECT, _color);
				break;
			case '$':
				SpriteBatch.Draw(*_bg, bg_pos, DEST_RECT, _color);
				break;
			case '%':
				SpriteBatch.Draw(*_wallhide, hide_bg_pos, HIDE_BLOCK_RECT, _color);
				break;
			default:
				SpriteBatch.Draw(*_bg, bg_pos, FLOOR_RECT, _color);
				break;
			}
		}
	}
}
