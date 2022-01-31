/**
 * @file Constantlist.h
 * @brief �萔��enum�N���X�̃��X�g
 * @author ������
 * @date 2021/07/14
 */

#pragma once

#include "../../ESGLib.h"

//�L�����̉摜�T�C�Y
const Vector2 CHARA_SIZE = Vector2(50,70);
//�`���Y���C���l
const float FIX_POS_Y = 20.0f;
//1�u���b�N�P��
const int BLOCK_SIZE = 50.0f;

const float CHARA_SPEED = 5.0f;

enum class Direction //�L�������i�ޕ���
{
	None,
	Down,
	Left,
	Right,
	Up
};