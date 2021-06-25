#include "DecoyManager.h"

DecoyManager::DecoyManager(): _wait_count{7,10,10,10,10,10},_ratio{0.3f ,0.4f ,0.5f ,0.2f ,0.1f ,0.3f }
{

}


void DecoyManager::Initialize(Vector3* positions)
{
	for (int i = 0; i < 6; i++) {
		_decoy[i].Initialize(positions[i], _ratio[i], _wait_count[i]);
	}

}

void DecoyManager::Update(ThreatMap map)
{
	for (int i = 0; i < 6; i++) {
		_decoy[i].Update(map);
	}
}

void DecoyManager::Draw()
{
	for (int i = 0; i < 6; i++) {
		_decoy[i].Draw();
	}
}

