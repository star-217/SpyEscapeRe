#include "Invisible.h"


float Invisible::Update()
{
	float alpha_speed = 20.0f;
	float max_time = 120.0f;

	if (_flag == true)
	{
		_time++;
		_alpha += alpha_speed;

		if (_time >= max_time)
		{
			_flag = false;
			_alpha = 1.0f;
			_time = 0.0f;
		}

	}
	if (_alpha >= 255.0f) {
		_alpha = 255.0f;
	}

	return _alpha;
}

