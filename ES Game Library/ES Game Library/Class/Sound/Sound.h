#pragma once

#include "../../ESGLib.h"

class LoadSound
{
public:
	void Initialize();
	MEDIA* GetBGM() { return _bgm; }


	enum
	{
		MAIN, SKILSE, LIMIT, MAX
	};

private:



	MEDIA _bgm[MAX];
	SOUND _se;

};