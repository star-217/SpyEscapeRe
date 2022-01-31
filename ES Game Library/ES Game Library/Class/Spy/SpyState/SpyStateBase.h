#pragma once

#include "../../../ESGLib.h"
#include "../../Base/ConstantList.h"

class SpyStateBase
{
public:
	SpyStateBase(){};
	virtual ~SpyStateBase() {};

	virtual void Initialize(TCHAR* file_name) = 0;
	virtual void Update() = 0;
	virtual void Draw(Vector3& pos, int& dir,float alpha) {};

protected:

	SPRITE _sprite = NULL;
	float _flame = 0;
};