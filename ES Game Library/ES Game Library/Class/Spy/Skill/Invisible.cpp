/**
 * @file  Invisible.cpp
 * @brief 透明化スキルクラス
 * @author 星寛文
 * @date 2021/04/20
 */
#include "Invisible.h"
#include <algorithm>

Invisible::Invisible() : _time(0.0f), _flag(false)
{

}

/**
  * @fn
  * 更新処理
  */
void Invisible::Update()
{

	constexpr float alpha_speed =  20.0f;
	constexpr float max_time    = 120.0f;

	_alpha = (std::min)(_alpha + alpha_speed, 255.0f);

	_time++;
	if (_time >= max_time)
	{
		_flag  = false;
		_alpha = 1.0f;
		_time  = 0.0f;
	}

}

