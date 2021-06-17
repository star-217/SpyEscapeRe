#include "BlackOut.h"
#include <algorithm>

BlackOut::BlackOut() :	black(GraphicsDevice.CreateSpriteFromFile(_T("skill.png"))),
						alpha(255.0f),position(0.0f,0.0f,-10.0f)
{
}

float BlackOut::Update()
{
	alpha -= 0.008f;
	alpha = std::clamp(alpha, 0.0f, 255.0f);

	return 1.0f;
}

void BlackOut::Draw()
{
	SpriteBatch.Draw(*black, position, alpha);
}
