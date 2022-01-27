/**
 * @file  DecoyManager.cpp
 * @brief �f�R�C�𕡐��Ǘ����邽�߂̃}�l�[�W���[�N���X
 * @author ������
 * @date 2021/04/20
 */
#include "DecoyManager.h"

DecoyManager::DecoyManager()
{

}


void DecoyManager::Initialize(int num_decoy)
{
	std::vector<int>   waitCount = { 7, 10, 10, 10, 10, 10 };
	std::vector<float> ratio = { 0.3f, 0.4f, 0.5f, 0.2f, 0.1f, 0.3f };

	for (int i = 0; i < num_decoy; i++)
	{
		_decoy.push_back(new Decoy);
		_decoy[i]->Initialize();
		_decoy[i]->SetPriorityRatio(ratio[i]);
		_decoy[i]->SetWaitCount(waitCount[i]);
	}
}

void DecoyManager::Update()
{
	for (int i = 0; i < _decoy.size(); i++)
	{
		_decoy[i]->Update();
	}
}

void DecoyManager::Draw()
{
	for (int i = 0; i < _decoy.size(); i++)
	{
		_decoy[i]->Draw();
	}
}
/**
 * @fn
 * ���Ѓ}�b�v�̏����������邽�߂̃f�[�^��n��
 * @param (human) �n�������L�����N�^�[�N���X
 */
void DecoyManager::SetOtherPositionInit(HumanBase* human)
{
	for (int i = 0; i < _decoy.size(); i++)
	{
		_decoy[i]->SetPosDataInit(human);
	}
}

/**
 * @fn
 * �f�R�C���ŏ��ɂ�����W��ݒ肷��
 * @param (positions) ���W�f�[�^
 */
void DecoyManager::SetPosition(std::vector<Vector3>& positions)
{
	for (int i = 0; i < _decoy.size(); i++)
	{
		_decoy[i]->SetDecoyPos(positions[i]);
	}
}

