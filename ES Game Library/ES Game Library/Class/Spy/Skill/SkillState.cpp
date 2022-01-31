/**
 * @file  SkillState.cpp
 * @brief Spyのスキルのランダム化とStateパターンでのスキルの切り替えプログラム
 * @author 星寛文
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
  * 更新処理
  */
void SkillState::Update()
{
	return _state->Update();
}

/**
  * @fn
  * 描画
  */
void SkillState::Draw()
{
	_state->Draw();
}

/**
 * @detail コンストラクタ配列の中身をシャッフルして
 *		   先頭からスキルを出すようにする。
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




