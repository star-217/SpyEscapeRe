#pragma once

#include "ESGLib.h"
#include "GameScene/GameScene.hpp"
#include "Class/Tracker/Tracker.h"
#include "Class/Spy/Spy.h"
#include "Class/Map/Map.h"
#include "Class/Sound/Sound.h"
#include "Class/Threatmap/Threatmap.h"
#include "Class/Decoy/DecoyManager.h"
#include "Class/Base/Collision.h"

class GameMain : public CGameScene {
public:
	GameMain()
	{
//		ContentRootDirectory(_T("Content"));
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
	static int GetTime() { return time; }

private:
	void Finalize();
	FONT DefaultFont;
	KeyboardState key;

private:
	// ïœêîêÈåæ

	Tracker   track;
	Spy       spy;
	Map       map;
	LoadSound sound;
	ThreatMap threatmap;
	DecoyManager decoy;
	Collision collision;

	Vector3 spy_pos;





	static int time;

	FONT original;

	float flame;
	//player
	SPRITE player;
	SPRITE playerwalk;
	SPRITE playerwin;
	Vector3 player_pos;
	float p_flame_x,p_flame_y;
	int p_walk_flag;
	float player_spd;
	float player_state;
	int player_count;
	float down_flame;

	//skil
	SPRITE skill;
	bool skill_state;
	float skill_time;
	float skill_alpha;
	bool alpha_flag;
	bool fake_flag;
	int abc;
	bool black_flag;
	float invisible_state;
	float invisible_time;
	float invisible_alpha;
	float randam_skil;
	float randam[5];
	float skil_time;
	float âzëO;

	//oni
	SPRITE tracker;
	Vector3 tracker_pos;
	float tracker_alpha;
	float tracker_spd;
	float stun_time;
	float tracker_count;
	bool stun_state;

	SPRITE tracker_attack;
	float tracker_flame_x, tracker_flame_y;
	float attack_state;

	int tracker_state;
	float win_flame;
	float win_time;

	SPRITE lose;
	float lose_flame;
	float lose_time;

	// ä÷êîêÈåæ
	void Tracker();
	void kabe();
	void Player();
	void Fake(Vector3& ai_pos, int& move_count, int& ai_pattern, float& dir, int old_pos_x[], int old_pos_y[], std::vector<float> ai_mapdata[],int& c);
	void AI();

	std::vector<cstring> map_data;
	FONT newfont;

	Vector3 change;

	float anime;

	float a_alpha;
	float b_alpha;

	int f;
	float speed = 5;
	//AI
	Vector3 fake_pos[6];
	Vector3 fake2_pos;
	Vector3 fake3_pos;
	Vector3 fake4_pos;
	Vector3 fake5_pos;
	Vector3 fake6_pos;


};
