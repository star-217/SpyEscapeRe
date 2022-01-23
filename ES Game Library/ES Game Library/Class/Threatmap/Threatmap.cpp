#include "Threatmap.h"

void ThreatMap::Initialize()
{
	_default_font = GraphicsDevice.CreateDefaultFont();
	_map_data	  = Map::GetMapData();
	_prev_mx	  = 0;
	_prev_my	  = 0;

	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < _map_data[y].size(); x++) {
			_threat_data_tracker[y].push_back(0);
			_threat_data_spy[y].push_back(0);
		}
	}

}

void ThreatMap::Update(Vector3 pos,std::string tag)
{
	if(tag == "TRACKER")
		CreateThreatMap(pos, _threat_data_tracker);
	else if(tag == "SPY")
		CreateThreatMap(pos, _threat_data_spy);
}

void ThreatMap::Draw()
{
#ifdef _DEBUG
	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < _threat_data_tracker[y].size(); x++)
		{
			SpriteBatch.DrawString(
				_default_font, Vector2(50 * x, 50 * y), Color(255, 0, 0),
				_T("%.4f"), _threat_data_spy[y][x]
			);
		}
	}
#endif
}

/**
 * @fn
 * デコイの挙動をAIで処理するための脅威マップを生成する関数です
 * @param (pos) 計算する相手のposition
 * @param (data) マップデータ
 * @detail デコイの場所と相手の場所の距離を計算し,それを0～1までの値に変換するアルゴリズムです
 */
void ThreatMap::CreateThreatMap(Vector3 pos, std::vector<float>* data)
{
	int mx = (int)(pos.x / 50);
	int my = (int)(pos.y / 50);
	//脅威マップ
	if (mx != _prev_mx || my != _prev_my) {
		float max = FLT_MIN;
		float min = FLT_MAX;
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < _map_data[y].size(); x++) {
				if (_map_data[y][x] == ' ' || _map_data[y][x] == '%') {
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
					data[y][x] = -1;	// 進行不可
				}
			}
		}
		float normal = max - min;
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < _map_data[y].size(); x++) {
				if (data[y][x] >= 0)
					data[y][x] = ((data[y][x] - min) / normal);
				else
					data[y][x] = 0;
			}
		}
		_prev_mx = mx; // 直前にいた座標を保存する
		_prev_my = my; // 直前にいた座標を保存する
	}
}

