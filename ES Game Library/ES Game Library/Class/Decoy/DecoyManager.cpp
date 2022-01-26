/**
 * @file  DecoyManager.cpp
 * @brief デコイを複数管理するためのマネージャー
 * @author 星寛文
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

void DecoyManager::SetSpy(HumanBase* spy)
{
	for (int i = 0; i < _decoy.size(); i++)
	{
		_decoy[i]->SetSpyPos(spy->GetPosition());
	}
}

void DecoyManager::SetTracker(HumanBase* tracker)
{
	for (int i = 0; i < _decoy.size(); i++)
	{
		_decoy[i]->SetTrackerPos(tracker->GetPosition());
	}
}

void DecoyManager::SetDecoyPosition(std::vector<Vector3>& positions)
{
	for (int i = 0; i < _decoy.size(); i++)
	{
		_decoy[i]->SetDecoyPos(positions[i]);
	}
}

