#pragma once

#include "TrackerStateBase.h"

class AttackState: public TrackerStateBase {

public:
	AttackState();
	~AttackState() {};

	void Initialize(TCHAR* file_name) override;
	void Update() override;
	void Draw(Vector3& pos, int& dir) override;

};