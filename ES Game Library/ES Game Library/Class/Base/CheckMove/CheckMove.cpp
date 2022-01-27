/**
 * @file  CheckMove.cpp
 * @brief 特定のクラスが動いたことを調べるクラス
 * @author 星寛文
 * @date 2022/01/27
 */

#include "CheckMove.h"

 /**
  * @fn
  * 知らせたいクラスを登録する
  * @param (human) 動いたことを知らせたいクラス 
  */
void CheckMove::AddListener(HumanBase* human)
{
	_human_list.push_back(human);
}

/**
  * @fn
  * 動いたことを知らせて特定の処理をさせるように命令する
  * @param (human) 動いたクラス
  */
void CheckMove::Notify(HumanBase* human)
{
	for (auto& target : _human_list)
	{
		target->DoMove(human);
	}
}
