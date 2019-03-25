#include "DxLib.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int x, y, addX, addY;
	int RectX, RectY, SizeX, SizeY;

	// ���j�^�̏����擾
	RectX = 100, RectY = 100, SizeX = 640, SizeY = 480;

	// �E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	// �^�X�N�o�[�Ȃ��ݒ�
	SetWindowStyleMode(1);

	// �E�B���h�E�̉𑜓x�����j�^�̉𑜓x�Ɠ����ɂ���
	SetGraphMode(640, 480, 32);

	// �E�B���h�E�̈ʒu���Z�b�g
	SetWindowPosition(RectX, RectY);

	// �c�w���C�u�����̏�����
	if (DxLib_Init() < 0) return -1;



	// ���C�����[�v
	x = 0;
	y = 0;
	addX = 16;
	addY = 16;
	while (ProcessMessage() == 0 && !CheckHitKeyAll())
	{
		// ��ʓ��𒵂ˉ��
		x += addX;
		y += addY;
		if (x < 0 || x > SizeX - 64) addX = -addX;
		if (y < 0 || y > SizeY - 64) addY = -addY;

		// ��ʂ̃N���A
		ClearDrawScreen();

		// �l�p�`�̕`��
		DrawBox(x, y, x + 64, y + 64, GetColor(255, 255, 255), TRUE);

		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}



	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}