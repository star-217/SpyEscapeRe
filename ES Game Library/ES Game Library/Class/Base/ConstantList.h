/**
 * @file Constantlist.h
 * @brief �萔��enum�N���X�̃��X�g
 * @author ������
 * @date 2021/07/14
 */

#pragma once

#include "../../ESGLib.h"

#define BLOCK_SIZE 50 //���킯�̊��
#define MAP_MAX_HEIGHT 18 //�}�b�v�f�[�^�̔z��
#define PLAYER_MAX 2 //�v���C���[�̍ő吔
#define PREV_MAX 4 // �k�����
#define CHARA_SIZE_X 50
#define CHARA_SIZE_Y 70
#define FIXED_POS_Y 20

enum class Direction //�L�������i�ޕ���
{
	None,
	Down,
	Left,
	Right,
	Up
};

enum class SpyState
{
	Default,
	Win,
	Lose
};

enum class TrackerState
{
	Default,
	Win,
	Lose,
	Attack
};