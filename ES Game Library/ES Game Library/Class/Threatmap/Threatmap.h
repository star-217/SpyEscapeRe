#pragma once

#include "../../ESGLib.h"
#include "../Map/Map.h"

class ThreatMap
{
public:
	ThreatMap();
	virtual ~ThreatMap();

	void Initialize();
	void Update();
	void Draw();

	void SetSpyPosData(Vector3 pos) { _spy_pos = pos; }
	void SetTrackerPosData(Vector3 pos) { _tracker_pos = pos; }

	std::vector<float>* CreateTheatData(float ratio);

private:
	std::vector<float>* CreateDistanceMap(Vector3 pos);

	std::vector<cstring>  _map_data;

	std::vector<float>*	  _threat_data;
	std::vector<float>*	  _threat_data_tracker;
	std::vector<float>*	  _threat_data_spy;

	Vector3 _spy_pos;
	Vector3 _tracker_pos;

	int _prev_mx;
	int _prev_my;

	enum { PREV_MAX = 4 };	// ëkÇÈï‡êî
	int _old_pos_x[PREV_MAX];
	int _old_pos_y[PREV_MAX];

	FONT _default_font;
};