#include "BlackOut.h"
#include <algorithm>

BlackOut::BlackOut() :	_black(GraphicsDevice.CreateSpriteFromFile(_T("skill.png"))),
						_alpha(255.0f),_position(0.0f,0.0f,-10.0f)
{
}

float BlackOut::Update()
{
	_alpha -= 0.008f;
	_alpha = std::clamp(_alpha, 0.0f, 255.0f);

	return 1.0f;
}

void BlackOut::Draw()
{
	SpriteBatch.Draw(*_black, _position, _alpha);
}
