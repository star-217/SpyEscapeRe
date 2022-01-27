/**
 * @file  Move.cpp
 * @brief �R���g���[���̈ړ��v���O����
 * @author ������
 * @date 2021/04/20
 */
#include "Move.h"

void Move::Initialize()
{
	_direction     = Direction::Down;
	_pad_direction = Direction::None;
}

/**
 * @fn
 * �R���g���[���ŃL�����N�^�[���ړ�������v���O�����ł��B
 * @param (pos) �L�����N�^�[�̃|�W�V����
 * @param (map_data) �}�b�v�f�[�^
 * @param (speed) �L�����N�^�[�̈ړ����x
 * @param (pad_number) �R���g���[���[�ԍ�
 * @return �L�����N�^�[�̃|�W�V������Ԃ�
 * @detail
 */
Vector3 Move::MovePostion(Vector3 pos,float speed,int pad_number)
{	
	//�L�����̈ړ��A�ړ�����
	auto _count_clamp = [&](const int delta)
	{
		_count += delta;
		_flag = false;
		if (_count >= BLOCK_SIZE) {
			_pad_direction = Direction::None;
			_flag = true;
		}
	};

	switch (_pad_direction) {
	case Direction::Right:
		_direction = Direction::Right;
		pos.x     += speed;
		_count_clamp(speed);
		break;

	case Direction::Left:
		_direction = Direction::Left;
		pos.x     -= speed;
		_count_clamp(speed);
		break;

	case Direction::Down:
		_direction = Direction::Down;
		pos.y     += speed;
		_count_clamp(speed);
		break;

	case Direction::Up:
		_direction = Direction::Up;
		pos.y     -= speed;
		_count_clamp(speed);
		break;
	}

	return pos;
}

/**
 * @fn
 * �R���g���[���[�̓��͕������擾����B
 * @param (pos) �L�����N�^�[�̃|�W�V����
 * @param (pad_number) �R���g���[���[�ԍ�
 */
void Move::PadDirection(Vector3 pos, int pad_number)
{
	_pad = GamePad(pad_number)->GetState();
	//�Q�[���p�b�h�̕����̎擾���A���̕����ɐi�߂邩���ׂ�
	if (_pad_direction == Direction::None)
	{
		if (_pad.X != 0 || _pad.Y != 0) {
			auto isPassing = [&](const int x, const int y)
			{
				if (_map_data[y][x] == ' ' || _map_data[y][x] == '%')
					return true;
				return false;
			};

			int mx = (int)(pos.x / BLOCK_SIZE);
			int my = (int)(pos.y / BLOCK_SIZE);
			float axis_x = Math_Abs(_pad.X);
			float axis_y = Math_Abs(_pad.Y);
			if (axis_x > axis_y) {
				if (_pad.X > 0) {
					if (isPassing(mx + 1, my)) {
						_pad_direction = Direction::Right;
						_count = 0;
					}
				}
				else if (_pad.X < 0) {
					if (isPassing(mx - 1, my)) {
						_pad_direction = Direction::Left;
						_count = 0;
					}
				}
			}
			else {
				if (_pad.Y > 0) {
					if (isPassing(mx, my + 1)) {
						_pad_direction = Direction::Down;
						_count = 0;
					}
				}
				else if (_pad.Y < 0) {
					if (isPassing(mx, my - 1)) {
						_pad_direction = Direction::Up;
						_count = 0;
					}
				}
			}
		}
	}
}
