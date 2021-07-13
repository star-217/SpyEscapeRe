#pragma once

#include "../../ESGLib.h"

class Spy;
class Tracker;
class DecoyManager;

class Collision
{
public:
	Collision() = default;
	virtual ~Collision() {}

	void Update(Spy&, Tracker&, DecoyManager&);

private:

};