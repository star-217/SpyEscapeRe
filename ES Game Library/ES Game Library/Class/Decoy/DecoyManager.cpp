/**
 * @file  DecoyManager.cpp
 * @brief デコイを複数管理するためのマネージャー
 * @author 星寛文
 * @date 2021/04/20
 */
#include "DecoyManager.h"

DecoyManager::DecoyManager() :
	_wait_count{ 7, 10, 10, 10, 10, 10 },
	_ratio{ 0.3f, 0.4f, 0.5f, 0.2f, 0.1f, 0.3f }
{

}


void DecoyManager::Initialize()
{
	for (int i = 0; i < DECOY_MAX; i++)
	{
		_decoy.push_back(new Decoy);
		_decoy[i]->Initialize();
		_decoy[i]->SetPriorityRatio(_ratio[i]);
		_decoy[i]->SetWaitCount(_wait_count[i]);
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

