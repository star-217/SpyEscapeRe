#pragma once

#include "../../../ESGLib.h"
#include "SkillFactory.h"


class SkillState
{
public:
	SkillState();
	virtual ~SkillState() {};

	float  Update();
	void   Draw();
	void   RandomSkil();
	void   ChangeState(SkillBase* state);

private:
	enum
	{
		BLACKOUT,
		INVISIBLE,
		MAX
	};

	SkillBase*   _state;
	SkillFactory _factory;

	int          _skil_box[MAX];
	int          _skil_count;
	int          _skil_count_max;
};