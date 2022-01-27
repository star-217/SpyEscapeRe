/**
 * @file Collision.cpp
 * @brief �����蔻��N���X
 * @author ������
 * @date 2021/04/20
 */
#include "Collision.h"

 /**
  * @fn
  * �����蔻����������N���X��o�^����
  * @param (tag) �o�^������̂̎��
  * @param (human) �o�^����N���X
  */
void Collision::AddListener(std::string tag, HumanBase* human)
{
	_human_list[tag].push_back(human);
}

/**
 * @fn
 * �`�F�b�N�����������蔻��𒲂ׂ�
 * @param (tag1) ���ׂ������̎�ނP 
 * @param (tag2) ���ׂ������̎�ނQ
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

