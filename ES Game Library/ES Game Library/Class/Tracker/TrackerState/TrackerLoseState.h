#pragma once

#include "TrackerStateBase.h"

class TrackerLoseState : public TrackerStateBase {

public:
	TrackerLoseState() {};
	virtual ~TrackerLoseState() {};

	void Initialize(TCHAR* file_name) override;
	void Update() override;
	void Draw(Vector3& pos, int& dir) override;

};