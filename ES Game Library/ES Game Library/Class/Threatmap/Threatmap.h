#pragma once

#include "../../ESGLib.h"

class ThreatMap
{
public:
	void Initialize(const std::vector<cstring>);
	void Update(Vector3 positon,std::string tag);
	void CreateThreatMap(Vector3,std::vector<float>*);
	std::vector<float>* GetSpyData() { return threat_data_spy; }
	std::vector<float>* GetTrackerData() { return threat_data_tracker; }
	void Draw();

private:

	std::vector<cstring>  map_data;
	std::vector<float>	  threat_data_tracker[18];
	std::vector<float>	  threat_data_spy[18];

	int prev_mx;
	int prev_my;

	int prev_pos_x[3], prev_pos_y[3];

	FONT DefaultFont;

};