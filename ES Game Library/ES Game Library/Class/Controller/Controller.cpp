#include "Controller.h"



void Controller::Initialize()
{
	InputDevice.CreateGamePad(2);

}

void Controller::Update(int pad_number)
{
	pad = GamePad(pad_number)->GetState();
	

	//�p�b�h�̓��͂����������ɃL�����������悤�Ɂi�΂߈ړ��̋֎~�j
	pad_direction = 0;
	if (pad.X != 0 || pad.Y != 0) {
		float axis_x = Math_Abs(pad.X);
		float axis_y = Math_Abs(pad.Y);
		if (axis_x > axis_y) {
			if (pad.X > 0) {
				pad_direction = 6;
			}
			else if (pad.X < 0) {
				pad_direction = 4;
			}
		}
		else {
			if (pad.Y > 0) {
				pad_direction = 2;
			}
			else if (pad.Y < 0) {
				pad_direction = 8;
			}
		}
	}

}


