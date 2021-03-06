/**
 * @file Collision.cpp
 * @brief 当たり判定クラス
 * @author 星寛文
 * @date 2021/04/20
 */
#include "Collision.h"

 /**
  * @fn
  * 当たり判定をしたいクラスを登録する
  * @param (tag) 登録するものの種類
  * @param (human) 登録するクラス
  */
void Collision::AddListener(std::string tag, HumanBase* human)
{
	_human_list[tag].push_back(human);
}

/**
 * @fn
 * チェックしたい当たり判定を調べる
 * @param (tag1) 調べたい物の種類１ 
 * @param (tag2) 調べたい物の種類２
 */
void Collision::CheckCollision(std::string tag1, std::string tag2)
{
	for (auto&& same : _human_list[tag1])
	{
		for (auto&& other : _human_list[tag2])
		{
			if (same->GetCollision().Intersect(other->GetCollision()))
			{
				same->OnCollisionEnter(tag2);
				other->OnCollisionEnter(tag1);
			}
		}
	}
}

