#include "DxLib.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int x, y, addX, addY;
	int RectX, RectY, SizeX, SizeY;

	// モニタの情報を取得
	RectX = 100, RectY = 100, SizeX = 640, SizeY = 480;

	// ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	// タスクバーなし設定
	SetWindowStyleMode(1);

	// ウィンドウの解像度をモニタの解像度と同じにする
	SetGraphMode(640, 480, 32);

	// ウィンドウの位置をセット
	SetWindowPosition(RectX, RectY);

	// ＤＸライブラリの初期化
	if (DxLib_Init() < 0) return -1;



	// メインループ
	x = 0;
	y = 0;
	addX = 16;
	addY = 16;
	while (ProcessMessage() == 0 && !CheckHitKeyAll())
	{
		// 画面内を跳ね回る
		x += addX;
		y += addY;
		if (x < 0 || x > SizeX - 64) addX = -addX;
		if (y < 0 || y > SizeY - 64) addY = -addY;

		// 画面のクリア
		ClearDrawScreen();

		// 四角形の描画
		DrawBox(x, y, x + 64, y + 64, GetColor(255, 255, 255), TRUE);

		// 裏画面の内容を表画面に反映
		ScreenFlip();
	}



	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}