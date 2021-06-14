#include "DecoyManager.h"

DecoyManager::DecoyManager(): wait_count{7,10,10,10,10,10},ratio{0.3f ,0.4f ,0.5f ,0.7f ,0.8f ,0.3f }
{

}


void DecoyManager::Initialize(Vector3* positions)
{
	for (int i = 0; i < 6; i++) {
		decoy[i].Initialize(positions[i], ratio[i], wait_count[i]);
	}

}

void DecoyManager::Update(ThreatMap map)
{
//	for (int i = 0; i < 6; i++) {
		decoy[0].Update(map);
//	}
}

void DecoyManager::Draw()
{
	//for (int i = 0; i < 6; i++) {
	//	decoy[i].Draw();
	//}
	decoy[0].Draw();
}

