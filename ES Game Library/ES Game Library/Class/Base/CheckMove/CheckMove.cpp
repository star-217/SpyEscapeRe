/**
 * @file  CheckMove.cpp
 * @brief ����̃N���X�����������Ƃ𒲂ׂ�N���X
 * @author ������
 * @date 2022/01/27
 */

#include "CheckMove.h"

 /**
  * @fn
  * �m�点�����N���X��o�^����
  * @param (human) ���������Ƃ�m�点�����N���X 
  */
void CheckMove::AddListener(HumanBase* human)
{
	_human_list.push_back(human);
}

/**
  * @fn
  * ���������Ƃ�m�点�ē���̏�����������悤�ɖ��߂���
  * @param (human) �������N���X
  */
void CheckMove::Notify(HumanBase* human)
{
	for (auto& target : _human_list)
	{
		target->DoMove(human);
	}
}
