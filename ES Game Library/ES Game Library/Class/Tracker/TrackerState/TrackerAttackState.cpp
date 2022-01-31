#include "TrackerAttackState.h"

/**
  * @fn
  * ������
  */
void TrackerAttackState::Initialize(TCHAR* file_name)
{
	_sprite = GraphicsDevice.CreateSpriteFromFile(file_name);
}

/**
  * @fn
  * �X�V����
  */
void TrackerAttackState::Update()
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
  * �`��
  * @param (pos) �S�̃|�W�V����
  * @param (dir) �����Ă������
  */
void TrackerAttackState::Draw(Vector3& pos, int& dir)
{
	SpriteBatch.Draw(
		*_sprite, Vector3(pos.x, pos.y - FIX_POS_Y, pos.z),
		RectWH(CHARA_SIZE.x * _flame, CHARA_SIZE.y * (dir - 1), CHARA_SIZE.x, CHARA_SIZE.y)
	);
}
