#include "DefaultState.h"

DefaultState::DefaultState()
{
}

/**
  * @fn
  * 初期化
  */
void DefaultState::Initialize(TCHAR* file_name)
{
	_sprite = GraphicsDevice.CreateSpriteFromFile(file_name);
}

/**
  * @fn
  * 更新処理
  */
void DefaultState::Update()
{
	constexpr int max_flame = 40;

	_flame = int(_flame + 1) % max_flame;
}

/**
  * @fn
  * 描画
  * @param (pos) 鬼のポジション
  * @param (dir) 向いている方向
  */
void DefaultState::Draw(Vector3& pos, int& dir)
{
	SpriteBatch.Draw(
		*_sprite, Vector3(pos.x, pos.y - FIX_POS_Y, pos.z),
		RectWH(CHARA_SIZE.x * _flame, CHARA_SIZE.y, CHARA_SIZE.x, CHARA_SIZE.y)
	);
}
