#pragma once

#include "../../../ESGLib.h"
#include "SkillBase.h"

class BlackOut : public SkillBase
{
public:
	BlackOut();
	virtual ~BlackOut() {};

	float Update();
	void Draw();

private:
	SPRITE black;
	float  alpha;
	Vector3 position;
};