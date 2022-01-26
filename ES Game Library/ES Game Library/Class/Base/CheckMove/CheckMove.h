#pragma once

#include "../../Decoy/Decoy.h"

class CheckMove {
public:

	CheckMove() = default;
	virtual ~CheckMove() {}

	void AddListener(HumanBase* human);

	void Notify(HumanBase* human);
private:
	std::vector<HumanBase*> _human_list;
};