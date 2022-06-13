/**
 * @file  BlackOut.cpp
 * @brief 画面を暗転させる
 * @author 星寛文
 * @date 2021/04/20
 */
#include "BlackOut.h"
#include <algorithm>


 /**
   * @fn
   * コンストラクタ
   */
BlackOut::BlackOut() :	_black(GraphicsDevice.CreateSpriteFromFile(_T("skill.png"))),
						_position(0.0f, 0.0f, -10.0f)
{
}

/**
  * @fn
  * 更新処理
  */
void BlackOut::Update()
{
	constexpr float alpha_speed = 0.008f;

	_alpha -= alpha_speed;
	_alpha  = std::clamp(_alpha, 0.0f, 255.0f);

}

/**
  * @fn
  * 描画
  */
void BlackOut::Draw()
{
	SpriteBatch.Draw(*_black, _position, _alpha);
}
