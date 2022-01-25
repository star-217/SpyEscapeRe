#include "Decoy.h"

Decoy::Decoy()
{
}

void Decoy::Initialize()
{
	_threatmap = new ThreatMap();
	_threatmap->Initialize();
	_threatmap->SetSpyPosData(_spy_pos);
	_threatmap->SetTrackerPosData(_tracker_pos);

	DefaultFont = GraphicsDevice.CreateDefaultFont();
	_decoy = GraphicsDevice.CreateSpriteFromFile(_T("spy.png"));

	_pos = Vector3_Zero;
	_old_pos.assign(PREV_MAX, Vector2_Zero);
	_animetion_flame = 0;
	_sprite_direction = 0;
	_move_count = 50; //50ドット単位のブロック
	_flame = 3600;
	_tag = "DECOY";

}

void Decoy::Update()
{
	constexpr float block_size = 50.0f;
	
	_threatmap->SetSpyPosData(_spy_pos);
	_threatmap->SetTrackerPosData(_tracker_pos);
	_threatmap->Update();
	if (_move_count >= block_size) {
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
 * デコイの移動プログラムです。
 * @detail 一ブロック動くたびに脅威マップをもとに数値が大きいほうに移動するようにしたプログラムです。
 */
void Decoy::Move()
{
	constexpr float block_size = 50.0f;
	if (_move_count >= block_size) {
		//キャラの場所のブロック分け
		const int mx = (int)(_pos.x / block_size);
		const int my = (int)(_pos.y / block_size);

		float max = 0;
		_move_pattern = Direction::None;
		//今いる場所から全ての方向のブロックにある値を調べ高い方へ移動する
		if (_threat_data[my - 1][mx] > max) {
			max = _threat_data[my - 1][mx];
			_move_pattern = Direction::Up;
		}
		if (_threat_data[my + 1][mx] > max) {
			max = _threat_data[my + 1][mx];
			_move_pattern = Direction::Down;
		}
		if (_threat_data[my][mx + 1] > max) {
			max = _threat_data[my][mx + 1];
			_move_pattern = Direction::Right;
		}
		if (_threat_data[my][mx - 1] > max) {
			max = _threat_data[my][mx - 1];
			_move_pattern = Direction::Left;
		}

		if (_move_pattern != Direction::None) {
			for (int i = PREV_MAX - 1 ; i > 0; i--) {
				_old_pos[i].x = _old_pos[i - 1].x;
				_old_pos[i].y = _old_pos[i - 1].y;
			}
			_old_pos[0].x = mx;
			_old_pos[0].y = my;
			_move_count = 0;
		}
	}

	if (_move_pattern > Direction::None) {
		_pos += _move_direction[(int)_move_pattern] * SPEED;
		FixDirection();
	}
	_move_count += SPEED;
}

void Decoy::Animetion()
{
	constexpr int max_flame = 40;

	_flame--;
	_animetion_flame++;
	_animetion_flame = (int)_animetion_flame % max_flame;
}

/**
 * @fn
 * キャラクターの画像と動きのパターンに違いがあるため修正するためのプログラムです。
 */
void Decoy::FixDirection()
{
	switch (_move_pattern)
	{
	case Direction::Down:	_sprite_direction = 3; break;
	case Direction::Right:	_sprite_direction = 0; break;
	case Direction::Left:	_sprite_direction = 2; break;
	case Direction::Up:		_sprite_direction = 1; break;
	default:								break;
	}
}


