#ifndef CKEY_H
#define CKEY_H

//GetKeyState�֐��̃w�b�_�t�@�C��
#include <Windows.h>
/*
CKey�N���X
�L�[�{�[�h���͂��擾����
*/
class CKey {
public:
	static bool Flg[256]; //�L�[��������Ă��鎞��true
	/*
	Push��static(�X�^�e�B�b�N)���\�b�h
	key�̒l�̃L�[��������Ă����true���A
	������Ă��Ȃ����false��߂�
	*/
	static bool Push(char key);
	//�L�[�������ꂽ�u�Ԃ���true��Ԃ�
	static bool Once(char key);
};

#endif
