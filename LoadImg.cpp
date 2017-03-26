#include "DxLib.h"
#include "LoadImg.h"

int PlayerImg;
int AmmoImg;
int BackImg;
int LogoImg;
int SelectMainMenuImg0;
int SelectMainMenuImg1;
int SelectMainMenuImg2;
int SelectMainMenuImg3;
int SelectMainMenuImg0N;
int SelectMainMenuImg1N;
int SelectMainMenuImg2N;
int SelectMainMenuImg3N;
int AboutImg;
int WeponImg;
int MBackImg;

/* ここで画像ロード処理のすべてを扱います。
新たな関数はLoadImg.hで宣言し、
別のcppファイルで画像ロードを行う際はLoadImg.hをincludeして下さい
ただし共通の変数にする場合はextern int各ccpで固有だが名前だけ同じ変数
にする場合は*/

//初期画像ロード処理
void LoadImg() {
	PlayerImg = LoadGraph("Asset/Player.png");
	WeponImg = LoadGraph("Asset/Wepon.png");
	AmmoImg = LoadGraph("Asset/Ammo.png");
	SelectMainMenuImg0 = LoadGraph("Asset/MenuSelect0.png");
	SelectMainMenuImg1 = LoadGraph("Asset/MenuSelect1.png");
	SelectMainMenuImg2 = LoadGraph("Asset/MenuSelect2.png");
	SelectMainMenuImg3 = LoadGraph("Asset/MenuSelect3.png");
	SelectMainMenuImg0N = LoadGraph("Asset/MenuSelect0N.png");
	SelectMainMenuImg1N = LoadGraph("Asset/MenuSelect1N.png");
	SelectMainMenuImg2N = LoadGraph("Asset/MenuSelect2N.png");
	SelectMainMenuImg3N = LoadGraph("Asset/MenuSelect3N.png");

}

//メインメニューの画像ロード・描画
void M_MenuLoadImg() {
	int BackImg = LoadGraph("Asset/MainMBack.png");
	int LogoImg = LoadGraph("Asset/Logo.png");
	//背景とロゴを描画
	DrawGraph(0, 0, BackImg, TRUE);
	DrawGraph(80, 30, LogoImg, TRUE);
}

//メインメニュー選択項目描画
/*これについては、メインメニューを分割する*/

//ゲームの背景ロード・描画
void GameBackLoadImg()
{
	BackImg = LoadGraph("Asset/back.png");
}

// プレイヤーを描画
/*これについては、Player.h並びにPlayer.cppに記述*/