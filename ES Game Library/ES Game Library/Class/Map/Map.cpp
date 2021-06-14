#include "Map.h"

Map::Map() : bg(nullptr),wallhide(nullptr)
{
}

void Map::Initialize(std::vector<cstring>& data)
{

	bg = GraphicsDevice.CreateSpriteFromFile(_T("deza.png"));
	wallhide = GraphicsDevice.CreateSpriteFromFile(_T("ton.png"));
	cl = Color(255, 255, 255);


	int _map_data_size = 18;
	map_data.resize(_map_data_size);
	//マップデータ
	map_data[0]  = ("################################");
	map_data[1]  = ("#             $$               #");
	map_data[2]  = ("#   $%$   $$      $$   $$  $$  #");
	map_data[3]  = ("#  $$%$$          $$           #");
	map_data[4]  = ("#  %%%%%                       #");
	map_data[5]  = ("#  $$%$$  $  $%%$    $   $$$$  #");
	map_data[6]  = ("#   $%$      $%%$              #");
	map_data[7]  = ("#          $$$%%$$$            #");
	map_data[8]  = ("#       $  %%%%%%%%      $$$$  #");
	map_data[9]  = ("#   $$  $  %%%%%%%%   $        #");
	map_data[10] = ("#   $$     $$$%%$$$   $        #");
	map_data[11] = ("#            $%%$        $%$   #");
	map_data[12] = ("#     $$     $%%$       $$%$$  #");
	map_data[13] = ("#                   $$  %%%%%  #");
	map_data[14] = ("#   $$  $$              $$%$$  #");
	map_data[15] = ("#   $$  $$          $$   $%$   #");
	map_data[16] = ("#              $$              #");
	map_data[17] = ("################################");

	data = map_data;

	int i = 0;

}

void Map::Update()
{
}

void Map::Draw()
{

	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < 32; x++) {
			if (map_data[y][x] == '#')
			{
				SpriteBatch.Draw(*bg, Vector3(x * 50, y * 50, 0), RectWH(0, 150, 50, 50), cl);
			}
			else if (map_data[y][x] == '$')
			{
				SpriteBatch.Draw(*bg, Vector3(x * 50, y * 50, 0), RectWH(100, 700, 50, 50), cl);
			}
			else if (map_data[y][x] == '%')
			{
				SpriteBatch.Draw(*wallhide, Vector3(x * 50, y * 50, -1), RectWH(0, 0, 50, 50), cl);
			}
			else {

				SpriteBatch.Draw(*bg, Vector3(x * 50, y * 50, 0), RectWH(0, 50, 50, 50), cl);
			}
		}
	}
}
