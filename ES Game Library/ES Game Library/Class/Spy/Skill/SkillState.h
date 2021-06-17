#pragma once

#include "../../../ESGLib.h"
#include "SkillFactory.h"


class SkillState
{
public:
	SkillState();
	virtual ~SkillState() {};

	float  Update();
	void  Draw();
	void  RandomSkil();
	void  ChangeState(SkillBase* state);

private:
	enum
	{
		BLACKOUT,
		INVISIBLE,
		MAX
	};

	SkillBase* state;
	SkillFactory factory;

	int skil_box[MAX];
	int skil_count;
	int skil_count_max;
};