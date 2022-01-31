/**
 * @file  SkillBase.h
 * @brief スキルの基底クラス
 * @author 星寛文
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