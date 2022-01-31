#include "SpyLoseState.h"

/**
  * @fn
  * ������
  */
void SpyLoseState::Initialize(TCHAR* file_name)
{
	_sprite = GraphicsDevice.CreateSpriteFromFile(file_name);
}

/**
  * @fn
  * �X�V����
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
  * �`��
  * @param (pos) Spy�̍��W
  * @param (dir) Spy�̌����Ă����
  * @param (alpha) �������X�L�����g�����Ƃ��̃A���t�@�l
  */
void SpyLoseState::Draw(Vector3& pos, int& dir, float alpha)
{
	SpriteBatch.Draw(*_sprite, pos, RectWH(CHARA_SIZE.x * (int)_flame, 0, CHARA_SIZE.x, CHARA_SIZE.y));
}
