/**
 * @file  DecoyManager.h
 * @brief �f�R�C�𕡐��Ǘ����邽�߂̃}�l�[�W���[�N���X
 * @author ������
 * @date 2021/04/20
 */
#pragma once

#include "../../ESGLib.h"
#include "Decoy.h"

class DecoyManager
{
public:
	DecoyManager();
	virtual ~DecoyManager() {};

	void Initialize(int num_decoy);
	void Update();
	void Draw();
	void SetOtherPositionInit(HumanBase* human);
	void SetPosition(std::vector<Vector3>& positions);

	//Decoy�N���X�����֐�
	std::vector<Decoy*> GetBase() { return _decoy; }

private:
	std::vector<Decoy*> _decoy;

};