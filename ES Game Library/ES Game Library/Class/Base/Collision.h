#pragma once

#include "../../ESGLib.h"
#include "GameState.h"
#include "../Spy/Spy.h"
#include "../Tracker/Tracker.h"
#include "../Decoy/DecoyManager.h"

class Collision
{
public:
	void Update(Spy,Tracker,DecoyManager);


private:
	enum
	{
		DEFAULT,
		DECOYHIT,
		TRACKERWIN
	};

};