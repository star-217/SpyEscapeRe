/**
 * @file  SkillFactory.h
 * @brief スキルの生成クラス
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../../ESGLib.h"
#include "BlackOut.h"
#include "NoSkill.h"
#include "Invisible.h"

class SkillFactory
{
public:
	/**
	* @detail スキルを生成する
	* @param  count 番号
	* @return 生成したスキルのクラスを返す
	*/
	SkillBase* Create(int count)
	{

		switch (count)
		{
		case BLACKOUT:	return new BlackOut;
		case INVISIBLE: return new Invisible;
		default:		return new NoSkill;
		}

		return nullptr;
	};

private:

	enum
	{
		BLACKOUT,
		INVISIBLE
	};
};