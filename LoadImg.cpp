#include "DxLib.h"
#include "LoadImg.h"

/* �����ŉ摜���[�h�����̂��ׂĂ������܂��B
�V���Ȋ֐���LoadImg.h�Ő錾���A
�ʂ�cpp�t�@�C���ŉ摜���[�h���s���ۂ�LoadImg.h��include���ĉ����� */

//�����摜���[�h����
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

//���C�����j���[�̉摜���[�h�E�`��
void M_MenuLoadImg() {
	BackImg = LoadGraph("MainMBack.png");
	LogoImg = LoadGraph("Logo.png");
	//�w�i�ƃ��S��`��
	DrawGraph(0, 0, BackImg, TRUE);
	DrawGraph(80, 30, LogoImg, TRUE);
}

//���C�����j���[�I�����ڕ`��


//�Q�[���̔w�i���[�h�E�`��
void GameBackLoadImg()
{
	BackImg = LoadGraph("back.png");
}

// �v���C���[��`��

