#pragma once

#include "TrackerStateBase.h"

class DefaultState : public TrackerStateBase {

public:
	DefaultState();
	~DefaultState() {};

	void Initialize(TCHAR* file_name) override;
	void Update() override;
	void Draw(Vector3& pos, int& dir) override;

};