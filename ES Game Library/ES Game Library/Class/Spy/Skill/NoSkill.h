#pragma once

#include "../../../ESGLib.h"
#include "SkillBase.h"

class NoSkill : public SkillBase
{
public:

	float Update() { return 1.0f; }
	void Draw() {};

private:

};