#include "DxLib.h"
 
int PlayerX, PlayerY;
int WeponX, WeponY;
//弾幕は数が多いので配列を使用
int AmmoX[20], AmmoY[20];
int PlayerGraph;
int WeponGraph;
int AmmoGraph;
int BackGraph;
int LogoGraph;
int SelectMainMenuGraph0;
int SelectMainMenuGraph1;
int SelectMainMenuGraph2;
int SelectMainMenuGraph3;
int SelectMainMenuGraph0N;
int SelectMainMenuGraph1N;
int SelectMainMenuGraph2N;
int SelectMainMenuGraph3N;
int MouseX, MouseY;
int SelectMainMenu = 0;
int SelectSetting = 0;
int AboutGraph;
int UseFont;

//乱数用の変数
int r;

//これは儀式のようなものなので考えずに書いとけばいい
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	int Key;

	// 画面モードのセット
	SetGraphMode(640, 480, 16);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)	// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}
	ChangeFont("おつとめフォント");

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	//使用する画像をロード
	PlayerGraph = LoadGraph("Player.png");
	WeponGraph = LoadGraph("Wepon.png");
	AmmoGraph = LoadGraph("Ammo.png");
	SelectMainMenuGraph0 = LoadGraph("MenuSelect0.png");
	SelectMainMenuGraph1 = LoadGraph("MenuSelect1.png");
	SelectMainMenuGraph2 = LoadGraph("MenuSelect2.png");
	SelectMainMenuGraph3 = LoadGraph("MenuSelect3.png");
	SelectMainMenuGraph0N = LoadGraph("MenuSelect0N.png");
	SelectMainMenuGraph1N = LoadGraph("MenuSelect1N.png");
	SelectMainMenuGraph2N = LoadGraph("MenuSelect2N.png");
	SelectMainMenuGraph3N = LoadGraph("MenuSelect3N.png");



	//メインメニューのループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_Z) == 0)
	{
		MENU:
		BackGraph = LoadGraph("MainMBack.png");
		LogoGraph = LoadGraph("Logo.png");
		//背景とロゴを描画
		DrawGraph(0, 0, BackGraph, TRUE);
		DrawGraph(80, 30, LogoGraph, TRUE);
		// 続行用のキーを表示
		DrawString(0, 0, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n選択はZキーです。\n上下キーで項目を変更。", GetColor(255, 255, 255));
		//項目を選択
		if ( CheckHitKey(KEY_INPUT_UP) == 1 )
		{
			SelectMainMenu = SelectMainMenu - 1;
		}
		else if ( CheckHitKey(KEY_INPUT_DOWN) == 1 )
		{
			SelectMainMenu = SelectMainMenu + 1;
		}
		else
		{
			SelectMainMenu = SelectMainMenu;
		}

		if (0 > SelectMainMenu) 
		{
			SelectMainMenu = 0;
		}
		else if (SelectMainMenu > 3)
		{
			SelectMainMenu = 3;
		}
		//選択項目を描画
		if (SelectMainMenu == 0)
		{
			DrawGraph(240, 170, SelectMainMenuGraph0, TRUE);
			DrawGraph(240, 250, SelectMainMenuGraph1N, TRUE);
			DrawGraph(240, 330, SelectMainMenuGraph2N, TRUE);
			DrawGraph(240, 410, SelectMainMenuGraph3N, TRUE);
		}
		else if (SelectMainMenu == 1)
		{
			DrawGraph(240, 170, SelectMainMenuGraph0N, TRUE);
			DrawGraph(240, 250, SelectMainMenuGraph1, TRUE);
			DrawGraph(240, 330, SelectMainMenuGraph2N, TRUE);
			DrawGraph(240, 410, SelectMainMenuGraph3N, TRUE);
		}
		else if (SelectMainMenu == 2)
		{
			DrawGraph(240, 170, SelectMainMenuGraph0N, TRUE);
			DrawGraph(240, 250, SelectMainMenuGraph1N, TRUE);
			DrawGraph(240, 330, SelectMainMenuGraph2, TRUE);
			DrawGraph(240, 410, SelectMainMenuGraph3N, TRUE);
		}
		else if (SelectMainMenu == 3)
		{
			DrawGraph(240, 170, SelectMainMenuGraph0N, TRUE);
			DrawGraph(240, 250, SelectMainMenuGraph1N, TRUE);
			DrawGraph(240, 330, SelectMainMenuGraph2N, TRUE);
			DrawGraph(240, 410, SelectMainMenuGraph3, TRUE);
		}
		else
		{
			DrawGraph(240, 170, SelectMainMenuGraph0N, TRUE);
			DrawGraph(240, 250, SelectMainMenuGraph1N, TRUE);
			DrawGraph(240, 330, SelectMainMenuGraph2N, TRUE);
			DrawGraph(240, 410, SelectMainMenuGraph3N, TRUE);
		}
		// 裏画面の内容を表画面に反映させる
		ScreenFlip();
		Sleep(75);
	}

		if (SelectMainMenu == 0)
		{

			BackGraph = LoadGraph("back.png");

			// キャラクターの初期位置をセット
			PlayerX = 10;
			PlayerY = 10;
			WeponX = PlayerX + 30;
			WeponY = PlayerY + 1;
			//乱数の初期値用の時間データを得るとこ
			DATEDATA Date;
			GetDateTime(&Date);
			int SRand(int Sec);
			//弾幕の位置を乱数で決定する
			for (int i = 0; i < 20; i++)
			{
				AmmoY[i] = GetRand(300);
				AmmoX[i] = GetRand(460);
			}


			// ループ
			while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_X) == 0)
			{

				//下に落ちる
				for (int i = 0; i < 20; i++)
				{
					AmmoY[i] = AmmoY[i] + 2;
				}

				// キー入力取得
				Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

				// 上を押していたら上に進む
				if (Key & PAD_INPUT_UP) PlayerY -= 3;

				// 下を押していたら下に進む
				if (Key & PAD_INPUT_DOWN) PlayerY += 3;

				// 右を押していたら右に進む
				if (Key & PAD_INPUT_RIGHT) PlayerX += 3;

				// 左を押していたら左に進む
				if (Key & PAD_INPUT_LEFT) PlayerX -= 3;
				//プレイヤーの行動制限
				if (PlayerX < 20) PlayerX = 21;

				if (PlayerX > 620) PlayerX = 619;

				if (PlayerY < 20) PlayerY = 21;

				if (PlayerY > 460) PlayerY = 459;

				//自機に随伴するやつ（お札とか？）
				WeponX = PlayerX + 30;
				WeponY = PlayerY + 1;

				//玉が下まで行ったら上に戻す
				for (int i = 0; i < 20; i++)
				{
					if (AmmoY[i] > 470) AmmoY[i] = 10, AmmoX[i] = GetRand(460);
				}

				// 画面を初期化する
				ClearDrawScreen();

				// プレイヤーを描画する
				DrawGraph(0, 0, BackGraph, TRUE);
				DrawGraph(PlayerX, PlayerY, PlayerGraph, TRUE);
				DrawGraph(WeponX, WeponY, WeponGraph, TRUE);
				//敵の弾幕を表示
				for (int i = 0; i < 20; i++)
				{
					DrawGraph(AmmoX[i], AmmoY[i], AmmoGraph, TRUE);
				}
				//説明を追加
				DrawString(0, 0, "\n移動は矢印キー\n終了するにはXキーを押す。", GetColor(255, 255, 255));

				// 裏画面の内容を表画面に反映させる
				ScreenFlip();
			}
			goto MENU;
		}
		else if (SelectMainMenu == 1)
		{
			BackGraph = LoadGraph("MainMBack.png");
			DrawGraph(0, 0, BackGraph, TRUE);

			while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_X) == 0)
			{

				if (CheckHitKey(KEY_INPUT_UP) == 1)
				{
					SelectSetting = SelectSetting - 1;
				}
				else if (CheckHitKey(KEY_INPUT_DOWN) == 1)
				{
					SelectSetting = SelectSetting + 1;
				}
				else
				{
					SelectSetting = SelectSetting;
				}

				if (0 > SelectSetting)
				{
					SelectSetting = 0;
				}
				else if (SelectSetting > 2)
				{
					SelectSetting = 2;
				}


				if (SelectSetting == 0)
				{
					DrawString(0, 5, "設定項目１", GetColor(255, 0, 63));
					DrawString(0, 20, "設定項目２", GetColor(255, 255, 255));
					DrawString(0, 35, "設定項目３", GetColor(255, 255, 255));
				}
				else if (SelectSetting == 1)
				{
					DrawString(0, 5, "設定項目１", GetColor(255, 255, 255));
					DrawString(0, 20, "設定項目２", GetColor(255, 0, 63));
					DrawString(0, 35, "設定項目３", GetColor(255, 255, 255));
				}
				else if (SelectSetting == 2)
				{
					DrawString(0, 5, "設定項目１", GetColor(255, 255, 255));
					DrawString(0, 20, "設定項目２", GetColor(255, 255, 255));
					DrawString(0, 35, "設定項目３", GetColor(255, 0, 63));
				}
				else
				{
					DrawString(0, 5, "設定項目１", GetColor(255, 255, 255));
					DrawString(0, 20, "設定項目２", GetColor(255, 255, 255));
					DrawString(0, 35, "設定項目３", GetColor(255, 255, 255));
				}
				ScreenFlip();
				Sleep(75);
			}
			goto MENU;
		}
		else if (SelectMainMenu == 2)
		{
			AboutGraph = LoadGraph("About.png");
			while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_X) == 0)
			{
				DrawGraph(0, 0, AboutGraph, TRUE);
				DrawString(0, 0, "このゲームのバージョンは××××です\nほかにもここに著作とかいろいろ情報を載せる予定\n\n終了するにはZキー", GetColor(255, 255, 255));
				// 裏画面の内容を表画面に反映させる
				ScreenFlip();
			}
			goto MENU;
		}
		else if (SelectMainMenu == 3)
		{
			goto END;
		}
		END:
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;					// ソフトの終了
}