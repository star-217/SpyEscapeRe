/**
 * @file  SkillState.h
 * @brief SkillState.cppのヘッダーファイル
 * @author 星寛文
 * @date 2021/04/20
 */
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
		SKILL_MAX
	};

	SkillBase*   _state;
	SkillFactory _factory;

	int          _skil_box[SKILL_MAX];
	int          _skil_count;
	int          _skil_count_max;
};