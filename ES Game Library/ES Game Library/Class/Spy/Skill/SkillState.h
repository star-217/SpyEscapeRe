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

	void   Update();
	void   Draw();
	void   RandomSkill();
	void   ChangeState(SkillBase* state);

	float GetAlpfa();

private:
	enum
	{
		BLACKOUT,
		INVISIBLE,
		SKILL_MAX
	};

	SkillBase*   _state;
	std::unique_ptr<SkillFactory> _factory;

	int          _skil_box[SKILL_MAX];
	int          _skil_count;
	int          _skil_count_max;
};