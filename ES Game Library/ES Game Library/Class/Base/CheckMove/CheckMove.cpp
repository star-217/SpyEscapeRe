#include "CheckMove.h"

void CheckMove::AddListener(HumanBase* human)
{
	_human_list.push_back(human);
}

void CheckMove::Notify(HumanBase* human)
{
	for (auto& target : _human_list)
	{
		target->DoMove(human);
	}
}
