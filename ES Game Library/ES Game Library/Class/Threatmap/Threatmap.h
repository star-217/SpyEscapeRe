#pragma once

#include "../../ESGLib.h"
#include "../Map/Map.h"

class ThreatMap
{
public:
	ThreatMap() {};
	virtual ~ThreatMap() {};

	void Initialize();
	void Update();
	void Draw();

	void SetSpyPosData(Vector3 pos) { _spy_pos = pos; }
	void SetTrackerPosData(Vector3 pos) { _tracker_pos = pos; }

	std::vector<std::vector<float>> CreateTheatData(float ratio, std::vector<Vector2>& old_pos);

private:
	std::vector<std::vector<float>> CreateDistanceMap(Vector3 pos);

	std::vector<cstring>  _map_data;

	std::vector<std::vector<float>>	  _threat_data;
	std::vector<std::vector<float>>	  _threat_data_tracker;
	std::vector<std::vector<float>>	  _threat_data_spy;

	Vector3 _spy_pos;
	Vector3 _tracker_pos;

	int _prev_mx;
	int _prev_my;

	FONT _default_font;
};