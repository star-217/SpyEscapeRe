#pragma once

#include "TrackerStateBase.h"

class TrackerAttackState: public TrackerStateBase {

public:
	TrackerAttackState() {};
	virtual ~TrackerAttackState() {};

	void Initialize(TCHAR* file_name) override;
	void Update() override;
	void Draw(Vector3& pos, int& dir) override;

};