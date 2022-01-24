/**
 * @file Collision.h
 * @brief Collision.cppのヘッダーファイル
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../../ESGLib.h"
#include "../../Spy/Spy.h"
#include "../../Tracker/Tracker.h"
#include "../../Decoy/DecoyManager.h"

class Spy;
class Tracker;
class DecoyManager;

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