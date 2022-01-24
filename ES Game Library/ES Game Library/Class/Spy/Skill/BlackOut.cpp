/**
 * @file  BlackOut.cpp
 * @brief SpyÇÃÉXÉLÉãâÊñ Çà√ì]Ç≥ÇπÇÈ
 * @author êØä∞ï∂
 * @date 2021/04/20
 */
#include "BlackOut.h"
#include <algorithm>

BlackOut::BlackOut() :	_black(GraphicsDevice.CreateSpriteFromFile(_T("skill.png"))),
						_alpha(255.0f), _position(0.0f, 0.0f, -10.0f)
{
}

float BlackOut::Update()
{
	constexpr float alpha_speed = 0.008f;

	_alpha -= alpha_speed;
	_alpha  = std::clamp(_alpha, 0.0f, 255.0f);

	return _alpha;
}

void BlackOut::Draw()
{
	SpriteBatch.Draw(*_black, _position, _alpha);
}
