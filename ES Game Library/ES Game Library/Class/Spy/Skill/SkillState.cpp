/**
 * @file  SkillState.cpp
 * @brief Spy�̃X�L���̃����_������State�p�^�[���ł̃X�L���̐؂�ւ��v���O����
 * @author ������
 * @date 2021/04/20
 */
#include "SkillState.h"

#include <numeric>
#include <algorithm>
#include <random>

SkillState::SkillState() :
	_skil_box{},
	_skil_count(0),
	_state(new NoSkill),
	_skil_count_max(1)
{
	std::iota(std::begin(_skil_box), std::end(_skil_box), 0);

	std::random_device seed_gen;
	std::mt19937 engine(seed_gen());
	std::shuffle(std::begin(_skil_box), std::end(_skil_box), engine);
	_factory = std::make_unique<SkillFactory>();
}

/**
  * @fn
  * �X�V����
  */
void SkillState::Update()
{
	return _state->Update();
}

/**
  * @fn
  * �`��
  */
void SkillState::Draw()
{
	_state->Draw();
}

/**
 * @detail �R���X�g���N�^�z��̒��g���V���b�t������
 *		   �擪����X�L�����o���悤�ɂ���B
 */
void SkillState::RandomSkill()
{

	ChangeState(_factory->Create(_skil_box[_skil_count]));
	_skil_count++;
}

void SkillState::ChangeState(SkillBase* state)
{
	delete this->_state;
	this->_state = state;
}

float SkillState::GetAlpfa()
{
	return _state->GetAlpfa();
}




