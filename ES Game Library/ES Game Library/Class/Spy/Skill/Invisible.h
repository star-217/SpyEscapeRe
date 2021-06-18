#pragma once

#include "../../../ESGLib.h"
#include "SkillBase.h"

class Invisible : public SkillBase
{
public:

	float Update();
	void Draw();

private:
	float _alpha;
	bool _flag;
	int _time;
};