#pragma once

#include "../../ESGLib.h"

class SoundResource
{
public:
	~SoundResource() {};
	void Initialize();
	MEDIA& GetBGM(std::string name) { return _bgm[name]; }

	static SoundResource& GetInstance()
	{
		static SoundResource sound;
		return sound;
	}

private:
	SoundResource();

	std::map<std::string, MEDIA> _bgm;
	SOUND _se;
};

#define SEResource SoundResource::GetInstance();