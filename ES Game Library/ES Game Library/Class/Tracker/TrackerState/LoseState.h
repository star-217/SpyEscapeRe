#pragma once

#include "TrackerStateBase.h"

class LoseState : public TrackerStateBase {

public:
	LoseState();
	~LoseState() {};

	void Initialize(TCHAR* file_name) override;
	void Update() override;
	void Draw(Vector3& pos, int& dir) override;

};