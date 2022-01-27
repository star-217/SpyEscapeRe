/**
 * @file Constantlist.h
 * @brief 定数とenumクラスのリスト
 * @author 星寛文
 * @date 2021/07/14
 */

#pragma once

#include "../../ESGLib.h"

//キャラの画像サイズ
const Vector2 CHARA_SIZE = Vector2(50,70);
//描画のY軸修正値
const float FIX_POS_Y = 20.0f;

enum class Direction //キャラが進む方向
{
	None,
	Down,
	Left,
	Right,
	Up
};

enum class SpyState
{
	Default,
	Win,
	Lose
};