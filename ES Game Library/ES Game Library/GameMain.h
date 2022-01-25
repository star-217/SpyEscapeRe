#pragma once

#include "ESGLib.h"
#include "GameScene/GameScene.hpp"
#include "Class/Tracker/Tracker.h"
#include "Class/Spy/Spy.h"
#include "Class/Map/Map.h"
#include "Class/Sound/Sound.h"
#include "Class/Decoy/DecoyManager.h"
#include "Class/Base/Collision/Collision.h"

class GameMain : public CGameScene {
public:

	GameMain() : DefaultFont(nullptr)
	{
	}

	virtual ~GameMain()
	{
#ifdef _INC_SQUIRREL
		Squirrel.ReleaseAllScripts();
#endif
#ifdef _INC_NUI
		NUI.ReleaseAllKinects();
#endif
#ifdef _INC_LIVE2D
		Live2D.ReleaseAllModels();
#endif
#ifdef _INC_EFFEKSEER
		Effekseer.ReleaseAllEffects();
#endif
#ifdef _INC_DIRECT2D
		Direct2D.ReleaseAllResources();
#endif
		MediaManager.ReleaseAllMedia();

		SoundDevice.ReleaseAllMusics();
		SoundDevice.ReleaseAllSounds();

		GraphicsDevice.ReleaseAllRenderTargets();
		GraphicsDevice.ReleaseAllStateBlocks();
		GraphicsDevice.ReleaseAllFonts();
		GraphicsDevice.ReleaseAllSprites();
		GraphicsDevice.ReleaseAllAnimationModels();
		GraphicsDevice.ReleaseAllModels();
		GraphicsDevice.ReleaseAllVertexBuffers();
		GraphicsDevice.ReleaseAllEffects();

		Finalize();
	}

public:
	virtual bool Initialize();
	virtual int  Update();
	virtual void Draw();

private:
	void Finalize();
	FONT DefaultFont;

private:
	// ïœêîêÈåæ
	Tracker*   _tracker;
	Spy*       _spy;
	DecoyManager* _decoy;
	Collision* _collision;

	Vector3 _spy_pos;
	Vector3 _tracker_pos;
	Vector3 _fake_pos[6];

};
