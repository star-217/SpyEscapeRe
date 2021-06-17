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




	map.Initialize(map_data);
	track.Initialize(map_data);
	sound.Initialize();
	spy.Initialize(map_data, player_pos);
	threatmap.Initialize(map_data);
	decoy.Initialize(fake_pos);

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



	spy_pos = spy.Update();
	tracker_pos = track.Update();
	threatmap.Update(tracker_pos,"TRACKER");
	threatmap.Update(spy_pos, "SPY");
	decoy.Update(threatmap);




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

	//KeyboardBuffer key_buffer = Keyboard->GetBuffer();
	//GamePadBuffer pad_1_buffer = GamePad(1)->GetBuffer();

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
	decoy.Draw();
	SpriteBatch.End();

	GraphicsDevice.EndScene();
}



