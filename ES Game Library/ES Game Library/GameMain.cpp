// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"
#include "GameScene/SelectScene.hpp"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));

	constexpr int PLAYER_MAX = 2;
	InputDevice.CreateGamePad(PLAYER_MAX);
	DefaultFont = GraphicsDevice.CreateDefaultFont();

	int select = SelectScene::GetSelect();

	Vector3 start_Pos[] = { Vector3( 150, 400, 0), Vector3( 800, 100, 0),
							Vector3(1250, 150, 0), Vector3( 850, 700, 0),
							Vector3(  50, 750, 0), Vector3(1500, 200, 0),
							Vector3(1500, 500, 0) };

	//選択シーンでの選択によっての分岐
	if (select == 0) {
		_spy_pos     = start_Pos[0];
		_fake_pos[0] = start_Pos[1];
		_fake_pos[1] = start_Pos[2];
		_fake_pos[2] = start_Pos[3];
		_fake_pos[3] = start_Pos[4];
		_fake_pos[4] = start_Pos[5];
		_fake_pos[5] = start_Pos[6];
	}
	if (select == 1) {
		_spy_pos     = start_Pos[1];
		_fake_pos[0] = start_Pos[2];
		_fake_pos[1] = start_Pos[0];
		_fake_pos[2] = start_Pos[3];
		_fake_pos[3] = start_Pos[4];
		_fake_pos[4] = start_Pos[5];
		_fake_pos[5] = start_Pos[6];
	}
	if (select == 2) {
		_spy_pos = start_Pos[2];
		_fake_pos[0] = start_Pos[0];
		_fake_pos[1] = start_Pos[1];
		_fake_pos[2] = start_Pos[3];
		_fake_pos[3] = start_Pos[4];
		_fake_pos[4] = start_Pos[5];
		_fake_pos[5] = start_Pos[6];
	}
	if (select == 3) {
		_spy_pos = start_Pos[3];
		_fake_pos[0] = start_Pos[0];
		_fake_pos[1] = start_Pos[1];
		_fake_pos[2] = start_Pos[2];
		_fake_pos[3] = start_Pos[4];
		_fake_pos[4] = start_Pos[5];
		_fake_pos[5] = start_Pos[6];
	}
	if (select == 4) {
		_spy_pos = start_Pos[4];
		_fake_pos[0] = start_Pos[0];
		_fake_pos[1] = start_Pos[1];
		_fake_pos[2] = start_Pos[3];
		_fake_pos[3] = start_Pos[2];
		_fake_pos[4] = start_Pos[5];
		_fake_pos[5] = start_Pos[6];
	}
	if (select == 5) {
		_spy_pos = start_Pos[5];
		_fake_pos[0] = start_Pos[0];
		_fake_pos[1] = start_Pos[1];
		_fake_pos[2] = start_Pos[3];
		_fake_pos[3] = start_Pos[4];
		_fake_pos[4] = start_Pos[2];
		_fake_pos[5] = start_Pos[6];
	}
	if (select == 6) {
		_spy_pos = start_Pos[6];
		_fake_pos[0] = start_Pos[0];
		_fake_pos[1] = start_Pos[1];
		_fake_pos[2] = start_Pos[3];
		_fake_pos[3] = start_Pos[4];
		_fake_pos[4] = start_Pos[5];
		_fake_pos[5] = start_Pos[2];
	}
	_spy = new Spy();
	_tracker = new Tracker();
	_decoy = new DecoyManager();
	_collision = new Collision();

	Map::GetInstance().Initialize();

	_tracker->Initialize();

	_spy->Initialize();
	_spy->SetStartPos(_spy_pos);

	auto a = _spy->GetPosition();

	_decoy->Initialize();
	_decoy->SetSpy(_spy);
	_decoy->SetTracker(_tracker);

	_collision->AddListener(_spy->GetTag(), _spy);
	_collision->AddListener(_tracker->GetTag(), _tracker);
	for (int i = 0; i < _decoy->GetBase().size(); i++) {
		_collision->AddListener(_decoy->GetBase()[i]->GetTag(), _decoy->GetBase()[i]);
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

	_spy->Update();
	_tracker->Update();
	_decoy->SetSpy(_spy);
	_decoy->SetTracker(_tracker);
	_decoy->Update();
	_collision->CheckCollision("SPY","TRACKER");
	_collision->CheckCollision("DECOY", "TRACKER");

	return 0;
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
	Map::GetInstance().Draw();
	_tracker->Draw();
	_spy->Draw();
	_decoy->Draw();
	SpriteBatch.End();

	GraphicsDevice.EndScene();
}



