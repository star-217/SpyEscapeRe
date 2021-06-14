#pragma once

#include "../../../ESGLib.h"
#include "SkillBase.h"

class Invisible : public SkillBase
{
public:

	void Update();
	void Draw();

private:
	float alpha;
	bool flag;
	int time;
};