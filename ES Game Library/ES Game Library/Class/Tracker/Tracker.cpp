/**
 * @file  Tracker.h
 * @brief 鬼側のクラス
 * @author 星寛文
 * @date 2021/04/20
 */
#include "Tracker.h"
#include "../Base/CheckMove/CheckMove.h"

 /**
   * @fn
   * コンストラクタ
   */
Tracker::Tracker() :_stun_time(0.0f),_stun_flag(false),
					_move(nullptr),_ctracker_state(nullptr),
					_tracker_state(TrackerState::State::Default),_old_tracker_state(TrackerState::State::Default),
					_direc(Direction::None)
{

}

/**
  * @fn
  * 初期化
  */
void Tracker::Initialize()
{
	//攻撃時以外当たらないように画面外へ
	_collision = Rect(-1,-1,-1,-1);

	_direc			 = Direction::Down;

	_move = std::make_unique<Move>();
	_ctracker_state = std::make_unique<TrackerState>();

	_move->Initialize();
	_ctracker_state->Initialize();

}

/**
  * @fn
  * 更新処理
  */
void Tracker::Update()
{
	KeyboardBuffer key = Keyboard->GetBuffer();
	_pos = _move->MovePostion(_pos, CHARA_SPEED,1);
	_direc = _move->GetDirection();
	MoveCollision();

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

	if(_tracker_state != _old_tracker_state)
	{
		_ctracker_state->ChangeState(_tracker_state);
	}
	_ctracker_state->Update();
	if (_ctracker_state->GetAnimetionFinish())
	{
		_tracker_state = TrackerState::State::Default;
	}

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
	if (_tracker_state == TrackerState::State::Attack)
	{
		_collision = Rect(_pos.x, _pos.y, _pos.x + CHARA_SIZE.x, _pos.y + CHARA_SIZE.y);
	}
	else
	{
		//攻撃していないときは画面外に
		_collision = Rect(-1,-1,-1,-1);
	}
}

/**
  * @fn
  * 当たった時の処理
  * @param (tag) 当たった相手のタグ
  */
void Tracker::OnCollisionEnter(std::string tag)
{
	if (tag == "DECOY")
	{
		_stun_flag = true;
	}

	if (tag == "SPY")
	{
		_ctracker_state->ChangeState(TrackerState::State::Win);
	}
}

