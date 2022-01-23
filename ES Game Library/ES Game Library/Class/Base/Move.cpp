#include "Move.h"

void Move::Initialize()
{
	_block_size    = 50;
	_direction     = Direction::None;
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
Vector3 Move::MovePostion(Vector3 pos, std::vector<cstring>& map_data,float speed,int pad_number)
{
	GamePadState _pad = GamePad(pad_number)->GetState();
	if (_pad_direction == Direction::None)
	{
		if (_pad.X != 0 || _pad.Y != 0) {
			int mx = (int)(pos.x / _block_size);
			int my = (int)(pos.y / _block_size);
			float axis_x = Math_Abs(_pad.X);
			float axis_y = Math_Abs(_pad.Y);
			if (axis_x > axis_y) {
				if (_pad.X > 0) {
					if (map_data[my][mx + 1] == ' ' || map_data[my][mx + 1] == '%') {
						_pad_direction = Direction::Right;
						_count = 0;
					}
				}
				else if (_pad.X < 0) {
					if (map_data[my][mx - 1] == ' ' || map_data[my][mx - 1] == '%') {
						_pad_direction = Direction::Left;
						_count = 0;
					}
				}
			}
			else {
				if (_pad.Y > 0) {
					if (map_data[my + 1][mx] == ' ' || map_data[my + 1][mx] == '%') {
						_pad_direction = Direction::Down;
						_count = 0;
					}
				}
				else if (_pad.Y < 0) {
					if (map_data[my - 1][mx] == ' ' || map_data[my - 1][mx] == '%') {
						_pad_direction = Direction::Up;
						_count = 0;
					}
				}
			}
		}
	}

	//�L�����̈ړ��A�ړ�����
	switch (_pad_direction) {
	case Direction::Right:
		_direction = Direction::Right;
		pos.x     += speed;
		_count    += speed;
		if (_count >= MAXBLOCKCOUNT) {
			_pad_direction = Direction::None;
		}
		break;

	case Direction::Left:
		_direction = Direction::Left;
		pos.x     -= speed;
		_count    += speed;
		if (_count >= MAXBLOCKCOUNT) {
			_pad_direction = Direction::None;
		}
		break;

	case Direction::Down:
		_direction = Direction::Down;
		pos.y     += speed;
		_count    += speed;
		if (_count >= MAXBLOCKCOUNT) {
			_pad_direction = Direction::None;
		}
		break;

	case Direction::Up:
		_direction = Direction::Up;
		pos.y     -= speed;
		_count    += speed;
		if (_count >= MAXBLOCKCOUNT) {
			_pad_direction = Direction::None;
		}
		break;
	}

	return pos;
}
