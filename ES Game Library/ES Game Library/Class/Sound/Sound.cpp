#include "Sound.h"

void LoadSound::Initialize()
{
	MediaManager.Attach(GraphicsDevice);
	bgm[MAIN]     = MediaManager.CreateMediaFromFile(_T("bgm3.mp3"));
	bgm[LIMIT]    = MediaManager.CreateMediaFromFile(_T("mission.mp3"));
	bgm[SKILSE]   = MediaManager.CreateMediaFromFile(_T("Spotlight04-1.mp3"));
	se            = SoundDevice.CreateSoundFromFile(_T("nc86224.wav"));
	

	
}


