#include "DxLib.h"
#include "LoadImg.h"

/* ここで画像ロード処理のすべてを扱います。
新たな関数はLoadImg.hで宣言し、
別のcppファイルで画像ロードを行う際はLoadImg.hをincludeして下さい
ただし共通の変数にする場合はextern int各ccpで固有だが名前だけ同じ変数
にする場合は*/

//初期画像ロード処理
void LoadImg() {
	int PlayerImg = LoadGraph("Player.png");
	int WeponImg = LoadGraph("Wepon.png");
	int AmmoImg = LoadGraph("Ammo.png");
	int SelectMainMenuImg0 = LoadGraph("MenuSelect0.png");
	int SelectMainMenuImg1 = LoadGraph("MenuSelect1.png");
	int SelectMainMenuImg2 = LoadGraph("MenuSelect2.png");
	int SelectMainMenuImg3 = LoadGraph("MenuSelect3.png");
	int SelectMainMenuImg0N = LoadGraph("MenuSelect0N.png");
	int SelectMainMenuImg1N = LoadGraph("MenuSelect1N.png");
	int SelectMainMenuImg2N = LoadGraph("MenuSelect2N.png");
	int SelectMainMenuImg3N = LoadGraph("MenuSelect3N.png");
}

/*メインメニューの画像ロード・描画
void M_MenuLoadImg() {
	int BackImg = LoadGraph("MainMBack.png");
	int LogoImg = LoadGraph("Logo.png");
	//背景とロゴを描画
	DrawGraph(0, 0, BackImg, TRUE);
	DrawGraph(80, 30, LogoImg, TRUE);
}*/

//メインメニュー選択項目描画


//ゲームの背景ロード・描画
void GameBackLoadImg()
{
	BackImg = LoadGraph("back.png");
}

// プレイヤーを描画

