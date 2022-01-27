/**
 * @file  CheckMove.h
 * @brief 特定のクラスが動いたことを調べるクラス
 * @author 星寛文
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