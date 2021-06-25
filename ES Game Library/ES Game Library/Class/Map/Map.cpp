#include "Map.h"

Map::Map() : _bg(nullptr),_wallhide(nullptr)
{
}

void Map::Initialize(std::vector<cstring>& data)
{

	_bg = GraphicsDevice.CreateSpriteFromFile(_T("deza.png"));
	_wallhide = GraphicsDevice.CreateSpriteFromFile(_T("ton.png"));
	_color = Color(255, 255, 255);


	int _map_data_size = 18;
	_map_data.resize(_map_data_size);
	//マップデータ
	_map_data[0]  = ("################################");
	_map_data[1]  = ("#             $$               #");
	_map_data[2]  = ("#   $%$   $$      $$   $$  $$  #");
	_map_data[3]  = ("#  $$%$$          $$           #");
	_map_data[4]  = ("#  %%%%%                       #");
	_map_data[5]  = ("#  $$%$$  $  $%%$    $   $$$$  #");
	_map_data[6]  = ("#   $%$      $%%$              #");
	_map_data[7]  = ("#          $$$%%$$$            #");
	_map_data[8]  = ("#       $  %%%%%%%%      $$$$  #");
	_map_data[9]  = ("#   $$  $  %%%%%%%%   $        #");
	_map_data[10] = ("#   $$     $$$%%$$$   $        #");
	_map_data[11] = ("#            $%%$        $%$   #");
	_map_data[12] = ("#     $$     $%%$       $$%$$  #");
	_map_data[13] = ("#                   $$  %%%%%  #");
	_map_data[14] = ("#   $$  $$              $$%$$  #");
	_map_data[15] = ("#   $$  $$          $$   $%$   #");
	_map_data[16] = ("#              $$              #");
	_map_data[17] = ("################################");

	data = _map_data;

	int i = 0;

}

void Map::Update()
{
}

void Map::Draw()
{

	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < 32; x++) {
			if (_map_data[y][x] == '#')
			{
				SpriteBatch.Draw(*_bg, Vector3(x * 50, y * 50, 0), RectWH(0, 150, 50, 50), _color);
			}
			else if (_map_data[y][x] == '$')
			{
				SpriteBatch.Draw(*_bg, Vector3(x * 50, y * 50, 0), RectWH(100, 700, 50, 50), _color);
			}
			else if (_map_data[y][x] == '%')
			{
				SpriteBatch.Draw(*_wallhide, Vector3(x * 50, y * 50, -1), RectWH(0, 0, 50, 50), _color);
			}
			else {

				SpriteBatch.Draw(*_bg, Vector3(x * 50, y * 50, 0), RectWH(0, 50, 50, 50), _color);
			}
		}
	}
}
