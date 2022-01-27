#pragma once

#include "TrackerStateBase.h"

class WinState : public TrackerStateBase {

public:
	WinState();
	~WinState() {};

	void Initialize(TCHAR* file_name) override;
	void Update() override;
	void Draw(Vector3& pos, int& dir) override;

};