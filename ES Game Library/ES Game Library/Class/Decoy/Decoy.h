/**
 * @file  Decoy.h
 * @brief �f�R�C(NPC)�N���X
 * @author ������
 * @date 2022/01/27
 */

#pragma once

#include "../../ESGLib.h"
#include "../Threatmap/Threatmap.h"
#include "../Base/HumanBase/HumanBase.h"
#include "../Base/ConstantList.h"

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

	void SetWaitCount(const int& wait_count) { _wait_count = wait_count; }
	void SetPriorityRatio(const float& ratio) { _ratio = ratio; }
	void SetPosDataInit(HumanBase* human) { _threatmap->SetPosData(human); }
	void ThreatMapDataInit() { _threatmap->SetMapdata(_map_data); }

private:

	void Move();
	void FixDirection();
	void Animetion();

	std::unique_ptr<ThreatMap> _threatmap;

	Vector3 _spy_pos;
	Vector3 _tracker_pos;

	SPRITE        _decoy;

	//�㉺���E�̕����̒l
	const Vector3 _move_direction[4] =
	{
		 -Vector3_Down,
		 Vector3_Left,
		 Vector3_Right,
		 -Vector3_Up
	};	// 4�����Ԃ�

	//�ړ�������enumclass
	Direction _move_pattern;

	//�A�ԉ摜��y��
	int  _sprite_direction;

	//AI������I�Ɏ~�܂�J�E���g
	int _wait_count;
	//�u���b�N�P�ʈړ��̃J�E���g
	int _move_count;
	//AI�̌v�Z�̊���
	float _ratio;

	float _animetion_flame;

	// �k�����
	enum { PREV_MAX = 4 };
	std::vector<Vector2> _old_pos;

	std::vector<std::vector<float>> _threat_data;
};