#include "Threatmap.h"

void ThreatMap::Initialize(const std::vector<cstring> data)
{
	DefaultFont = GraphicsDevice.CreateDefaultFont();
	map_data = data;
	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < map_data[y].size(); x++) {
			threat_data_tracker[y].push_back(0);
			threat_data_spy[y].push_back(0);
		}
	}
	prev_mx = 0;
	prev_my = 0;

}

void ThreatMap::Update(Vector3 pos,std::string tag)
{
	if(tag == "TRACKER")
	CreateThreatMap(pos, threat_data_tracker);
	else if(tag == "SPY")
	CreateThreatMap(pos, threat_data_spy);

}



void ThreatMap::Draw()
{
	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < threat_data_tracker[y].size(); x++)
		{
			SpriteBatch.DrawString(DefaultFont, Vector2(50*x, 50*y), Color(255, 0, 0), _T("%.4f"), threat_data_spy[y][x]);
		}
	}
}

void ThreatMap::CreateThreatMap(Vector3 pos, std::vector<float>* data)
{
	int mx = (int)(pos.x / 50);
	int my = (int)(pos.y / 50);
	//‹ºˆÐƒ}ƒbƒv
	if (mx != prev_mx || my != prev_my) {
		float max = FLT_MIN;
		float min = FLT_MAX;
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < map_data[y].size(); x++) {
				if (map_data[y][x] == ' ' || map_data[y][x] == '%') {
					data[y][x] = Vector3_Distance(pos, Vector3(x * 50, y * 50, 0));
					if (max < data[y][x])
					{
						max = data[y][x];
					}
					if (min > data[y][x])
					{
						min = data[y][x];
					}
				}
				else {
					data[y][x] = -1;
				}
			}
		}
		float normal = max - min;
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < map_data[y].size(); x++) {
				if (data[y][x] >= 0)
					data[y][x] = ((data[y][x] - min) / normal);
				else
					data[y][x] = 0;
			}
		}
		prev_mx = mx;
		prev_my = my;
	}
}

