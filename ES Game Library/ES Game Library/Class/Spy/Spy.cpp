#include "Spy.h"

void Spy::Initialize(const std::vector<cstring> data, const Vector3 pos)
{
	spy = GraphicsDevice.CreateSpriteFromFile(_T("spy.png"));

	spy_pos = pos;
	map_data = data;
	direction = 0;
	pad_direction = 0;
	chara_size = 50;
	player_count = 0;
	animetion_flame = 0;
	invisible_alpha = 1.0f;
	animetion_flame_max = 40;
	move.Initialize();
}

Vector3 Spy::Update()
{
	KeyboardBuffer key = Keyboard->GetBuffer();
	spy_pos = move.Move(spy_pos,map_data,5,0);
	direction = move.GetDirection();
	Animetion();
	skill.Update();

	if (key.IsPressed(Keys_Enter)) {
		skill.RandomSkil();
	}
		auto a = 1;


	return spy_pos;
}

void Spy::Draw()
{

	skill.Draw();
	SpriteBatch.Draw(*spy, Vector3(spy_pos.x, spy_pos.y - 20, 0.0f), RectWH(50 * (int)animetion_flame, direction * 70, 50, 70), invisible_alpha);
}

void Spy::Animetion()
{
	animetion_flame++;
	animetion_flame = (int)animetion_flame % (int)animetion_flame_max;
}
