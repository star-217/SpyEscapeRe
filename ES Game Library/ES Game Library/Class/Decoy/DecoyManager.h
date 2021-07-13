#pragma once

#include "../../ESGLib.h"
#include "DecoyBase.h"

class DecoyManager
{
public:
	DecoyManager();
	virtual ~DecoyManager() {};

	void Initialize(std::vector<cstring>& ,Vector3* positions);
	void Update(ThreatMap);
	void Draw();
	DecoyBase* GetBase() { return _decoy; }

private:
	enum
	{
		DECOY_MAX = 6
	};

	DecoyBase _decoy[DECOY_MAX];

	float _ratio[DECOY_MAX];

	int _wait_count[DECOY_MAX];

};