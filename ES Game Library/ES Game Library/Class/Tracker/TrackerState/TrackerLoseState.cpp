#include "TrackerLoseState.h"

/**
  * @fn
  * 初期化
  */
void TrackerLoseState::Initialize(TCHAR* file_name)
{
	_sprite = GraphicsDevice.CreateSpriteFromFile(file_name);
}

/**
  * @fn
  * 更新処理
  */
void TrackerLoseState::Update()
{
	constexpr int flame_speed = 0.8f;
	constexpr int flame_max = 30.0f;

	_flame += flame_speed;
	_flame = max(_flame, flame_max);
}

/**
  * @fn
  * 描画
  * @param (pos) 鬼のポジション
  * @param (dir) 向いている方向
  */
void TrackerLoseState::Draw(Vector3& pos, int& dir)
{
	SpriteBatch.Draw(
		*_sprite, Vector3(pos.x, pos.y - FIX_POS_Y, pos.z),
		RectWH(CHARA_SIZE.x * _flame, CHARA_SIZE.y, CHARA_SIZE.x, CHARA_SIZE.y)
	);
}
