#include "SkillState.h"

SkillState::SkillState() :
	_skil_box{},
	_skil_count(0),
	_state(new NoSkill),
	_skil_count_max(1)
{
}

float SkillState::Update()
{
	_state->Update();
	return _state->Update();
}

void SkillState::Draw()
{
	_state->Draw();
}


void SkillState::RandomSkil()
{
	auto random_count = MathHelper_Random(0, _skil_count_max);
	for (int i = 0; i < MAX; i++) {
		if (_skil_box[i] == random_count)
		{
			random_count = MathHelper_Random(0, _skil_count_max);
			i = 0;
		}
	}
	_skil_box[_skil_count] = random_count;
	_skil_count++;

	ChangeState(_factory.Create(random_count));
}

void SkillState::ChangeState(SkillBase* state)
{
	delete this->_state;
	this->_state = state;
}




