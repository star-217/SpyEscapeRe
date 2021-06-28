#include "Collision.h"

void Collision::Update(Spy spy, Tracker tracker, DecoyManager decoy)
{
	if (tracker.GetCollision().Intersect(spy.GetCollision()))
	{
		spy.AttackHit();
	}

	if (tracker.GetCollision().Intersect(decoy.GetBase()->GetCollision()))
	{
		tracker.Stun();
	}
}
