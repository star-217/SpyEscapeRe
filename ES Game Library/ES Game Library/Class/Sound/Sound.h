#pragma once

#include "../../ESGLib.h"

class SoundResource
{
public:
	void Initialize();
	MEDIA& GetBGM(std::string name) { return _bgm[name]; }

	static SoundResource& GetInstance()
	{
		static SoundResource sound;
		return sound;
	}

private:
	std::map<std::string, MEDIA> _bgm;
	SOUND _se;
};

#define SEResource SoundResource::GetInstance();