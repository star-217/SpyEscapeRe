#include "Collision.h"

#include "../Spy/Spy.h"
#include "../Tracker/Tracker.h"
#include "../Decoy/DecoyManager.h"

void Collision::Update(Spy& spy, Tracker& tracker, DecoyManager& decoy)
{
	auto tracker_collision = tracker.GetCollision();
	if (tracker_collision.Intersect(spy.GetCollision()))
	{
		spy.AttackHit();
		return;
	}

	if (tracker_collision.Intersect(decoy.GetBase()->GetCollision()))
	{
		tracker.Stun();
	}
}
