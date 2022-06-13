#pragma once

#include "TrackerStateBase.h"

class TrackerDefaultState : public TrackerStateBase {

public:
	TrackerDefaultState() {};
	virtual ~TrackerDefaultState() {};

	void Initialize(TCHAR* file_name) override;
	void Update() override;
	void Draw(Vector3& pos, int& dir) override;

};