#include "DecoyBase.h"

DecoyBase::DecoyBase()  : _old_pos_x {}, _old_pos_y {}
{
}

void DecoyBase::Initialize(Vector3 pos)
{

	DefaultFont = GraphicsDevice.CreateDefaultFont();
	_decoy = GraphicsDevice.CreateSpriteFromFile(_T("spy.png"));

	auto map_data = Map::GetMapData();
	for (int y = 0; y < map_data.size(); ++y) {
		for (int x = 0; x < map_data[y].size(); ++x) {
			_ai_data[y].push_back(0);
		}
	}

	_decoy_pos = pos;
	_animetion_flame = 0;
	_direction = 0;
	_move_count = 50;
	_flame = 3600;
	_fix_positon_y = 20;

}

void DecoyBase::Update(ThreatMap& map)
{


	AIMap(map);
	Move();
	_collision = Rect(_decoy_pos.x, _decoy_pos.y, _decoy_pos.x + CHARA_SIZE.x, _decoy_pos.y + CHARA_SIZE.y);
	Animetion();

}

void DecoyBase::Draw()
{

	SpriteBatch.Draw(*_decoy,Vector3(_decoy_pos.x, _decoy_pos.y - _fix_positon_y, _decoy_pos.z),
					RectWH(CHARA_SIZE.x * _animetion_flame, CHARA_SIZE.y * _direction, CHARA_SIZE.x, CHARA_SIZE.y));

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
		_decoy_pos += _move_direction[(int)_move_pattern] * SPEED;
		FixDirection();
	}
	_move_count += SPEED;
}

void DecoyBase::Animetion()
{
	const int max_flame = 40;

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


