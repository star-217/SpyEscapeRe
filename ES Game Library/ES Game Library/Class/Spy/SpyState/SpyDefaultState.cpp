#include "SpyDefaultState.h"

/**
  * @fn
  * 初期化
  */
void SpyDefaultState::Initialize(TCHAR* file_name)
{
	_sprite = GraphicsDevice.CreateSpriteFromFile(file_name);
}

/**
  * @fn
  * 更新処理
  */
void SpyDefaultState::Update()
{
	constexpr int animetion_flame_max = 40;

	_flame = int(_flame + 1) % animetion_flame_max;
}

/**
  * @fn
  * 描画
  * @param (pos) Spyの座標
  * @param (dir) Spyの向いてる方向
  * @param (alpha) 透明化スキルを使ったときのアルファ値
  */
void SpyDefaultState::Draw(Vector3& pos, int& dir, float alpha)
{
	SpriteBatch.Draw(*_sprite, pos, RectWH(CHARA_SIZE.x * (int)_flame, dir * CHARA_SIZE.y, CHARA_SIZE.x, CHARA_SIZE.y), alpha);
}
