/**
 * @file Collision.cpp
 * @brief 当たり判定をobserverパターンで実装したもの
 * @author 星寛文
 * @date 2021/04/20
 */
#include "Collision.h"


void Collision::AddListener(std::string tag, HumanBase* human)
{
	_human_list[tag].push_back(human);
}

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

