#pragma once

#include "../../../ESGLib.h"
#include "../Move/Move.h"

class HumanBase {
public:

	virtual void Initialize() {};
	virtual void Update() {};
	virtual void Draw() {};
	virtual void OnCollisionEnter(std::string tag) {};

	Rect GetCollision() { return _collision; }

protected:

	Vector3 _pos;
	Rect _collision;
};