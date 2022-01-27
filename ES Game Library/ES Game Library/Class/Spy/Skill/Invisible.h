/**
 * @file  Invisible.h
 * @brief �������X�L���N���X
 * @author ������
 * @date 2021/04/20
 */
#pragma once

#include "../../../ESGLib.h"
#include "SkillBase.h"

class Invisible : public SkillBase
{
public:
	Invisible();
	virtual ~Invisible() {};

	void  Update() override;
	void  Draw() {};


private:

	bool  _flag;
	int	  _time;
};