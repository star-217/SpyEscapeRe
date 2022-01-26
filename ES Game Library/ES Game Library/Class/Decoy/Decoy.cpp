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
	_move_pattern = Direction::None;

	_animetion_flame = 0;
	_sprite_direction = 0;
	_move_count = 50; //50ドット単位のブロック
	_flame = 3600;
	_tag = "DECOY";

}

void Decoy::Update()
{
	constexpr float BLOCK_SIZE = 50.0f;
	
	_threatmap->Update();
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

void Decoy::DoMove(HumanBase* human)
{
	if(human->GetTag() == "SPY")
	_threatmap->SetSpyPosData(human->GetPosition());
	if(human->GetTag() == "TRACKER")
	_threatmap->SetTrackerPosData(human->GetPosition());
}

/**
 * @fn
 * デコイの移動プログラムです。
 * @detail 一ブロック動くたびに脅威マップをもとに数値が大きいほうに移動するようにしたプログラムです。
 */
void Decoy::Move()
{
	constexpr float BLOCK_SIZE = 50.0f;
	if (_move_count >= BLOCK_SIZE) {
		//キャラの場所のブロック分け
		const int MX = (int)(_pos.x / BLOCK_SIZE);
		const int MY = (int)(_pos.y / BLOCK_SIZE);

		float max = 0;
		_move_pattern = Direction::None;
		//今いる場所から全ての方向のブロックにある値を調べ高い方へ移動する
		if (_threat_data[MY - 1][MX] > max) {
			max = _threat_data[MY - 1][MX];
			_move_pattern = Direction::Up;
		}
		if (_threat_data[MY + 1][MX] > max) {
			max = _threat_data[MY + 1][MX];
			_move_pattern = Direction::Down;
		}
		if (_threat_data[MY][MX + 1] > max) {
			max = _threat_data[MY][MX + 1];
			_move_pattern = Direction::Right;
		}
		if (_threat_data[MY][MX - 1] > max) {
			max = _threat_data[MY][MX - 1];
			_move_pattern = Direction::Left;
		}

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

	if (_move_pattern > Direction::None) {
		_pos += _move_direction[(int)_move_pattern - 1] * SPEED;
		FixDirection();
	}
	_move_count += SPEED;
}

void Decoy::Animetion()
{
	constexpr int MAX_FLAME = 40;

	_flame--;
	_animetion_flame++;
	_animetion_flame = (int)_animetion_flame % MAX_FLAME;
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


