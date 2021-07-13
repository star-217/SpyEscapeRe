#include <fstream>

#include "Map.h"

Map::Map() : _bg(nullptr), _wallhide(nullptr)
{
}

std::vector<cstring> Map::Initialize()
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

	return _map_data;
}

void Map::Update()
{
}

void Map::Draw()
{
	for (int y = 0; y < _map_data.size(); ++y) {
		for (int x = 0; x < _map_data[y].size(); ++x) {
			switch (_map_data[y][x]) {
			case '#':
				SpriteBatch.Draw(*_bg,		 Vector3(x * 50, y * 50,  0), RectWH(  0, 150, 50, 50), _color);
				break;
			case '$':
				SpriteBatch.Draw(*_bg,		 Vector3(x * 50, y * 50,  0), RectWH(100, 700, 50, 50), _color);
				break;
			case '%':
				SpriteBatch.Draw(*_wallhide, Vector3(x * 50, y * 50, -1), RectWH(  0,   0, 50, 50), _color);
				break;
			default:
				SpriteBatch.Draw(*_bg,		 Vector3(x * 50, y * 50,  0), RectWH(  0,  50, 50, 50), _color);
				break;
			}
		}
	}
}
