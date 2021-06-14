// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"
#include "GameScene/SelectScene.hpp"

int GameMain::time = 0;

#include <fstream>
#define MAZE_WIDTH 32
#define MAZE_HEIGHT 18
/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));

	//GameTimer.SetFPS(10);
	//int cells[MAZE_WIDTH][MAZE_HEIGHT];

	DefaultFont = GraphicsDevice.CreateDefaultFont();




	time = 60;
	flame = 0;

	InputDevice.CreateGamePad(1);


	for (int i = 0; i < 4; i++) {
		mx_k[i] = 0;
		my_k[i] = 0;
		mx_i[i] = 0;
		my_i[i] = 0;
		mx_h[i] = 0;
		my_h[i] = 0;
		mx_g[i] = 0;
		my_g[i] = 0;
		mx_o[i] = 0;
		my_o[i] = 0;
		mx_p[i] = 0;
		my_p[i] = 0;

	}

	direc5 = 0;
	direc6 = 0;

	k_count = 10;
	j_count = 10;
	h_count = 10;
	g_count = 10;
	o_count = 10;
	p_count = 10;

	j = 0;
	h = 0;
	g = 0;
	k = 0;
	o = 0;
	p = 0;
	fake_speed[0] = Vector3(0, -1, 0);
	fake_speed[1] = Vector3(0, 1, 0);
	fake_speed[2] = Vector3(1, 0, 0);
	fake_speed[3] = Vector3(-1, 0, 0);
	fake_dir[0] = 3;
	fake_dir[1]	= 0;
	fake_dir[2]	= 2;
	fake_dir[3]	= 1;



	fake_stop_count[0] = 16;
	fake_stop_count[1] = 8;
	fake_stop_count[2] = 22;
	fake_stop_count[3] = 14;
	fake_stop_count[4] = 28;
	fake_stop_count[5] = 16;


	int select = SelectScene::GetSelect();

	Vector3 start_Pos[] = { Vector3(150,400,0),Vector3(800,100,0),Vector3(1250,150,0),Vector3(850, 700, 0),Vector3(50, 750, 0),Vector3(1500, 200, 0),Vector3(1500, 500, 0) };

	//選択シーンでの選択によっての分岐
	if (select == 0) {
		player_pos = start_Pos[0];
		fake_pos[0] = start_Pos[1];
		fake_pos[1] = start_Pos[2];
		fake_pos[2] = start_Pos[3];
		fake_pos[3] = start_Pos[4];
		fake_pos[4] = start_Pos[5];
		fake_pos[5] = start_Pos[6];
	}
	if (select == 1) {
		player_pos = start_Pos[1];
		fake_pos[0] = start_Pos[2];
		fake_pos[1] = start_Pos[0];
		fake_pos[2] = start_Pos[3];
		fake_pos[3] = start_Pos[4];
		fake_pos[4] = start_Pos[5];
		fake_pos[5] = start_Pos[6];
	}
	if (select == 2) {
		player_pos = start_Pos[2];
		fake_pos[0] = start_Pos[0];
		fake_pos[1] = start_Pos[1];
		fake_pos[2] = start_Pos[3];
		fake_pos[3] = start_Pos[4];
		fake_pos[4] = start_Pos[5];
		fake_pos[5] = start_Pos[6];
	}
	if (select == 3) {
		player_pos = start_Pos[3];
		fake_pos[0] = start_Pos[0];
		fake_pos[1] = start_Pos[1];
		fake_pos[2] = start_Pos[2];
		fake_pos[3] = start_Pos[4];
		fake_pos[4] = start_Pos[5];
		fake_pos[5] = start_Pos[6];
	}
	if (select == 4) {
		player_pos = start_Pos[4];
		fake_pos[0] = start_Pos[0];
		fake_pos[1] = start_Pos[1];
		fake_pos[2] = start_Pos[3];
		fake_pos[3] = start_Pos[2];
		fake_pos[4] = start_Pos[5];
		fake_pos[5] = start_Pos[6];
	}
	if (select == 5) {
		player_pos = start_Pos[5];
		fake_pos[0] = start_Pos[0];
		fake_pos[1] = start_Pos[1];
		fake_pos[2] = start_Pos[3];
		fake_pos[3] = start_Pos[4];
		fake_pos[4] = start_Pos[2];
		fake_pos[5] = start_Pos[6];
	}
	if (select == 6) {
		player_pos = start_Pos[6];
		fake_pos[0] = start_Pos[0];
		fake_pos[1] = start_Pos[1];
		fake_pos[2] = start_Pos[3];
		fake_pos[3] = start_Pos[4];
		fake_pos[4] = start_Pos[5];
		fake_pos[5] = start_Pos[2];
	}



	prev_mx = -1;
	prev_my = -1;

	map.Initialize(map_data);
	track.Initialize(map_data);
	sound.Initialize();
	spy.Initialize(map_data, player_pos);
	threatmap.Initialize(map_data);
	decoy.Initialize(fake_pos);

	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < map_data[y].size(); x++) {
			dist[y].push_back(0);
			dist_A[y].push_back(0);
			dist2[y].push_back(0);
			dist3[y].push_back(0);
			dist4[y].push_back(0);
			dist5[y].push_back(0);
			dist6[y].push_back(0);
			dist_player[y].push_back(0);
			dist_AI[y].push_back(0);
		}
	}

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	// TODO: Add your finalization logic here

}



