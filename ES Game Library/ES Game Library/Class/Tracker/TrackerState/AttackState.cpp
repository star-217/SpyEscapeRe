#include "AttackState.h"

/**
  * @fn
  * 初期化
  */
void AttackState::Initialize(TCHAR* file_name)
{
	_sprite = GraphicsDevice.CreateSpriteFromFile(file_name);
}

/**
  * @fn
  * 更新処理
  */
void AttackState::Update()
{
	constexpr int flame_speed = 1.0f;
	constexpr int flame_max = 50.0f;

	_flame += flame_speed;
	if (_flame > flame_max)
	{
		_flame = 0.0f;
		_flag = true;
	}
}

/**
  * @fn
  * 描画
  * @param (pos) 鬼のポジション
  * @param (dir) 向いている方向
  */
void AttackState::Draw(Vector3& pos, int& dir)
{
	SpriteBatch.Draw(
		*_sprite, Vector3(pos.x, pos.y - FIX_POS_Y, pos.z),
		RectWH(CHARA_SIZE.x * _flame, CHARA_SIZE.y * (dir - 1), CHARA_SIZE.x, CHARA_SIZE.y)
	);
}
