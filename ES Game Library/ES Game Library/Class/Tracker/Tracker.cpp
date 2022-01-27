/**
 * @file  Tracker.h
 * @brief 鬼側のクラス
 * @author 星寛文
 * @date 2021/04/20
 */
#include "Tracker.h"

Tracker::Tracker() :_collision(Rect(0,0,0,0)),_tracker_spd(0.0f),_stun_time(0.0f),_tracker_flame_x(0.0f),
					_win_flame(0.0f),_lose_flame(0.0f),_attack_flame(0.0f),_stun_flag(false)
{

}

/**
  * @fn
  * 初期化
  */
void Tracker::Initialize()
{
	_pos = Vector3(1500, 800, 0);
	_tracker_state = TrackerState::State::Default;

	_tracker_spd     = 5.0f;
	_tracker_flame_x = 0;
	_stun_time		 = 0;
	_win_flame		 = 0;
	_lose_flame		 = 0;
	_attack_flame	 = 0;
	_collision = Rect(_pos.x, _pos.y, _pos.x + CHARA_SIZE.x, _pos.y + CHARA_SIZE.y);


	_direc			 = Direction::Down;
	_stun_flag		 = false;
	_tag = "TRACKER";

	_move = new Move();
	_move->Initialize();

	_ctracker_state = new TrackerState();
	_ctracker_state->Initialize();


}

/**
  * @fn
  * 更新処理
  */
void Tracker::Update()
{
	KeyboardBuffer key = Keyboard->GetBuffer();
	_pos = _move->MovePostion(_pos,_tracker_spd,1);
	_direc = _move->GetDirection();
	
	//移動が完了したらCheckMoveクラスに通知する
	if (_move->GetMoveCmp())
	{
		_check_move->Notify(this);
	}

	if (_stun_flag)
	{
		StunTime();
	}

	if (key.IsPressed(Keys_A))
	{
		_tracker_state = TrackerState::State::Attack;
	}

	MoveCollision();

	if(_tracker_state != _old_tracker_state)
	{
		_ctracker_state->ChangeState(_tracker_state);
	}
	_ctracker_state->Update();

	_old_tracker_state = _tracker_state;
}

/**
  * @fn
  * 描画
  */
void Tracker::Draw()
{
	_ctracker_state->Draw(_pos, (int)_direc);
}


/**
  * @fn
  * デコイを攻撃したときのスタン処理
  */
void Tracker::StunTime()
{
	constexpr float max_time = 120.0f;

	_stun_time++;
	if (_stun_time > max_time)
	{
		_stun_flag = false;
	}
}

/**
  * @fn
  * 攻撃したときの当たり判定の変更
  */
void Tracker::MoveCollision()
{
	if()
	_collision = Rect(_pos.x, _pos.y, _pos.x + CHARA_SIZE.x, _pos.y + CHARA_SIZE.y);
}

/**
  * @fn
  * 当たった時の処理
  * @param (tag) 当たった相手のタグ
  */
void Tracker::OnCollisionEnter(std::string tag)
{
	if(tag == "DECOY")
		_stun_flag = true;
}

