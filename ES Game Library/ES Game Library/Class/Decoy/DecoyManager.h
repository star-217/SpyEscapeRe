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

	void Initialize();
	void Update();
	void Draw();
	void SetSpy(HumanBase* spy);
	void SetTracker(HumanBase* tracker);

	std::vector<Decoy*> GetBase() { return _decoy; }

private:
	enum
	{
		DECOY_MAX = 6
	};

	std::vector<Decoy*> _decoy;

	float _ratio[DECOY_MAX];

	int _wait_count[DECOY_MAX];

};