#include "Decoy.h"

Decoy::Decoy()  : _old_pos_x {}, _old_pos_y {}
{
}

void Decoy::Initialize()
{

	DefaultFont = GraphicsDevice.CreateDefaultFont();
	_decoy = GraphicsDevice.CreateSpriteFromFile(_T("spy.png"));

	_decoy_pos = pos;
	_animetion_flame = 0;
	_direction = 0;
	_move_count = 50;
	_flame = 3600;
	_fix_positon_y = 20;

}

void Decoy::Update()
{
	constexpr float block_size = 50.0f;
	//_threatmap;
	
	if (_move_count >= block_size) {
		_threat_data = _threatmap.CreateTheatData(_ratio);
	}

	Move();
	_collision = Rect(_decoy_pos.x, _decoy_pos.y, _decoy_pos.x + CHARA_SIZE.x, _decoy_pos.y + CHARA_SIZE.y);
	Animetion();

}

void Decoy::Draw()
{

	SpriteBatch.Draw(*_decoy,Vector3(_decoy_pos.x, _decoy_pos.y - _fix_positon_y, _decoy_pos.z),
					RectWH(CHARA_SIZE.x * _animetion_flame, CHARA_SIZE.y * _direction, CHARA_SIZE.x, CHARA_SIZE.y));

}

/**
 * @fn
 * デコイの移動プログラムです。
 * @sa 参照すべき関数を書けばリンクが貼れる
 * @detail 一ブロック動くたびに脅威マップをもとに数値が大きいほうに移動するようにしたプログラムです。
 */
void Decoy::Move()
{
	constexpr float block_size = 50.0f;
	if (_move_count >= block_size) {
		//キャラの場所のブロック分け
		const int mx = (int)(_decoy_pos.x / block_size);
		const int my = (int)(_decoy_pos.y / block_size);

		//
		float max = 0;
		_move_pattern = Direction::None;
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
				_old_pos_x[i] = _old_pos_x[i - 1];
				_old_pos_y[i] = _old_pos_y[i - 1];
			}
			_old_pos_x[0] = mx;
			_old_pos_y[0] = my;
			_move_count = 0;
		}
	}

	if (_move_pattern > Direction::None) {
		_decoy_pos += _move_direction[(int)_move_pattern] * SPEED;
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
	case Direction::Down:	_direction = 3; break;
	case Direction::Right:	_direction = 0; break;
	case Direction::Left:	_direction = 2; break;
	case Direction::Up:		_direction = 1; break;
	default:								break;
	}
}


