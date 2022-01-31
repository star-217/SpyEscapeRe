#include "SpyDefaultState.h"

/**
  * @fn
  * ������
  */
void SpyDefaultState::Initialize(TCHAR* file_name)
{
	_sprite = GraphicsDevice.CreateSpriteFromFile(file_name);
}

/**
  * @fn
  * �X�V����
  */
void SpyDefaultState::Update()
{
	constexpr int animetion_flame_max = 40;

	_flame = int(_flame + 1) % animetion_flame_max;
}

/**
  * @fn
  * �`��
  * @param (pos) Spy�̍��W
  * @param (dir) Spy�̌����Ă����
  * @param (alpha) �������X�L�����g�����Ƃ��̃A���t�@�l
  */
void SpyDefaultState::Draw(Vector3& pos, int& dir, float alpha)
{
	SpriteBatch.Draw(*_sprite, pos, RectWH(CHARA_SIZE.x * (int)_flame, dir * CHARA_SIZE.y, CHARA_SIZE.x, CHARA_SIZE.y), alpha);
}
