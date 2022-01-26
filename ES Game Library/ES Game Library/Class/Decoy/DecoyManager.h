/**
 * @file  DecoyManager.h
 * @brief DecoyManager.cppのヘッダーファイル
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
	void SetSpy(HumanBase* spy);
	void SetTracker(HumanBase* tracker);
	void SetDecoyPosition(std::vector<Vector3>& positions);

	std::vector<Decoy*> GetBase() { return _decoy; }

private:

	std::vector<Decoy*> _decoy;

};