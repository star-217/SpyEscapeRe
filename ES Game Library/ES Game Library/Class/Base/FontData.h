/**
 * @file Collision.h
 * @brief �f�o�b�O���Ɏg�p����t�H���g�f�[�^
 * @author ������
 * @date 2021/04/20
 */
#ifdef DEBUG

#pragma once

#include "../../ESGLib.h"

class FontData
{
public:
	static FontData& GetInstance()
	{
		static FontData instance;
		return instance;
	}

	FONT GetFont()
	{
		if(!DefaultFont)
			DefaultFont = GraphicsDevice.CreateDefaultFont();
		return DefaultFont;
	}
private:
	FONT DefaultFont = nullptr;
};

#endif // DEBUG
