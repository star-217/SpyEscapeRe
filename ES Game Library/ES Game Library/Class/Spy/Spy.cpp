/**
 * @file  Spy.cpp
 * @brief 逃げる側のクラス
 * @author 星寛文
 * @date 2021/04/20
 */
#include "Spy.h"
#include "../Base/CheckMove/CheckMove.h"

 /**
   * @fn
   * コンストラクタ
   */
Spy::Spy() : _move(nullptr),_skill(nullptr),
			_spy(0),_win(0),_lose(0),_state(SpyState::Default),
			_direction(0),_player_count(0),_animetion_flame(0),
			_win_flame(0),_lose_flame(0),_invisible_alpha(0)
{

}
 /**
   * @fn
   * 初期化
   */
void Spy::Initialize()
{
	_spy = GraphicsDevice.CreateSpriteFromFile(_T("spy.png"));
	_win = GraphicsDevice.CreateSpriteFromFile(_T("playerwin.png"));
	_lose = GraphicsDevice.CreateSpriteFromFile(_T("playerdown.png"));

	//アルファ値なので初期は１
	_invisible_alpha = 1.0f;

	_move = new Move();
	_move->Initialize();

	_skill = new SkillState();

}

/**
  * @fn
  * 更新処理
  */
void Spy::Update()
{
	KeyboardBuffer key	= Keyboard->GetBuffer();

	_pos			    = _move->MovePostion(_pos,CHARA_SPEED,0);
	_skill->Update();
	_invisible_alpha = _skill->GetAlpfa();
	_direction			= (int)_move->GetDirection();
	_collision			= Rect(_pos.x, _pos.y, _pos.x + CHARA_SIZE.x, _pos.y + CHARA_SIZE.y);

	//移動が完了したらCheckMoveクラスに通知する
	if (_move->GetMoveCmp())
	{
		_check_move->Notify(this);
	}

	Animetion();

	//スキル使用
	if (key.IsPressed(Keys_Enter)) {
		_skill->RandomSkill();
	}
}

/**
  * @fn
  * 描画
  */
void Spy::Draw()
{

	const Vector3 _draw_spy_pos = Vector3(_pos.x, _pos.y - FIX_POS_Y, 0.0f);

	_skill->Draw();
	switch (_state) {
	case SpyState::Default:
		SpriteBatch.Draw(*_spy, _draw_spy_pos, RectWH(CHARA_SIZE.x * (int)_animetion_flame, _direction * CHARA_SIZE.y, CHARA_SIZE.x, CHARA_SIZE.y), _invisible_alpha);
		break;
	case SpyState::Win:
		SpriteBatch.Draw(*_win, _draw_spy_pos, RectWH(CHARA_SIZE.x * (int)_win_flame, 0, CHARA_SIZE.x, CHARA_SIZE.y));
		break;
	case SpyState::Lose:
		SpriteBatch.Draw(*_lose, _draw_spy_pos, RectWH(CHARA_SIZE.x * (int)_lose_flame, 0, CHARA_SIZE.x, CHARA_SIZE.y));
		break;
	}
}

/**
  * @fn
  * (通常)連番画像アニメーション
  */
void Spy::Animetion()
{
	constexpr int animetion_flame_max = 40;

	_animetion_flame = int(_animetion_flame + 1) % animetion_flame_max;
}

/**
  * @fn
  * (勝利時)連番画像アニメーション
  */
void Spy::WinAnimetion()
{
	constexpr float flame_speed	= 0.8f;
	constexpr int max_flame		= 50;

	_win_flame += flame_speed;
	_win_flame = max(_win_flame, max_flame);

}

/**
  * @fn
  * (敗北時)連番画像アニメーション
  */
void Spy::LoseAnimetion()
{
	constexpr float flame_speed	= 0.8f;
	constexpr int max_flame		= 30;

	_lose_flame += flame_speed;
	_lose_flame = max(_lose_flame, max_flame);

}

/**
  * @fn
  * 当たった時の処理
  * @param (tag) 当たった相手のタグ
  */
void Spy::OnCollisionEnter(std::string tag)
{
	if(tag == "TRACKER")
		_state = SpyState::Lose;
}
