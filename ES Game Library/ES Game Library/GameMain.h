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

	SPRITE wall;
	SPRITE floar;
	SPRITE fake;

	SPRITE down;
	SPRITE oniwin;
	SPRITE isu;
	Vector3 change;

	float anime;

	//direction
	float direc;
	float direc2;
	float direc3;
	float direc4;
	float direc5;
	float direc6;
	float direc7;
	float direc8;


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
	int k,k_count;
	int j, j_count;
	int h, h_count;
	int g, g_count;
	int p, p_count;
	int o, o_count;
	int a,b;
	int fake_stop_count[6];
	int AI_count;



	std::vector<float> dist[18];
	std::vector<float> dist_A[18];
	std::vector<float> dist2[18];
	std::vector<float> dist3[18];
	std::vector<float> dist4[18];
	std::vector<float> dist5[18];
	std::vector<float> dist6[18];
	std::vector<float> dist_player[18];
	std::vector<float> dist_AI[18];

	// ä÷êîêÈåæ
	/*string map_data[18];*/
	float max,max2;
	float min, min2;
	float normal;
	float normal2;
	float sw_f = 0;


	int mx_k[4],my_k[4];
	int  mx_i[4], my_i[4];
	int  mx_h[4], my_h[4];
	int  mx_g[4], my_g[4];
	int  mx_p[4], my_p[4];
	int  mx_o[4], my_o[4];

	int prev_mx, prev_my;
	int prev_mx2, prev_my2;

	int pad2_direction;
	int pad_direction;

	Vector3 fake_speed[4];
	int fake_dir[4];
};
