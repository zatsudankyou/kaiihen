#include "DxLib.h"
 
int PlayerX, PlayerY;
int WeponX, WeponY;
//�e���͐��������̂Ŕz����g�p
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

//�����p�̕ϐ�
int r;

//����͋V���̂悤�Ȃ��̂Ȃ̂ōl�����ɏ����Ƃ��΂���
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	int Key;

	// ��ʃ��[�h�̃Z�b�g
	SetGraphMode(640, 480, 16);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)	// �c�w���C�u��������������
	{
		return -1;				// �G���[���N�����璼���ɏI��
	}
	ChangeFont("���Ƃ߃t�H���g");

	// �`����ʂ𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	//�g�p����摜�����[�h
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



	//���C�����j���[�̃��[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_Z) == 0)
	{
		MENU:
		BackGraph = LoadGraph("MainMBack.png");
		LogoGraph = LoadGraph("Logo.png");
		//�w�i�ƃ��S��`��
		DrawGraph(0, 0, BackGraph, TRUE);
		DrawGraph(80, 30, LogoGraph, TRUE);
		// ���s�p�̃L�[��\��
		DrawString(0, 0, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n�I����Z�L�[�ł��B\n�㉺�L�[�ō��ڂ�ύX�B", GetColor(255, 255, 255));
		//���ڂ�I��
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
		//�I�����ڂ�`��
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
		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();
		Sleep(75);
	}

		if (SelectMainMenu == 0)
		{

			BackGraph = LoadGraph("back.png");

			// �L�����N�^�[�̏����ʒu���Z�b�g
			PlayerX = 10;
			PlayerY = 10;
			WeponX = PlayerX + 30;
			WeponY = PlayerY + 1;
			//�����̏����l�p�̎��ԃf�[�^�𓾂�Ƃ�
			DATEDATA Date;
			GetDateTime(&Date);
			int SRand(int Sec);
			//�e���̈ʒu�𗐐��Ō��肷��
			for (int i = 0; i < 20; i++)
			{
				AmmoY[i] = GetRand(300);
				AmmoX[i] = GetRand(460);
			}


			// ���[�v
			while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_X) == 0)
			{

				//���ɗ�����
				for (int i = 0; i < 20; i++)
				{
					AmmoY[i] = AmmoY[i] + 2;
				}

				// �L�[���͎擾
				Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

				// ��������Ă������ɐi��
				if (Key & PAD_INPUT_UP) PlayerY -= 3;

				// ���������Ă����牺�ɐi��
				if (Key & PAD_INPUT_DOWN) PlayerY += 3;

				// �E�������Ă�����E�ɐi��
				if (Key & PAD_INPUT_RIGHT) PlayerX += 3;

				// ���������Ă����獶�ɐi��
				if (Key & PAD_INPUT_LEFT) PlayerX -= 3;
				//�v���C���[�̍s������
				if (PlayerX < 20) PlayerX = 21;

				if (PlayerX > 620) PlayerX = 619;

				if (PlayerY < 20) PlayerY = 21;

				if (PlayerY > 460) PlayerY = 459;

				//���@�ɐ��������i���D�Ƃ��H�j
				WeponX = PlayerX + 30;
				WeponY = PlayerY + 1;

				//�ʂ����܂ōs�������ɖ߂�
				for (int i = 0; i < 20; i++)
				{
					if (AmmoY[i] > 470) AmmoY[i] = 10, AmmoX[i] = GetRand(460);
				}

				// ��ʂ�����������
				ClearDrawScreen();

				// �v���C���[��`�悷��
				DrawGraph(0, 0, BackGraph, TRUE);
				DrawGraph(PlayerX, PlayerY, PlayerGraph, TRUE);
				DrawGraph(WeponX, WeponY, WeponGraph, TRUE);
				//�G�̒e����\��
				for (int i = 0; i < 20; i++)
				{
					DrawGraph(AmmoX[i], AmmoY[i], AmmoGraph, TRUE);
				}
				//������ǉ�
				DrawString(0, 0, "\n�ړ��͖��L�[\n�I������ɂ�X�L�[�������B", GetColor(255, 255, 255));

				// ����ʂ̓��e��\��ʂɔ��f������
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
					DrawString(0, 5, "�ݒ荀�ڂP", GetColor(255, 0, 63));
					DrawString(0, 20, "�ݒ荀�ڂQ", GetColor(255, 255, 255));
					DrawString(0, 35, "�ݒ荀�ڂR", GetColor(255, 255, 255));
				}
				else if (SelectSetting == 1)
				{
					DrawString(0, 5, "�ݒ荀�ڂP", GetColor(255, 255, 255));
					DrawString(0, 20, "�ݒ荀�ڂQ", GetColor(255, 0, 63));
					DrawString(0, 35, "�ݒ荀�ڂR", GetColor(255, 255, 255));
				}
				else if (SelectSetting == 2)
				{
					DrawString(0, 5, "�ݒ荀�ڂP", GetColor(255, 255, 255));
					DrawString(0, 20, "�ݒ荀�ڂQ", GetColor(255, 255, 255));
					DrawString(0, 35, "�ݒ荀�ڂR", GetColor(255, 0, 63));
				}
				else
				{
					DrawString(0, 5, "�ݒ荀�ڂP", GetColor(255, 255, 255));
					DrawString(0, 20, "�ݒ荀�ڂQ", GetColor(255, 255, 255));
					DrawString(0, 35, "�ݒ荀�ڂR", GetColor(255, 255, 255));
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
				DrawString(0, 0, "���̃Q�[���̃o�[�W�����́~�~�~�~�ł�\n�ق��ɂ������ɒ���Ƃ����낢������ڂ���\��\n\n�I������ɂ�Z�L�[", GetColor(255, 255, 255));
				// ����ʂ̓��e��\��ʂɔ��f������
				ScreenFlip();
			}
			goto MENU;
		}
		else if (SelectMainMenu == 3)
		{
			goto END;
		}
		END:
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;					// �\�t�g�̏I��
}