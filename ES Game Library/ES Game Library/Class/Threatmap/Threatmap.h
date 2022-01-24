/**
 * @file  Threatmap.h
 * @brief Threatmap.cppのヘッダーファイル
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../ESGLib.h"
#include "../Base/ConstantList.h"
#include "../Base/FontData.h"

class ThreatMap
{
public:
	ThreatMap();
	virtual ~ThreatMap() {};

	void Initialize(const std::vector<cstring>&);
	void Update(Vector3 positon,std::string tag);
	void CreateThreatMap(Vector3,std::vector<float>*);
	std::vector<float>* GetSpyData() { return _threat_data_spy; }
	std::vector<float>* GetTrackerData() { return _threat_data_tracker; }
	void Draw();

private:
	std::vector<cstring>  _map_data;
	std::vector<float>	  _threat_data_tracker[MAP_MAX_HEIGHT];
	std::vector<float>	  _threat_data_spy[MAP_MAX_HEIGHT];

	int _prev_mx;
	int _prev_my;

};