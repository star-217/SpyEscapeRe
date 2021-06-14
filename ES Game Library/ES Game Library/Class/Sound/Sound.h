#pragma once

#include "../../ESGLib.h"

class LoadSound
{
public:
	void Initialize();
	MEDIA* GetBGM() { return bgm; }


	enum
	{
		MAIN, SKILSE, LIMIT, MAX
	};

private:

	

	MEDIA bgm[MAX];
	MEDIA skil;
	MEDIA mission;
	SOUND se;

};