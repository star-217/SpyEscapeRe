/**
 * @file  SkillBase.h
 * @brief �X�L���̊��N���X
 * @author ������
 * @date 2021/04/20
 */
#pragma once

#include "../../../ESGLib.h"

class SkillBase
{
public:
	SkillBase() : _alpha(1) {};
	virtual ~SkillBase() {};

	virtual void Update() = 0;
	virtual void Draw()    = 0;

	float GetAlpha() { return _alpha; }

protected:
	float _alpha;

};