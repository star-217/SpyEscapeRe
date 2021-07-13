#pragma once

#include "../../ESGLib.h"

class ThreatMap
{
public:
	ThreatMap();
	virtual ~ThreatMap();

	void Initialize(const std::vector<cstring>&);
	void Update(Vector3 positon,std::string tag);
	void CreateThreatMap(Vector3,std::vector<float>*);
	std::vector<float>* GetSpyData() { return _threat_data_spy; }
	std::vector<float>* GetTrackerData() { return _threat_data_tracker; }
	void Draw();

private:
	std::vector<cstring>  _map_data;
	std::vector<float>	  _threat_data_tracker[18];
	std::vector<float>	  _threat_data_spy[18];

	int _prev_mx;
	int _prev_my;

	FONT _default_font;
};