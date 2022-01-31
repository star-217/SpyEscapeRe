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
	constexpr int DECOY_MAX = 6;

	InputDevice.CreateGamePad(PLAYER_MAX);
	DefaultFont = GraphicsDevice.CreateDefaultFont();

	int select = SelectScene::GetSelect();

	std::vector<Vector3> startPos = { Vector3( 150, 400, 0), Vector3( 800, 100, 0),
							Vector3(1250, 150, 0), Vector3( 850, 700, 0),
							Vector3(  50, 750, 0), Vector3(1500, 200, 0),
							Vector3(1500, 500, 0) };
	Vector3 TrackerPos = Vector3(1500, 800, 0);

	_map = std::make_unique<Map>();
	_spy = std::make_unique<Spy>();
	_tracker = std::make_unique<Tracker>();
	_decoy = std::make_unique<DecoyManager>();
	_collision = std::make_unique<Collision>();
	_check_move = std::make_unique<CheckMove>();


	_map->Initialize();

	_tracker->Initialize();
	_tracker->SetPosition(TrackerPos);
	_tracker->SetTag("TRACKER");
	_tracker->SetMapData(_map->GetMapData());

	_spy->Initialize();
	_spy->SetPosition(startPos[select]);
	_spy->SetTag("SPY");
	_spy->SetMapData(_map->GetMapData());

	startPos.erase(startPos.begin() + select);

	_decoy->Initialize(DECOY_MAX);
	_decoy->SetOtherPositionInit(_spy.get());
	_decoy->SetOtherPositionInit(_tracker.get());
	_decoy->SetPosition(startPos);
	_decoy->SetTag("DECOY");
	_decoy->SetMapData(_map->GetMapData());

	_collision->AddListener(_spy->GetTag(), _spy.get());
	_collision->AddListener(_tracker->GetTag(), _tracker.get());
	for (int i = 0; i < _decoy->GetBase().size(); i++) {
		_collision->AddListener(_decoy->GetBase()[i]->GetTag(), _decoy->GetBase()[i]);
		_check_move->AddListener(_decoy->GetBase()[i]);
	}

	_spy->SetCheckMoveClass(_check_move.get());
	_tracker->SetCheckMoveClass(_check_move.get());

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

	_map->Draw();
	_tracker->Draw();
	_spy->Draw();
	_decoy->Draw();

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}



