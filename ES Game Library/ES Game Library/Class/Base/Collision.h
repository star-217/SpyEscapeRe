/**
 * @file Collision.h
 * @brief Collision.cpp�̃w�b�_�[�t�@�C��
 * @author ������
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