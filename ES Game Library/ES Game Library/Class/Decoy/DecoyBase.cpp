#include "DecoyBase.h"

DecoyBase::DecoyBase()  : _move_direction{ -Vector3_Up, -Vector3_Down,Vector3_Right,Vector3_Left },
						  _old_pos_x {}, _old_pos_y {}
{
}

void DecoyBase::Initialize(std::vector<cstring>& map_data,Vector3 pos,float ratio,int count)
{

	DefaultFont = GraphicsDevice.CreateDefaultFont();
	_decoy = GraphicsDevice.CreateSpriteFromFile(_T("spy.png"));

	for (int y = 0; y < map_data.size(); ++y) {
		for (int x = 0; x < map_data[y].size(); ++x) {
			_ai_data[y].push_back(0);
		}
	}

	_stop_count = count;
	_ratio = ratio;
	_ratio2 = 1.0f - _ratio;
	_decoy_pos = pos;
	_speed = 5;
	_animetion_flame = 0;
	_direction = 0;
	_move_count = 50;
	_flame = 3600;
	_fix_positon_y = 20;

}

void DecoyBase::Update(ThreatMap& map)
{
	Vector2 chara_size = Vector2(50, 70);

	AIMap(map);
	Move();
	_collision = Rect(_decoy_pos.x, _decoy_pos.y, _decoy_pos.x + chara_size.x, _decoy_pos.y + chara_size.y);
	Animetion();

}

void DecoyBase::Draw()
{
	Vector2 chara_size = Vector2(50, 70);
	SpriteBatch.Draw(*_decoy,Vector3(_decoy_pos.x, _decoy_pos.y - _fix_positon_y, _decoy_pos.z),
					RectWH(chara_size.x * _animetion_flame, chara_size.y * _direction,chara_size.x,chara_size.y));

}


void DecoyBase::AIMap(ThreatMap& threatmap)
{
	float block_size = 50.0f;
	int data_size = 18;

	if (_move_count >= block_size) {
		auto spy_data = threatmap.GetSpyData();
		auto tracker_data = threatmap.GetTrackerData();
		for (int y = 0; y < data_size; y++) {
			for (int x = 0; x < spy_data[y].size(); x++) {
				_ai_data[y][x] = spy_data[y][x] * _ratio + tracker_data[y][x] * _ratio2;
				for (int i = PREV_MAX - 1 ; i > 0; i--) {
					_ai_data[_old_pos_y[i]][_old_pos_x[i]] = 0;//直前に通った場所にいかないようにするため
				}
			}
		}
	}

}

/**
 * @fn
 * デコイの移動プログラムです。
 * @sa 参照すべき関数を書けばリンクが貼れる
 * @detail 一ブロック動くたびに脅威マップをもとに数値が大きいほうに移動するようにしたプログラムです。
 */
void DecoyBase::Move()
{
	float block_size = 50.0f;
	if (_move_count >= block_size) {
		//キャラの場所のブロック分け
		const int mx = (int)(_decoy_pos.x / block_size);
		const int my = (int)(_decoy_pos.y / block_size);

		//
		float max = 0;
		_move_pattern = Direction::None;
		if (_ai_data[my - 1][mx] > max) {
			max = _ai_data[my - 1][mx];
			_move_pattern = Direction::Up;
		}
		if (_ai_data[my + 1][mx] > max) {
			max = _ai_data[my + 1][mx];
			_move_pattern = Direction::Down;
		}
		if (_ai_data[my][mx + 1] > max) {
			max = _ai_data[my][mx + 1];
			_move_pattern = Direction::Right;
		}
		if (_ai_data[my][mx - 1] > max) {
			max = _ai_data[my][mx - 1];
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
		_decoy_pos += _move_direction[(int)_move_pattern] * _speed;
		FixDirection();
	}
	_move_count += _speed;
}

void DecoyBase::Animetion()
{
	int max_flame = 40;
	_flame--;
	_animetion_flame += 1.0f;
	_animetion_flame = (int)_animetion_flame % max_flame;
}

/**
 * @fn
 * キャラクターの画像と動きのパターンに違いがあるため修正するためのプログラムです。
 */
void DecoyBase::FixDirection()
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


