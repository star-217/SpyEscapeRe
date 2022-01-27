/**
 * @file  BlackOut.h
 * @brief BlackOut.cpp
 * @author êØä∞ï∂
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

	void  Update() override;
	void  Draw() override;

private:
	SPRITE  _black;
	Vector3 _position;
};