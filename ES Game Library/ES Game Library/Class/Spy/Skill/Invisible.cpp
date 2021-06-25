#include "Invisible.h"


float Invisible::Update()
{
	if (_flag == true)
	{
		_time += 1.0f;
		_alpha += 20.0f;

		if (_time >= 120.0f)
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

void Invisible::Draw()
{
}
