#pragma once

#include "../../ESGLib.h"
#include "../Threatmap/Threatmap.h"
#include "../Base/HumanBase/HumanBase.h"

class Decoy : public HumanBase
{
public:
	Decoy();
	virtual ~Decoy() {};

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void OnCollisionEnter(std::string tag) override {};
	void DoMove(HumanBase* human) override;

	void SetSpyPos(Vector3 pos) { _spy_pos = pos; }
	void SetTrackerPos(Vector3 pos) { _tracker_pos = pos; }

	void Move();
	void SetDecoyPos(Vector3 pos) { _pos = pos; }
	void SetWaitCount(int& wait_count) { _wait_count = wait_count; }
	void SetPriorityRatio(float& ratio) { _ratio = ratio; }


private:

	void FixDirection();
	void Animetion();

	enum class Direction
	{
		None,
		Down,
		Left,
		Right,
		Up,
		Max
	};

	ThreatMap* _threatmap;
	Vector3 _spy_pos;
	Vector3 _tracker_pos;


	SPRITE        _decoy;

	//�L�����̉摜�T�C�Y
	const Vector2 CHARA_SIZE = Vector2(50, 70);

	const int  SPEED = 5;
	//�㉺���E�̕����̒l
	const Vector3 _move_direction[4] =
	{
		 -Vector3_Down,
		 Vector3_Left,
		 Vector3_Right,
		 -Vector3_Up
	};	// 4�����Ԃ�

	//�L�����̃|�W�V����y���C���l
	const float _fix_positon_y = 20.0f;

	//�ړ�������enumclass
	Direction _move_pattern;

	//�A�ԉ摜��y��
	int  _sprite_direction;

	//AI������I�Ɏ~�܂�J�E���g
	int _wait_count;
	//�u���b�N�P�ʈړ��̃J�E���g
	int _move_count;

	float _ratio;

	float _flame;
	float _animetion_flame;

	enum { PREV_MAX = 4 };	// �k�����
	std::vector<Vector2> _old_pos;

	std::vector<std::vector<float>> _threat_data;

	FONT DefaultFont;
};