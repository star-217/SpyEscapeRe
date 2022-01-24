#include "Threatmap.h"

void ThreatMap::Initialize()
{
	_default_font = GraphicsDevice.CreateDefaultFont();
	_map_data	  = Map::GetInstance().GetMapData();
	_prev_mx	  = 0;
	_prev_my	  = 0;

	for (int y = 0; y < _map_data.size(); y++) {
		for (int x = 0; x < _map_data[y].size(); x++) {
			_threat_data_tracker[y].push_back(0);
			_threat_data_spy[y].push_back(0);
			_threat_data[y].push_back(0);
		}
	}

}

void ThreatMap::Update()
{
	_threat_data_spy = CreateDistanceMap(_spy_pos);
	_threat_data_tracker = CreateDistanceMap(_tracker_pos);
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

std::vector<float>* ThreatMap::CreateTheatData(float ratio)
{
	const float ratio2 = 1.0f - ratio;

	for (int y = 0; y < _map_data.size(); y++) {
		for (int x = 0; x < _map_data[y].size(); x++) {
			_threat_data[y][x] = _threat_data_spy[y][x] * ratio + _threat_data_tracker[y][x] * ratio2;
			for (int i = PREV_MAX - 1; i > 0; i--) {
				_threat_data[_old_pos_y[i]][_old_pos_x[i]] = 0;//���O�ɒʂ����ꏊ�ɂ����Ȃ��悤�ɂ��邽��
			}
		}
	}

	return _threat_data;
}

/**
 * @fn
 * �f�R�C�̋�����AI�ŏ������邽�߂̋��Ѓ}�b�v�𐶐�����֐��ł�
 * @param (pos) �v�Z���鑊���position
 * @param (data) �}�b�v�f�[�^
 * @detail �f�R�C�̏ꏊ�Ƒ���̏ꏊ�̋������v�Z��,�����0�`1�܂ł̒l�ɕϊ�����A���S���Y���ł�
 */
std::vector<float>* ThreatMap::CreateDistanceMap(Vector3 pos)
{
	int mx = (int)(pos.x / 50);
	int my = (int)(pos.y / 50);
	//���Ѓ}�b�v
	if (mx != _prev_mx || my != _prev_my) {
		float max = FLT_MIN;
		float min = FLT_MAX;
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < _map_data[y].size(); x++) {
				if (_map_data[y][x] ==  ' ' || _map_data[y][x] == '%' ) {
					_threat_data[y][x] = Vector3_Distance(pos, Vector3(x * 50, y * 50, 0));
					if (max < _threat_data[y][x])
					{
						max = _threat_data[y][x];
					}
					if (min > _threat_data[y][x])
					{
						min = _threat_data[y][x];
					}
				}
				else {
					_threat_data[y][x] = -1;	// �i�s�s��
				}
			}
		}
		float normal = max - min;
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < _map_data[y].size(); x++) {
				if (_threat_data[y][x] >= 0)
					_threat_data[y][x] = ((_threat_data[y][x] - min) / normal);
				else
					_threat_data[y][x] = 0;
			}
		}
		_prev_mx = mx; // ���O�ɂ������W��ۑ�����
		_prev_my = my; // ���O�ɂ������W��ۑ�����
	}
}

