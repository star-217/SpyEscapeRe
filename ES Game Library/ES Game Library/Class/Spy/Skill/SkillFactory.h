/**
 * @file  SkillFactory.h
 * @brief �X�L���̐����N���X
 * @author ������
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
	* @detail �X�L���𐶐�����
	* @param  count �ԍ�
	* @return ���������X�L���̃N���X��Ԃ�
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