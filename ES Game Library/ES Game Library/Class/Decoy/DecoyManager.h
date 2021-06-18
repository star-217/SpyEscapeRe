#pragma once

#include "../../ESGLib.h"
#include "DecoyBase.h"

class DecoyManager
{
public:
	DecoyManager();
	virtual ~DecoyManager() {};

	void Initialize(Vector3* positions);
	void Update(ThreatMap);
	void Draw();
	DecoyBase* GetBase() { return _decoy; }

private:
	DecoyBase _decoy[6];

	float _ratio[6];

	int _wait_count[6];

};