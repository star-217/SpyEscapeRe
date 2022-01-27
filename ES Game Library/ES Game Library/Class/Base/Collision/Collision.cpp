/**
 * @file Collision.cpp
 * @brief “–‚½‚è”»’èƒNƒ‰ƒX
 * @author ¯Š°•¶
 * @date 2021/04/20
 */
#include "Collision.h"

 /**
  * @fn
  * “–‚½‚è”»’è‚ð‚µ‚½‚¢ƒNƒ‰ƒX‚ð“o˜^‚·‚é
  * @param (tag) “o˜^‚·‚é‚à‚Ì‚ÌŽí—Þ
  * @param (human) “o˜^‚·‚éƒNƒ‰ƒX
  */
void Collision::AddListener(std::string tag, HumanBase* human)
{
	_human_list[tag].push_back(human);
}

/**
 * @fn
 * ƒ`ƒFƒbƒN‚µ‚½‚¢“–‚½‚è”»’è‚ð’²‚×‚é
 * @param (tag1) ’²‚×‚½‚¢•¨‚ÌŽí—Þ‚P 
 * @param (tag2) ’²‚×‚½‚¢•¨‚ÌŽí—Þ‚Q
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

