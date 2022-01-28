/**
 * @file  DecoyManager.cpp
 * @brief デコイを複数管理するためのマネージャークラス
 * @author 星寛文
 * @date 2021/04/20
 */
#include "DecoyManager.h"

/**
  * @fn
  * 初期化
  * @param (num_decoy) decoyの数
  */
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

/**
  * @fn
  * 更新処理
  */
void DecoyManager::Update()
{
	for (int i = 0; i < _decoy.size(); i++)
	{
		_decoy[i]->Update();
	}
}

/**
  * @fn
  * 描画
  */
void DecoyManager::Draw()
{
	for (int i = 0; i < _decoy.size(); i++)
	{
		_decoy[i]->Draw();
	}
}
void DecoyManager::SetMapData(std::vector<cstring>& map_data)
{
	for (int i = 0; i < _decoy.size(); i++)
	{
		_decoy[i]->SetMapData(map_data);
		_decoy[i]->ThreatMapDataInit();
	}

}
/**
 * @fn
 * 脅威マップの初期化をするためのデータを渡す
 * @param (human) 渡したいキャラクタークラス
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
 * デコイが最初にいる座標を設定する
 * @param (positions) 座標データ
 */
void DecoyManager::SetPosition(std::vector<Vector3>& positions)
{
	for (int i = 0; i < _decoy.size(); i++)
	{
		_decoy[i]->SetPosition(positions[i]);
	}
}

void DecoyManager::SetTag(std::string tag)
{
	for (int i = 0; i < _decoy.size(); i++)
	{
		_decoy[i]->SetTag(tag);
	}
}

