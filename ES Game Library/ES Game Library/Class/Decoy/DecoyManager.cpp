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


void DecoyManager::Initialize(std::vector<cstring>& map_data,Vector3* positions)
{
	for (int i = 0; i < 6; i++)
	{
		_decoy.push_back(new DecoyBase);
		_decoy[i]->SetPriorityRatio(_ratio[i]);
		_decoy[i]->SetWaitCount(_wait_count[i]);
	}
}

void DecoyManager::Update(ThreatMap& map)
{
	for (int i = 0; i < _decoy.size(); i++)
	{
		_decoy[i]->Update(map);
	}
}

void DecoyManager::Draw()
{
	for (int i = 0; i < _decoy.size(); i++)
	{
		_decoy[i]->Draw();
	}
}

