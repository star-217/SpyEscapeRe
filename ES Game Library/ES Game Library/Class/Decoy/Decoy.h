/**
 * @file  Decoy.h
 * @brief デコイ(NPC)クラス
 * @author 星寛文
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

	void SetPosDataInit(HumanBase* human) { _threatmap->SetPosData(human); }

	void Move();
	void SetDecoyPos(Vector3 pos) { _pos = pos; }
	void SetWaitCount(int& wait_count) { _wait_count = wait_count; }
	void SetPriorityRatio(float& ratio) { _ratio = ratio; }


private:

	void FixDirection();
	void Animetion();

	ThreatMap* _threatmap;
	Vector3 _spy_pos;
	Vector3 _tracker_pos;


	SPRITE        _decoy;

	const int  SPEED = 5;
	//上下左右の方向の値
	const Vector3 _move_direction[4] =
	{
		 -Vector3_Down,
		 Vector3_Left,
		 Vector3_Right,
		 -Vector3_Up
	};	// 4方向ぶん

	//キャラのポジションy軸修正値
	const float _fix_positon_y = 20.0f;

	//移動方向のenumclass
	Direction _move_pattern;

	//連番画像のy軸
	int  _sprite_direction;

	//AIが定期的に止まるカウント
	int _wait_count;
	//ブロック単位移動のカウント
	int _move_count;
	//AIの計算の割合
	float _ratio;

	float _animetion_flame;

	// 遡る歩数
	enum { PREV_MAX = 4 };
	std::vector<Vector2> _old_pos;

	std::vector<std::vector<float>> _threat_data;
};