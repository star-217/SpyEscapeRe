#pragma once

#include "TrackerStateBase.h"

class TrackerWinState : public TrackerStateBase {

public:
	TrackerWinState() {};
	virtual ~TrackerWinState() {};

	void Initialize(TCHAR* file_name) override;
	void Update() override;
	void Draw(Vector3& pos, int& dir) override;

};