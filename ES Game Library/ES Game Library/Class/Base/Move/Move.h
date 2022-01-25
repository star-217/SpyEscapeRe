/**
 * @file  Move.h
 * @brief Move.cpp�̃w�b�_�[�t�@�C��
 * @author ������
 * @date 2021/04/20
 */
#pragma once

#include "../../../ESGLib.h"


class Move
{
public:

	enum class Direction //�L�������i�ޕ���
	{
		None,
		Down,
		Left,
		Right,
		Up
	};

	Move() = default;
	virtual ~Move() {}

	void      Initialize();
	Vector3   MovePostion(Vector3 pos, std::vector<cstring>& map_data, float speed,int pad_number);
	Direction GetDirection() const { return _direction; }

private:

	Direction _pad_direction;
	int       _count;
	Direction _direction;

	const int MAXBLOCKCOUNT = 50;
	const int BLOCK_SIZE = 50;
};