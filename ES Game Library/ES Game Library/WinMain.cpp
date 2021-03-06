/*
================================================================================
					 オブジェクト指向＆＆ゲームプログラミング
	     Copyright (c) 2011 Human Academy Sendai. All rights reserved.
================================================================================

 【対象ＯＳ】
     Microsoft Windows 7以降

 【コンパイラ】
     Microsoft VisualC++ 2013

 【プログラム】
	 WinMain.cpp
				WinMain関数

 【バージョン】
	 * Version    2015.10.00      2015/08/28  03:10:03

================================================================================
*/

//------------------------------------------------------------------------------
//	インクルードファイル
//------------------------------------------------------------------------------
#include "Framework/GameApp.hpp"

//------------------------------------------------------------------------------
//	WinMain
//------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nShowCmd)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if(GameApp().Initialize(hInstance) == false)
		return -1;

	const int return_code = GameApp().Run();
	_CrtDumpMemoryLeaks();

	return return_code;
}
