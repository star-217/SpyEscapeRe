/**
 * @file Constantlist.h
 * @brief 定数とenumクラスのリスト
 * @author 星寛文
 * @date 2021/07/14
 */

#pragma once

#include "../../ESGLib.h"

#define BLOCK_SIZE 50 //区画わけの基準数
#define MAP_MAX_HEIGHT 18 //マップデータの配列数
#define PLAYER_MAX 2 //プレイヤーの最大数
#define PREV_MAX 4 // 遡る歩数
#define CHARA_SIZE_X 50
#define CHARA_SIZE_Y 70
#define FIXED_POS_Y 20

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

enum class TrackerState
{
	Default,
	Win,
	Lose,
	Attack
};