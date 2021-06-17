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
	DecoyBase* GetBase() { return decoy; }

private:
	DecoyBase decoy[6];

	float ratio[6];

	int wait_count[6];

};