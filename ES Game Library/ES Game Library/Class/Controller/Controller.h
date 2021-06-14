#pragma once

#include "../../ESGLib.h"

class Controller
{
public:
	static Controller& Instance() {
		static Controller instance;
		return instance;
	}

	static void Initialize();
	void Update(int);
	int GetDirection() { return pad_direction; }
	

private:
	GamePadState pad;
	int pad_direction;

};