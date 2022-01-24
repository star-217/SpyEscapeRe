#include "Threatmap.h"

void ThreatMap::Initialize()
{
	_default_font = GraphicsDevice.CreateDefaultFont();
	_map_data	  = Map::GetMapData();
	_prev_mx	  = 0;
	_prev_my	  = 0;

	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < _map_data[y].size(); x++) {
			_threat_data_tracker[y].push_back(0);
			_threat_data_spy[y].push_back(0);
		}
	}

}

void ThreatMap::Update(Vector3 pos,std::string tag)
{
	if(tag == "TRACKER")
		CreateThreatMap(pos, _threat_data_tracker);
	else if(tag == "SPY")
		CreateThreatMap(pos, _threat_data_spy);
}

void ThreatMap::Draw()
{
#ifdef _DEBUG
	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < _threat_data_tracker[y].size(); x++)
		{
			SpriteBatch.DrawString(
				_default_font, Vector2(50 * x, 50 * y), Color(255, 0, 0),
				_T("%.4f"), _threat_data_spy[y][x]
			);
		}
	}
#endif
}

/**
 * @fn
 * �f�R�C�̋�����AI�ŏ������邽�߂̋��Ѓ}�b�v�𐶐�����֐��ł�
 * @param (pos) �v�Z���鑊���position
 * @param (data) �}�b�v�f�[�^
 * @detail �f�R�C�̏ꏊ�Ƒ���̏ꏊ�̋������v�Z��,�����0�`1�܂ł̒l�ɕϊ�����A���S���Y���ł�
 */
void ThreatMap::CreateThreatMap(Vector3 pos, std::vector<float>* data)
{
	int mx = (int)(pos.x / 50);
	int my = (int)(pos.y / 50);
	//���Ѓ}�b�v
	if (mx != _prev_mx || my != _prev_my) {
		float max = FLT_MIN;
		float min = FLT_MAX;
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < _map_data[y].size(); x++) {
				if (_map_data[y][x] == ' ' || _map_data[y][x] == '%') {
					data[y][x] = Vector3_Distance(pos, Vector3(x * 50, y * 50, 0));
					if (max < data[y][x])
					{
						max = data[y][x];
					}
					if (min > data[y][x])
					{
						min = data[y][x];
					}
				}
				else {
					data[y][x] = -1;	// �i�s�s��
				}
			}
		}
		float normal = max - min;
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < _map_data[y].size(); x++) {
				if (data[y][x] >= 0)
					data[y][x] = ((data[y][x] - min) / normal);
				else
					data[y][x] = 0;
			}
		}
		_prev_mx = mx; // ���O�ɂ������W��ۑ�����
		_prev_my = my; // ���O�ɂ������W��ۑ�����
	}
}

