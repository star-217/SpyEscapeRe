/**
 * @file  DecoyManager.h
 * @brief DecoyManager.cppのヘッダーファイル
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../ESGLib.h"
#include "DecoyBase.h"

class DecoyManager
{
public:
	DecoyManager();
	virtual ~DecoyManager() {};

	void Initialize(std::vector<cstring>& ,Vector3* positions);
	void Update(ThreatMap&);
	void Draw();
	std::vector<DecoyBase*> GetBase() { return _decoy; }

private:
	enum
	{
		DECOY_MAX = 6
	};

	std::vector<DecoyBase*> _decoy;

	float _ratio[DECOY_MAX];

	int _wait_count[DECOY_MAX];

};