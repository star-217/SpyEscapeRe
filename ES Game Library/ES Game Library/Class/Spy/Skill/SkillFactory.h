#pragma once

#include "../../../ESGLib.h"
#include "BlackOut.h"
#include "NoSkill.h"
#include "Invisible.h"

class SkillFactory
{
public:
	SkillBase* Create(int count)
	{
		SkillBase* state = new NoSkill;

		switch (count)
		{
		case BLACKOUT:
			state = new BlackOut; break;
		case INVISIBLE:
			state = new Invisible; break;
		default:
			state = new NoSkill; break;
			break;
		}

		return state;

	};

private:

	enum
	{
		BLACKOUT,
		INVISIBLE
	};
};