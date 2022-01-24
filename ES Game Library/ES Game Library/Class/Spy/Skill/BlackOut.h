/**
 * @file  BlackOut.h
 * @brief BlackOut.cppのヘッダーファイル
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../../ESGLib.h"
#include "SkillBase.h"

class BlackOut : public SkillBase
{
public:
	BlackOut();
	virtual ~BlackOut() {};

	float Update();
	void  Draw();

private:
	SPRITE  _black;
	Vector3 _position;
	float   _alpha;
};