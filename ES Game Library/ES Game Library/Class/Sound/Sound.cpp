#include "Sound.h"

void LoadSound::Initialize()
{
	MediaManager.Attach(GraphicsDevice);
	_bgm[MAIN]     = MediaManager.CreateMediaFromFile(_T("bgm3.mp3"));
	_bgm[LIMIT]    = MediaManager.CreateMediaFromFile(_T("mission.mp3"));
	_bgm[SKILSE]   = MediaManager.CreateMediaFromFile(_T("Spotlight04-1.mp3"));
	_se            = SoundDevice.CreateSoundFromFile(_T("nc86224.wav"));

}


