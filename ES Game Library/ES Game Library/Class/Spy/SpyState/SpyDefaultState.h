#pragma once

#include "SpyStateBase.h"

class SpyDefaultState : public SpyStateBase {
public:
	SpyDefaultState() {};
	virtual ~SpyDefaultState() {};

	void Initialize(TCHAR* file_name);
	void Update();
	void Draw(Vector3& pos, int& dir, float alpha);

private:

};