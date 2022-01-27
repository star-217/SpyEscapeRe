#pragma once

#include "../../../ESGLib.h"
#include "../../Base/ConstantList.h"

class TrackerStateBase
{
public:
	TrackerStateBase() {};
	virtual ~TrackerStateBase() = 0;

	virtual void Initialize(TCHAR* file_name) = 0;
	virtual void Update() = 0;
	virtual void Draw(Vector3& pos, int& dir) {};
	virtual bool AnimetionFinish() { return _flag; }

protected:

	SPRITE _sprite;
	bool _flag = false;
	float _flame = 0;
};