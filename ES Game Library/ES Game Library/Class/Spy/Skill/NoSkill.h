/**
 * @file  Noskill.h
 * @brief Spy���X�L�����g���Ă��Ȃ��Ƃ�
 * @author ������
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