/**
 * @file  Threatmap.cpp
 * @brief 脅威マップを生成するクラス
 * @author 星寛文
 * @date 2021/04/20
 */

#pragma once

#include "../../ESGLib.h"
#include "../Map/Map.h"
#include "../Base/HumanBase/HumanBase.h"

class ThreatMap
{
public:
	ThreatMap();
	virtual ~ThreatMap() {};

	void Initialize();
	void Update();
	void Draw();

	void SetPosData(HumanBase* human) 
	{
		if (human->GetTag() == "SPY")
			_spy_pos = human->GetPosition();
		if (human->GetTag() == "SPY")
			_tracker_pos = human->GetPosition();
	}

	void SetMapdata(std::vector<cstring> map_data) { _map_data = map_data; }
	std::vector<std::vector<float>> CreateTheatData(float ratio, std::vector<Vector2>& old_pos);

private:
	std::vector<std::vector<float>> CreateDistanceMap(Vector3 pos);

	std::vector<cstring>  _map_data;

	std::vector<std::vector<float>>	  _threat_data;
	std::vector<std::vector<float>>	  _threat_data_tracker;
	std::vector<std::vector<float>>	  _threat_data_spy;

	Vector3 _spy_pos;
	Vector3 _tracker_pos;

	//過去の座標
	const int PREV_MAX = 3;
	int _prev_mx;
	int _prev_my;

	FONT _default_font;
};