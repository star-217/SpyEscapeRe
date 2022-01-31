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
			_direction(0),_player_count(0),_invisible_alpha(0)
{

}
 /**
   * @fn
   * 初期化
   */
void Spy::Initialize()
{

	//アルファ値なので初期は１
	_invisible_alpha = 1.0f;

	_state = std::make_unique<SpyState>();
	_move = std::make_unique<Move>();
	_skill = std::make_unique<SkillState>();

	_state->Initialize();
	_move->Initialize();

}

/**
  * @fnh
  * 更新処理
  */
void Spy::Update()
{
	KeyboardBuffer key	= Keyboard->GetBuffer();

	_pos			    = _move->MovePostion(_pos,CHARA_SPEED,0);
	_skill->Update();
	_state->Update();
	_invisible_alpha	= _skill->GetAlpha();
	_direction			= (int)_move->GetDirection();
	_collision			= Rect(_pos.x, _pos.y, _pos.x + CHARA_SIZE.x, _pos.y + CHARA_SIZE.y);

	//移動が完了したらCheckMoveクラスに通知する
	if (_move->GetMoveCmp())
	{
		_check_move->Notify(this);
	}

	//スキル使用
	if (key.IsPressed(Keys_Enter))
	{
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
	_state->Draw(_draw_spy_pos,_direction,_invisible_alpha);
}

/**
  * @fn
  * 当たった時の処理
  * @param (tag) 当たった相手のタグ
  */
void Spy::OnCollisionEnter(std::string tag)
{
	if (tag == "TRACKER")
		_state->ChangeState(SpyState::State::Lose);

}
