#ifndef CSCENEGAME2_H
#define CSCENEGAME2_H
#include "CScene.h"

/*
�Q�[���̃V�[��
*/
//CScene�N���X���p������
class CSceneGame2 : public CScene {
public:

	char buf[10];

	float mFadeout;
	float mFadein;

	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

	EScene GetNextScene();
	//�f�X�g���N�^�̐錾
	~CSceneGame2();

};

#endif
