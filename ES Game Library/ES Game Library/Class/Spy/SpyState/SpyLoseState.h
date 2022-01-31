#pragma once

#include "SpyStateBase.h"

class SpyLoseState : public SpyStateBase {
public:
	SpyLoseState() {};
	virtual ~SpyLoseState() {};

	void Initialize(TCHAR* file_name);
	void Update();
	void Draw(Vector3& pos, int& dir, float alpha);

private:

};