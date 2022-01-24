/**
 * @file Collision.h
 * @brief Collision.cppのヘッダーファイル
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../ESGLib.h"

class Spy;
class Tracker;
class DecoyManager;

class Collision
{
public:
	Collision() = default;
	virtual ~Collision() {}

	void Update(Spy&, Tracker&, DecoyManager&);

private:

};