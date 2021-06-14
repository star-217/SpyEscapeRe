#pragma once

#include "../../../ESGLib.h"

class SkillBase
{
public:
	SkillBase() {};
	~SkillBase() {};

	virtual void Update() = 0;
	virtual void Draw() = 0;

private:

};