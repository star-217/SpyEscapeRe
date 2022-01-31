#include "SpyLoseState.h"

/**
  * @fn
  * 初期化
  */
void SpyLoseState::Initialize(TCHAR* file_name)
{
	_sprite = GraphicsDevice.CreateSpriteFromFile(file_name);
}

/**
  * @fn
  * 更新処理
  */
void SpyLoseState::Update()
{
	constexpr float flame_speed = 0.8f;
	constexpr int max_flame = 30;

	_flame += flame_speed;
	_flame = max(_flame, max_flame);
}

/**
  * @fn
  * 描画
  * @param (pos) Spyの座標
  * @param (dir) Spyの向いてる方向
  * @param (alpha) 透明化スキルを使ったときのアルファ値
  */
void SpyLoseState::Draw(Vector3& pos, int& dir, float alpha)
{
	SpriteBatch.Draw(*_sprite, pos, RectWH(CHARA_SIZE.x * (int)_flame, 0, CHARA_SIZE.x, CHARA_SIZE.y));
}
