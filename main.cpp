#include "DxLib.h"
#include "include\define.h"
#include "include\Map\Map.h"
#include "include\GameEngine\GameEngine.h"
#include "include\define.h"

//-------------------------------------------------------------------------------------------------------------------
//メインループの処理をまとめる
int ProcessLoop() {
	if (ScreenFlip() != 0) return -1;
	if (ProcessMessage() != 0) return -1;
	if (ClearDrawScreen() != 0) return -1;
	return 0;
}
//-------------------------------------------------------------------------------------------------------------------
//初期化関連をまとめる
void DXinit() {
	SetOutApplicationLogValidFlag(FALSE);			//ログ消し
	SetMainWindowText("Test");						//ウインドウタイトルを変更
	SetGraphMode(800, 600, 16);						//画面解像度、色深度バッファ？変更
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);		//画面サイズ変更
	ChangeWindowMode(TRUE);							//ウィンドウモード変更
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);		//初期化
	DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);	//裏画面設定
}
//-------------------------------------------------------------------------------------------------------------------





int Object::uid_ = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DXinit();
	ge->init();


	while (ProcessLoop() == 0) {
		ge->update();
		ge->render();
	};

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}