int GameMain::Update()
{



	Player();
	Tracker();
	AI();
	spy_pos = spy.Update();
	tracker_pos = track.Update();
	threatmap.Update(tracker_pos,"TRACKER");
	threatmap.Update(spy_pos, "SPY");
	decoy.Update(threatmap);
	//Fake(fake_pos,k_count,k,direc2,mx_k,my_k,dist2,fake_stop_count[0]);
	//Fake(fake2_pos, j_count, j, direc3, mx_i, my_i, dist_AI, fake_stop_count[1]);
	//Fake(fake3_pos, h_count, h, direc5, mx_h, my_h, dist3, fake_stop_count[2]);
	//Fake(fake4_pos, g_count, g, direc6, mx_g, my_g, dist4, fake_stop_count[3]);
	//Fake(fake5_pos, p_count, p, direc7, mx_p, my_p, dist5, fake_stop_count[4]);
	//Fake(fake6_pos, o_count, o, direc8, mx_o, my_o, dist6, fake_stop_count[5]);




	if (stun_state == true) {
		if (fake_flag = true && tracker_alpha >= 255.0f) {
			fake_flag = false;
		}
		if (fake_flag = false && tracker_alpha <= 0.0f) {
			fake_flag = true;
		}
		if (fake_flag) {
			tracker_alpha += 20;
		}
		else {
			tracker_alpha -= 20;
		}
	}
	else {
		tracker_alpha = 1.0f;
	}

	if (stun_state == true) {
		stun_time += 1.0f;
		if (stun_time >= 120.0f) {

			stun_time = 0.0f;
			stun_state = false;
		}
	}


	if (tracker_state == 0) {
		flame++;
		if (flame == 60) {
			time -= 1;
			flame = 0;
			if (time == 0) {

				tracker_state = 2;
			}
		}
	}

	if (time == 20) {
		auto bgm = sound.GetBGM();
		bgm[sound.MAIN]->Stop();
		bgm[sound.LIMIT]->Play();

	}

	if (time <= 15) {
		a_alpha -= 0.02f;
	}

	if (a_alpha <= 0.0f) {
		a_alpha = 0.0f;
	}

	if (time <= 30) {
		b_alpha -= 0.02f;
	}

	if (b_alpha <= 0.0f) {
		b_alpha = 0.0f;
	}

	if (time == 15) {
		tracker_spd = player_spd * 1.5;
	}

	if (lose_time >= 180) {
		return GAME_SCENE(new clearScene);
	}

	//鬼と逃げる人の当たり判定

	KeyboardBuffer key_buffer = Keyboard->GetBuffer();
	GamePadBuffer pad_1_buffer = GamePad(1)->GetBuffer();

	if (attack_state == 1)
	{
		if (invisible_state == false) {

			if (player_pos.x + 35 < tracker_pos.x + 15 || player_pos.x + 15 > tracker_pos.x + 35 ||
				player_pos.y + 40 < tracker_pos.y + 10 || player_pos.y + 10 > tracker_pos.y + 40)
			{
			}
			else if (time >= 0)
			{
				tracker_state = 1;
				player_state = 1;
			}
		}
	}

	if (win_time >= 180)
	{
		return GAME_SCENE(new resultScene);
	}
	if (tracker_state == 0) {
		anime += 1.0f;
	}
	else {
		anime = 1;
	}
	if (anime >= 40) {
		anime = 0;
	}
	AI_count++;
	return 0;
}


void GameMain::Tracker()
{

	//アニメーション
	if (tracker_state == 1)
	{
		win_flame += 0.8f;
		down_flame += 0.8f;
		win_time++;
	}

	if (lose_flame > 30)
	{
		lose_flame = 0;
	}

	if (win_flame >= 50)
	{
		win_flame = 0;
	}

	if (tracker_state == 2) {
		win_flame += 0.8f;
		lose_flame += 0.5f;
		lose_time++;
	}

	if (skil_time <= 0) {
		skil_time = 0;
	}
}



void GameMain::Player()
{
	KeyboardState  key = Keyboard->GetState();
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();
	GamePadState  pad_2 = GamePad(1)->GetState();
	GamePadBuffer pad_buffer = GamePad(1)->GetBuffer();
	GamePadBuffer pad_buffer2 = GamePad(0)->GetBuffer();


	// パンチ
	if (tracker_state == 0) {
		if (key_buffer.IsPressed(Keys_G) || pad_buffer2.IsPressed(GamePad_Button6))
		{
			attack_state = 1;
		}
	}

	if (attack_state == 1)
	{
		tracker_flame_x += 0.6f;
	}
	if (tracker_flame_x >= 20)
	{
		attack_state = 0;
		tracker_flame_x = 0;
	}


}

//プレイヤーのデコイたちのAI
void GameMain::Fake(Vector3& ai_pos, int& move_count, int& ai_pattern, float& dir, int old_pos_x[], int old_pos_y[], std::vector<float> ai_mapdata[],int& c)
{

	// 鬼とデコイの当たり判定
	if (invisible_state == false) {
		if (attack_state == 1) {
			if (tracker_pos.x + 35 < ai_pos.x + 15 || tracker_pos.x + 15 > ai_pos.x + 35 ||
				tracker_pos.y + 40 < ai_pos.y + 10 || tracker_pos.y + 10 > ai_pos.y + 40) {
			}
			else if (time >= 0) {

				stun_state = true;
			}

		}
	}
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);
	GraphicsDevice.BeginScene();
	SpriteBatch.Begin();
	map.Draw();
	track.Draw();
	spy.Draw();
	//threatmap.Draw();
	decoy.Draw();
	SpriteBatch.End();

	GraphicsDevice.EndScene();
}



