/**
 * @file  SkillBase.h
 * @brief Spyのスキルのベース
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../../ESGLib.h"

class SkillBase
{
public:
	SkillBase() = default;
	virtual ~SkillBase() {};

	virtual float Update() = 0;
	virtual void Draw()    = 0;

private:

};