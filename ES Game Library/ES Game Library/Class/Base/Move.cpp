#include "Move.h"

void Move::Initialize()
{
	InputDevice.CreateGamePad(2);
	_block_size = 50;
	_direction = 0;
	_pad_direction = 0;
}

Vector3 Move::MovePostion(Vector3 pos, std::vector<cstring> map_data,float speed,int pad_number)
{
	_pad = GamePad(pad_number)->GetState();


	if (_pad_direction == 0)
	{
		if (_pad.X != 0 || _pad.Y != 0) {
			int mx = (int)(pos.x / 50);
			int my = (int)(pos.y / 50);
			float axis_x = Math_Abs(_pad.X);
			float axis_y = Math_Abs(_pad.Y);
			if (axis_x > axis_y) {
				if (_pad.X > 0) {
					if (map_data[my][mx + 1] == ' ' || map_data[my][mx + 1] == '%') {
						_pad_direction = 6;
						_count = 0;
					}
				}
				else if (_pad.X < 0) {
					if (map_data[my][mx - 1] == ' ' || map_data[my][mx - 1] == '%') {
						_pad_direction = 4;
						_count = 0;
					}
				}
			}
			else {
				if (_pad.Y > 0) {
					if (map_data[my + 1][mx] == ' ' || map_data[my + 1][mx] == '%') {
						_pad_direction = 2;
						_count = 0;
					}
				}
				else if (_pad.Y < 0) {
					if (map_data[my - 1][mx] == ' ' || map_data[my - 1][mx] == '%') {
						_pad_direction = 8;
						_count = 0;
					}
				}
			}
		}
	}

	//ƒLƒƒƒ‰‚ÌˆÚ“®AˆÚ“®§ŒÀ
	if (_pad_direction == 6) {
		pos.x += speed;
		_direction = 2;
		_count += speed;
		if (_count >= 50) {
			_pad_direction = 0;
		}

	}
	else if (_pad_direction == 4) {
		pos.x -= speed;
		_direction = 1;

		_count += speed;

		if (_count >= 50) {
			_pad_direction = 0;
		}
	}
	else if (_pad_direction == 2) {
		pos.y += speed;
		_direction = 0;

		_count += speed;

		if (_count >= 50) {
			_pad_direction = 0;
		}

	}
	else if (_pad_direction == 8) {
		pos.y -= speed;
		_direction = 3;

		_count += speed;

		if (_count >= 50) {
			_pad_direction = 0;
		}

	}

	return pos;


}
