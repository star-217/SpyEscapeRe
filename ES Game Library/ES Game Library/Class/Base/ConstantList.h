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
//1ブロック単位
const int BLOCK_SIZE = 50.0f;

const float CHARA_SPEED = 5.0f;

enum class Direction //キャラが進む方向
{
	None,
	Down,
	Left,
	Right,
	Up
};