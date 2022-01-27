/**
 * @file Collision.h
 * @brief “–‚½‚è”»’èƒNƒ‰ƒX
 * @author ¯Š°•¶
 * @date 2021/04/20
 */
#pragma once

#include "../../../ESGLib.h"
#include "../../Base/HumanBase/HumanBase.h"

class Collision
{
public:
	Collision() = default;
	virtual ~Collision() {}

	void AddListener(std::string tag,HumanBase* human);

	void CheckCollision(std::string tag, std::string tag2);

private:
	std::map<std::string,std::vector<HumanBase*>> _human_list;

};