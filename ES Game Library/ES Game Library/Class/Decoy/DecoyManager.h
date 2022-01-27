/**
 * @file  DecoyManager.h
 * @brief デコイを複数管理するためのマネージャークラス
 * @author 星寛文
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

	//Decoyクラスを取る関数
	std::vector<Decoy*> GetBase() { return _decoy; }

private:
	std::vector<Decoy*> _decoy;

};