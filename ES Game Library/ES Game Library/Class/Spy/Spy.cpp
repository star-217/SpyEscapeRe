#include "Spy.h"

void Spy::Initialize(const std::vector<cstring> data, const Vector3 pos)
{
	spy = GraphicsDevice.CreateSpriteFromFile(_T("spy.png"));
	attack = GraphicsDevice.CreateSpriteFromFile(_T("punch.png"));
	win = GraphicsDevice.CreateSpriteFromFile(_T("playerwin.png"));
	lose = GraphicsDevice.CreateSpriteFromFile(_T("playerdown.png"));

	spy_pos = pos;
	map_data = data;
	direction = 0;
	pad_direction = 0;
	chara_size = 50;
	player_count = 0;

	animetion_flame = 0;
	win_flame = 0;
	lose_flame = 0;

	animetion_flame_max = 40;

	invisible_alpha = 1.0f;
	move.Initialize();

}

Vector3 Spy::Update()
{
	KeyboardBuffer key = Keyboard->GetBuffer();
	spy_pos = move.Move(spy_pos,map_data,5,0);
	invisible_alpha = skill.Update();
	direction = move.GetDirection();

	collision = Rect(spy_pos.x, spy_pos.y, spy_pos.x + 50, spy_pos.y +70);

	Animetion();

	if (key.IsPressed(Keys_Enter)) {
		skill.RandomSkil();
	}
	auto a = 1;


	return spy_pos;
}

void Spy::Draw()
{

	draw_spy_pos = Vector3(spy_pos.x, spy_pos.y - 20, 0.0f);

	skill.Draw();
	switch (state) {
	case DEFAULT:
		SpriteBatch.Draw(*spy, draw_spy_pos, RectWH(50 * (int)animetion_flame, direction * 70, 50, 70), invisible_alpha); break;
	case WIN:
		SpriteBatch.Draw(*win, draw_spy_pos, RectWH(50 * (int)win_flame, 0, 50, 70)); break;
	case LOSE:
		SpriteBatch.Draw(*lose, draw_spy_pos, RectWH(50 * (int)lose_flame, 0, 50, 70)); break;
	}

}

void Spy::Animetion()
{
	animetion_flame++;
	animetion_flame = (int)animetion_flame % (int)animetion_flame_max;
}


void Spy::WinAnimetion()
{
	win_flame += 0.8f;
	win_flame = max(win_flame, 50);

}

void Spy::LoseAnimetion()
{
	lose_flame += 0.8f;
	lose_flame = max(lose_flame, 30);

}

void Spy::AttackHit()
{
}
