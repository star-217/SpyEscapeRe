#include "DecoyBase.h"

DecoyBase::DecoyBase()  : move_direction{ -Vector3_Up, -Vector3_Down,Vector3_Right,Vector3_Left },
						  old_pos_x {}, old_pos_y {}
{
}

void DecoyBase::Initialize(Vector3 pos,float ratio,int count)
{
	DefaultFont = GraphicsDevice.CreateDefaultFont();
	decoy = GraphicsDevice.CreateSpriteFromFile(_T("spy.png"));
	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < 32; x++) {
			ai_data[y].push_back(0);
		}
	}
	stop_count = count;
	_ratio = ratio;
	decoy_pos = pos;
	speed = 5;
	animetion_flame = 0;
	direction = 0;
	move_count = 50;
	flame = 3600;
	fix_positon_y = 20;

}

void DecoyBase::Update(ThreatMap map)
{
	AIMap(map);
	Move();
	collision = Rect(decoy_pos.x, decoy_pos.y, decoy_pos.x + 50, decoy_pos.y + 70);
	Animetion();

}

void DecoyBase::Draw()
{
	SpriteBatch.Draw(*decoy,Vector3(decoy_pos.x, decoy_pos.y - fix_positon_y, decoy_pos.z),RectWH(50 * animetion_flame, 70 * direction,50,70));

}

void DecoyBase::AIMap(ThreatMap threatmap)
{
	auto spy_data = threatmap.GetSpyData();
	auto tracker_data = threatmap.GetTrackerData();
	auto ratio2 = 1.0f - _ratio;

	if (move_count >= 50) {
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < spy_data[y].size(); x++) {
				ai_data[y][x] = spy_data[y][x] * _ratio + tracker_data[y][x] * ratio2;
				for (int i = 3; i > 0; i--) {
					ai_data[old_pos_y[i]][old_pos_x[i]] = 0;
				}
			}
		}
	}

}


void DecoyBase::Move()
{
	if (move_count >= 50) {
		//キャラの場所のブロック分け
		const int mx = (int)(decoy_pos.x / 50.0f);
		const int my = (int)(decoy_pos.y / 50.0f);

		float max = 0;
		move_pattern = -1;
		if (ai_data[my - 1][mx] > max) {
			max = ai_data[my - 1][mx];
			move_pattern = UP;
		}
		if (ai_data[my + 1][mx] > max) {
			max = ai_data[my + 1][mx];
			move_pattern = DOWN;
		}
		if (ai_data[my][mx + 1] > max) {
			max = ai_data[my][mx + 1];
			move_pattern = RIGHT;
		}
		if (ai_data[my][mx - 1] > max) {
			max = ai_data[my][mx - 1];
			move_pattern = LEFT;
		}
		if (move_pattern != -1) {
			for (int i = 3; i > 0; i--) {
				old_pos_x[i] = old_pos_x[i - 1];
				old_pos_y[i] = old_pos_y[i - 1];
			}
			old_pos_x[0] = mx;
			old_pos_y[0] = my;
			move_count = 0;
		}
	}

	if (move_pattern >= 0) {
		decoy_pos += move_direction[move_pattern] * speed;
		FixDirection();
	}
	move_count += speed;
}

void DecoyBase::Animetion()
{
	flame--;
	animetion_flame += 1.0f;
	animetion_flame = (int)animetion_flame % 40;
}

void DecoyBase::FixDirection()
{
	switch (move_pattern)
	{
	case 0:
		direction = 3; break;
	case 1:
		direction = 0; break;
	case 2:
		direction = 2; break;
	case 3:
		direction = 1; break;
	default:
		break;
	}
}


