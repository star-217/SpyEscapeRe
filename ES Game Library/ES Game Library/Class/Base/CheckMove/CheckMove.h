/**
 * @file  CheckMove.h
 * @brief ����̃N���X�����������Ƃ𒲂ׂ�N���X
 * @author ������
 * @date 2022/01/27
 */

#pragma once

#include "../../Base/HumanBase/HumanBase.h"

class CheckMove {
public:

	CheckMove() = default;
	virtual ~CheckMove() {}

	void AddListener(HumanBase* human);

	void Notify(HumanBase* human);
private:
	std::vector<HumanBase*> _human_list;
};