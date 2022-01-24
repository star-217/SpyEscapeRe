/**
 * @file  Invisible.h
 * @brief Invisible.cpp�̃w�b�_�[�t�@�C��
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

	float Update();
	void  Draw() {};

private:
	float _alpha;
	bool  _flag;
	int	  _time;
};