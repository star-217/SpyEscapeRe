#pragma once

#include "TrackerStateBase.h"

class LoseState : public TrackerStateBase {

public:
	LoseState();
	virtual ~LoseState() {};

	void Initialize(TCHAR* file_name) override;
	void Update() override;
	void Draw(Vector3& pos, int& dir) override;

};