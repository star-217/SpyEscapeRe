#pragma once

#include "SpyStateBase.h"

class SpyWinState : public SpyStateBase{
public:
	SpyWinState() {};
	virtual ~SpyWinState() {};

	void Initialize(TCHAR* file_name);
	void Update();
	void Draw(Vector3& pos, int& dir, float alpha);

private:

};