/**
 * @file  Noskill.h
 * @brief Spyがスキルを使っていないとき
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../../ESGLib.h"
#include "SkillBase.h"

class NoSkill : public SkillBase
{
public:

	void Update() {};
	void Draw() {};

private:

};