#include "BlackOut.h"
#include <algorithm>

BlackOut::BlackOut() :	_black(GraphicsDevice.CreateSpriteFromFile(_T("skill.png"))),
						_alpha(255.0f),_position(0.0f,0.0f,-10.0f)
{
}

float BlackOut::Update()
{
	float alpha_speed = 0.008f;

	_alpha -= alpha_speed;
	_alpha = std::clamp(_alpha, 0.0f, 255.0f);

	return _alpha;
}

void BlackOut::Draw()
{
	SpriteBatch.Draw(*_black, _position, _alpha);
}
