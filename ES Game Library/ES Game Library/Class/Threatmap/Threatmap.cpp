/**
 * @file  Threatmap.h
 * @brief DecoyとSpy、Trackerそれぞれの距離を計算してMapにするプログラム
 * @author 星寛文
 * @date 2021/04/20
 */
#include "Threatmap.h"

ThreatMap::ThreatMap() : _prev_mx(0), _prev_my(0)
{
}

void ThreatMap::Initialize(const std::vector<cstring>& data)
{
	_map_data	  = data;
	_prev_mx	  = 0;
	_prev_my	  = 0;

	for (int y = 0; y < _map_data.size(); y++) {
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
	for (int y = 0; y < MAP_MAX_HEIGHT; y++) {
		for (int x = 0; x < _threat_data_tracker[y].size(); x++)
		{
			auto font = FontData::GetInstance().GetFont();
			SpriteBatch.DrawString(
				font, Vector2(BLOCK_SIZE * x, BLOCK_SIZE * y), Color(255, 0, 0),
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
	int mx = (int)(pos.x / BLOCK_SIZE);
	int my = (int)(pos.y / BLOCK_SIZE);
	//脅威マップ
	if (mx != _prev_mx || my != _prev_my) {
		float max = FLT_MIN;
		float min = FLT_MAX;
		for (int y = 0; y < _map_data.size(); y++) {
			for (int x = 0; x < _map_data[y].size(); x++) {
				if (_map_data[y][x] == ' ' || _map_data[y][x] == '%') {
					data[y][x] = Vector3_Distance(pos, Vector3(x * BLOCK_SIZE, y * BLOCK_SIZE, 0));
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
		for (int y = 0; y < _map_data.size(); y++) {
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

