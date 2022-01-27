/**
 * @file  Decoy.cpp
 * @brief デコイ(NPC)クラス
 * @author 星寛文
 * @date 2022/01/27
 */

#include "Decoy.h"

Decoy::Decoy()
{
}

void Decoy::Initialize()
{
	_threatmap = new ThreatMap();
	_threatmap->Initialize();

	_decoy = GraphicsDevice.CreateSpriteFromFile(_T("spy.png"));

	_pos = Vector3_Zero;
	_old_pos.assign(PREV_MAX, Vector2_Zero);
	_move_pattern = Direction::None;

	_animetion_flame = 0;
	_sprite_direction = 0;
	_move_count = 50; //50ドット単位のブロック
	_tag = "DECOY";

}

void Decoy::Update()
{
	constexpr float BLOCK_SIZE = 50.0f;
	
	_threatmap->Update();
	//脅威マップを1ブロック単位で更新
	if (_move_count >= BLOCK_SIZE) {
		_threat_data = _threatmap->CreateTheatData(_ratio, _old_pos);
	}

	Move();
	_collision = Rect(_pos.x, _pos.y, _pos.x + CHARA_SIZE.x, _pos.y + CHARA_SIZE.y);
	Animetion();

}

void Decoy::Draw()
{
	SpriteBatch.Draw(*_decoy,Vector3(_pos.x, _pos.y - _fix_positon_y, _pos.z),
					RectWH(CHARA_SIZE.x * _animetion_flame, CHARA_SIZE.y * _sprite_direction, CHARA_SIZE.x, CHARA_SIZE.y));
}

/**
 * @fn
 * 脅威マップで使用するPositionデータを更新する
 * @param (human) 動いたクラス
 */
void Decoy::DoMove(HumanBase* human)
{
	_threatmap->SetPosData(human);
}

/**
 * @fn
 * デコイの移動プログラム
 * @detail 一ブロック動くたびに脅威マップをもとに数値が大きいほうに移動する
 */
void Decoy::Move()
{
	constexpr float BLOCK_SIZE = 50.0f;
	if (_move_count >= BLOCK_SIZE) {
		const int MX = (int)(_pos.x / BLOCK_SIZE);
		const int MY = (int)(_pos.y / BLOCK_SIZE);

		//今いる場所から全ての方向のブロックにある最大値を調べ方向を決める
		float max = 0;
		_move_pattern = Direction::None;
		auto isCheck = [&](int my, int mx, Direction dir)
		{
			if (_threat_data[MY + my][MX + mx] > max) {
				_move_pattern = dir;
				return _threat_data[MY + my][MX + mx];
			}
			return max;
		};
		max = isCheck(-1, 0, Direction::Up);
		max = isCheck(1 , 0, Direction::Down);
		max = isCheck(0 , 1, Direction::Right);
		max = isCheck(0 ,-1, Direction::Left);

		// 過去の座標を保存する
		if (_move_pattern != Direction::None) {
			for (int i = PREV_MAX - 1 ; i > 0; i--) {
				_old_pos[i].x = _old_pos[i - 1].x;
				_old_pos[i].y = _old_pos[i - 1].y;
			}
			_old_pos[0].x = MX;
			_old_pos[0].y = MY;
			_move_count = 0;
		}
	}

	//移動処理
	if (_move_pattern > Direction::None) {
		_pos += _move_direction[(int)_move_pattern - 1] * SPEED;
		FixDirection();
	}
	_move_count += SPEED;
}

/**
 * @fn
 * 連番画像を動かす
 */
void Decoy::Animetion()
{
	constexpr int MAX_FLAME = 40;

	_animetion_flame++;
	_animetion_flame = (int)_animetion_flame % MAX_FLAME;
}

/**
 * @fn
 * キャラクターの画像と動きのパターンに違いがあるため修正するためのプログラム
 */
void Decoy::FixDirection()
{
	switch (_move_pattern)
	{
	case Direction::Right:	_sprite_direction = 0; break;
	case Direction::Up:		_sprite_direction = 1; break;
	case Direction::Left:	_sprite_direction = 2; break;
	case Direction::Down:	_sprite_direction = 3; break;
	default:									   break;
	}
}


