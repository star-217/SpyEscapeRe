#include "SkillState.h"

SkillState::SkillState() :
	skil_box{},
	skil_count(0),
	state(new NoSkill),
	skil_count_max(1)
{
}

void SkillState::Update()
{
	state->Update();
}

void SkillState::Draw()
{
	state->Draw();
}


void SkillState::RandomSkil()
{
	auto random_count = MathHelper_Random(0, skil_count_max);
	for (int i = 0; i < MAX; i++) {
		if (skil_box[i] == random_count)
		{
			random_count = MathHelper_Random(0, skil_count_max);
			i = 0;
		}
	}
	skil_box[skil_count] = random_count;
	skil_count++;

	switch (random_count)
	{
	case BLACKOUT:
		ChangeState(new BlackOut); break;
	case INVISIBLE:
		ChangeState(new Invisible); break;
	default:
		ChangeState(new NoSkill); break;
		break;
	}
}

void SkillState::ChangeState(SkillBase* state)
{
	delete this->state;
	this->state = state;
}




