#include "DefaultState.h"

DefaultState::DefaultState()
{
}

/**
  * @fn
  * ������
  */
void DefaultState::Initialize(TCHAR* file_name)
{
	_sprite = GraphicsDevice.CreateSpriteFromFile(file_name);
}

/**
  * @fn
  * �X�V����
  */
void DefaultState::Update()
{
	constexpr int max_flame = 40;

	_flame = int(_flame + 1) % max_flame;
}

/**
  * @fn
  * �`��
  * @param (pos) �S�̃|�W�V����
  * @param (dir) �����Ă������
  */
void DefaultState::Draw(Vector3& pos, int& dir)
{
	SpriteBatch.Draw(
		*_sprite, Vector3(pos.x, pos.y - FIX_POS_Y, pos.z),
		RectWH(CHARA_SIZE.x * _flame, CHARA_SIZE.y, CHARA_SIZE.x, CHARA_SIZE.y)
	);
}
