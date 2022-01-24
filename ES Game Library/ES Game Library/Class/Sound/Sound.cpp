#include "Sound.h"

void SoundResource::Initialize()
{
	MediaManager.Attach(GraphicsDevice);
	_bgm["main"]     = MediaManager.CreateMediaFromFile(_T("bgm3.mp3"));
	_bgm["limit"] = MediaManager.CreateMediaFromFile(_T("mission.mp3"));
	_bgm["skill_se"] = MediaManager.CreateMediaFromFile(_T("Spotlight04-1.mp3"));
	_se            = SoundDevice.CreateSoundFromFile(_T("nc86224.wav"));

}


