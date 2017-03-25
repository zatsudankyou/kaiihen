#include "DxLib.h"
#include "LoadImg.h"

/* ここで画像ロード処理のすべてを扱います。
新たな関数はLoadImg.hで宣言し、
別のcppファイルで画像ロードを行う際はLoadImg.hをincludeして下さい */

//初期画像ロード処理
void LoadImg() {
	PlayerImg = LoadGraph("Player.png");
	WeponImg = LoadGraph("Wepon.png");
	AmmoImg = LoadGraph("Ammo.png");
	SelectMainMenuImg0 = LoadGraph("MenuSelect0.png");
	SelectMainMenuImg1 = LoadGraph("MenuSelect1.png");
	SelectMainMenuImg2 = LoadGraph("MenuSelect2.png");
	SelectMainMenuImg3 = LoadGraph("MenuSelect3.png");
	SelectMainMenuImg0N = LoadGraph("MenuSelect0N.png");
	SelectMainMenuImg1N = LoadGraph("MenuSelect1N.png");
	SelectMainMenuImg2N = LoadGraph("MenuSelect2N.png");
	SelectMainMenuImg3N = LoadGraph("MenuSelect3N.png");
}

//メインメニューの画像ロード・描画
void M_MenuLoadImg() {
	BackImg = LoadGraph("MainMBack.png");
	LogoImg = LoadGraph("Logo.png");
	//背景とロゴを描画
	DrawGraph(0, 0, BackImg, TRUE);
	DrawGraph(80, 30, LogoImg, TRUE);
}

//メインメニュー選択項目描画


//ゲームの背景ロード・描画
void GameBackLoadImg()
{
	BackImg = LoadGraph("back.png");
}

// プレイヤーを描画

