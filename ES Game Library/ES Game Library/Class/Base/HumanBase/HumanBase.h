/**
 * @file  HumanBase.cpp
 * @brief キャラクターの基底クラス
 * @author 星寛文
 * @date 2022/01/27
 */

#pragma once

#include "../../../ESGLib.h"
#include "../ConstantList.h"

class CheckMove;

class HumanBase {
public:

	virtual void Initialize() = 0;
	virtual void Update() {};
	virtual void Draw() {};
	//当たり判定が返ってきた時の処理
	virtual void OnCollisionEnter(std::string tag) {};
	//CheckMoveクラスから知らせが来た時の処理
	virtual void DoMove(HumanBase* human) {};
	
	void SetMapData(std::vector<cstring>& map_data) { _map_data = map_data; }
	void SetTag(std::string tag) { _tag = tag; }
	void SetPosition(Vector3 pos) { _pos = pos; }
	void SetCheckMoveClass(CheckMove* check_move) { _check_move = check_move; }

	Vector3 GetPosition() { return _pos; }
	Rect GetCollision() { return _collision; }
	std::string GetTag() { return _tag; }

protected:

	CheckMove* _check_move;
	Vector3 _pos;
	std::string _tag;
	Rect _collision;
	std::vector<cstring> _map_data;
};