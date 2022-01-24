/**
 * @file  SkillBase.h
 * @brief Spy�̃X�L���̃x�[�X
 * @author ������
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