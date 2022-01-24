/**
 * @file  Noskill.h
 * @brief Spy‚ªƒXƒLƒ‹‚ğg‚Á‚Ä‚¢‚È‚¢‚Æ‚«
 * @author ¯Š°•¶
 * @date 2021/04/20
 */
#pragma once

#include "../../../ESGLib.h"
#include "SkillBase.h"

class NoSkill : public SkillBase
{
public:

	float Update() { return 1.0f; }
	void Draw() {};

private:

};