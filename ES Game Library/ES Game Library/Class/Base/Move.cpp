#include "Move.h"

void CMove::Initialize()
{
	InputDevice.CreateGamePad(2);
	block_size = 50;
	direction = 0;
	pad_direction = 0;
}

Vector3 CMove::Move(Vector3 pos, std::vector<cstring> map_data,float speed,int pad_number)
{
	pad = GamePad(pad_number)->GetState();


	if (pad_direction == 0)
	{
		if (pad.X != 0 || pad.Y != 0) {
			int mx = (int)(pos.x / 50);
			int my = (int)(pos.y / 50);
			float axis_x = Math_Abs(pad.X);
			float axis_y = Math_Abs(pad.Y);
			if (axis_x > axis_y) {
				if (pad.X > 0) {
					if (map_data[my][mx + 1] == ' ' || map_data[my][mx + 1] == '%') {
						pad_direction = 6;
						count = 0;
					}
				}
				else if (pad.X < 0) {
					if (map_data[my][mx - 1] == ' ' || map_data[my][mx - 1] == '%') {
						pad_direction = 4;
						count = 0;
					}
				}
			}
			else {
				if (pad.Y > 0) {
					if (map_data[my + 1][mx] == ' ' || map_data[my + 1][mx] == '%') {
						pad_direction = 2;
						count = 0;
					}
				}
				else if (pad.Y < 0) {
					if (map_data[my - 1][mx] == ' ' || map_data[my - 1][mx] == '%') {
						pad_direction = 8;
						count = 0;
					}
				}
			}
		}
	}

	//ƒLƒƒƒ‰‚ÌˆÚ“®AˆÚ“®§ŒÀ
	if (pad_direction == 6) {
		pos.x += speed;
		direction = 2;
		count += speed;
		if (count >= 50) {
			pad_direction = 0;
		}

	}
	else if (pad_direction == 4) {
		pos.x -= speed;
		direction = 1;

		count += speed;

		if (count >= 50) {
			pad_direction = 0;
		}
	}
	else if (pad_direction == 2) {
		pos.y += speed;
		direction = 0;

		count += speed;

		if (count >= 50) {
			pad_direction = 0;
		}

	}
	else if (pad_direction == 8) {
		pos.y -= speed;
		direction = 3;

		count += speed;

		if (count >= 50) {
			pad_direction = 0;
		}

	}

	return pos;


}
