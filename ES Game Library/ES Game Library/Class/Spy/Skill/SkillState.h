#pragma once

#include "../../../ESGLib.h"
#include "BlackOut.h"
#include "NoSkill.h"
#include "Invisible.h"


class SkillState
{
public:
	SkillState();
	virtual ~SkillState() {};

	void  Update();
	void  Draw();
	void  RandomSkil();
	void  ChangeState(SkillBase* state);

	//void  BlackOut();
	//float Invisible();
	//void  SpyStun();
	//void  AllStun();
	//void  ColorChange();

private:
	enum
	{
		BLACKOUT,
		INVISIBLE,
		MAX
	};

	SkillBase* state;

	int skil_box[MAX];
	int skil_count;
	int skil_count_max;
};