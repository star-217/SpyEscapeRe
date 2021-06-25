#include "DecoyBase.h"

DecoyBase::DecoyBase()  : _move_direction{ -Vector3_Up, -Vector3_Down,Vector3_Right,Vector3_Left },
						  _old_pos_x {}, _old_pos_y {}
{
}

void DecoyBase::Initialize(Vector3 pos,float ratio,int count)
{
	DefaultFont = GraphicsDevice.CreateDefaultFont();
	_decoy = GraphicsDevice.CreateSpriteFromFile(_T("spy.png"));
	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < 32; x++) {
			_ai_data[y].push_back(0);
		}
	}
	_stop_count = count;
	_ratio = ratio;
	_decoy_pos = pos;
	_speed = 5;
	_animetion_flame = 0;
	_direction = 0;
	_move_count = 50;
	_flame = 3600;
	_fix_positon_y = 20;

}

void DecoyBase::Update(ThreatMap map)
{
	AIMap(map);
	Move();
	_collision = Rect(_decoy_pos.x, _decoy_pos.y, _decoy_pos.x + 50, _decoy_pos.y + 70);
	Animetion();

}

void DecoyBase::Draw()
{
	SpriteBatch.Draw(*_decoy,Vector3(_decoy_pos.x, _decoy_pos.y - _fix_positon_y, _decoy_pos.z),RectWH(50 * _animetion_flame, 70 * _direction,50,70));

}

void DecoyBase::AIMap(ThreatMap threatmap)
{
	auto spy_data = threatmap.GetSpyData();
	auto tracker_data = threatmap.GetTrackerData();
	auto ratio2 = 1.0f - _ratio;

	if (_move_count >= 50) {
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < spy_data[y].size(); x++) {
				_ai_data[y][x] = spy_data[y][x] * _ratio + tracker_data[y][x] * ratio2;
				for (int i = 3; i > 0; i--) {
					_ai_data[_old_pos_y[i]][_old_pos_x[i]] = 0;
				}
			}
		}
	}

}


void DecoyBase::Move()
{
	if (_move_count >= 50) {
		//キャラの場所のブロック分け
		const int mx = (int)(_decoy_pos.x / 50.0f);
		const int my = (int)(_decoy_pos.y / 50.0f);

		float max = 0;
		_move_pattern = -1;
		if (_ai_data[my - 1][mx] > max) {
			max = _ai_data[my - 1][mx];
			_move_pattern = UP;
		}
		if (_ai_data[my + 1][mx] > max) {
			max = _ai_data[my + 1][mx];
			_move_pattern = DOWN;
		}
		if (_ai_data[my][mx + 1] > max) {
			max = _ai_data[my][mx + 1];
			_move_pattern = RIGHT;
		}
		if (_ai_data[my][mx - 1] > max) {
			max = _ai_data[my][mx - 1];
			_move_pattern = LEFT;
		}
		if (_move_pattern != -1) {
			for (int i = 3; i > 0; i--) {
				_old_pos_x[i] = _old_pos_x[i - 1];
				_old_pos_y[i] = _old_pos_y[i - 1];
			}
			_old_pos_x[0] = mx;
			_old_pos_y[0] = my;
			_move_count = 0;
		}
	}

	if (_move_pattern >= 0) {
		_decoy_pos += _move_direction[_move_pattern] * _speed;
		FixDirection();
	}
	_move_count += _speed;
}

void DecoyBase::Animetion()
{
	_flame--;
	_animetion_flame += 1.0f;
	_animetion_flame = (int)_animetion_flame % 40;
}

void DecoyBase::FixDirection()
{
	switch (_move_pattern)
	{
	case 0:
		_direction = 3; break;
	case 1:
		_direction = 0; break;
	case 2:
		_direction = 2; break;
	case 3:
		_direction = 1; break;
	default:
		break;
	}
}


