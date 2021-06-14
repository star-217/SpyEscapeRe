#include "Invisible.h"


void Invisible::Update()
{
	if (flag == true)
	{
		time += 1.0f;
		alpha += 20.0f;

		if (time >= 120.0f)
		{
			flag = false;
			alpha = 1.0f;
			time = 0.0f;
		}

	}
	if (alpha >= 255.0f) {
		alpha = 255.0f;
	}

}

void Invisible::Draw()
{
}
