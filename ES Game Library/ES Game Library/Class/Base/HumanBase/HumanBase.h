#pragma once

#include "../../../ESGLib.h"
#include "../Move/Move.h"

class HumanBase {
public:

	virtual void Initialize() = 0;
	virtual void Update() {};
	virtual void Draw() {};
	virtual void OnCollisionEnter(std::string tag) {};

	Vector3 GetPosition() { return _pos; }

	Rect GetCollision() { return _collision; }

	std::string GetTag() { return _tag; }
protected:

	const float CHARA_SIZE_X = 50.0f;
	const float CHARA_SIZE_Y = 70.0f;
	const float FIX_POS_Y = 20.0f;

	Vector3 _pos;
	std::string _tag;
	Rect _collision;
};