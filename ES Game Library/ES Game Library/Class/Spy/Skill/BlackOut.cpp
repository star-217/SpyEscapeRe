/**
 * @file  BlackOut.cpp
 * @brief ��ʂ��Ó]������
 * @author ������
 * @date 2021/04/20
 */
#include "BlackOut.h"
#include <algorithm>


 /**
   * @fn
   * �R���X�g���N�^
   */
BlackOut::BlackOut() :	_black(GraphicsDevice.CreateSpriteFromFile(_T("skill.png"))),
						_position(0.0f, 0.0f, -10.0f)
{
}

/**
  * @fn
  * �X�V����
  */
void BlackOut::Update()
{
	constexpr float alpha_speed = 0.008f;

	_alpha -= alpha_speed;
	_alpha  = std::clamp(_alpha, 0.0f, 255.0f);

}

/**
  * @fn
  * �`��
  */
void BlackOut::Draw()
{
	SpriteBatch.Draw(*_black, _position, _alpha);
}
