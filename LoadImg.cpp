#include "DxLib.h"
#include "LoadImg.h"

/* �����ŉ摜���[�h�����̂��ׂĂ������܂��B
�V���Ȋ֐���LoadImg.h�Ő錾���A
�ʂ�cpp�t�@�C���ŉ摜���[�h���s���ۂ�LoadImg.h��include���ĉ�����
���������ʂ̕ϐ��ɂ���ꍇ��extern int�eccp�ŌŗL�������O���������ϐ�
�ɂ���ꍇ��*/

//�����摜���[�h����
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

/*���C�����j���[�̉摜���[�h�E�`��
void M_MenuLoadImg() {
	int BackImg = LoadGraph("MainMBack.png");
	int LogoImg = LoadGraph("Logo.png");
	//�w�i�ƃ��S��`��
	DrawGraph(0, 0, BackImg, TRUE);
	DrawGraph(80, 30, LogoImg, TRUE);
}*/

//���C�����j���[�I�����ڕ`��


//�Q�[���̔w�i���[�h�E�`��
void GameBackLoadImg()
{
	BackImg = LoadGraph("back.png");
}

// �v���C���[��`��

