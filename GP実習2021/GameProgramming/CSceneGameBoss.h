#ifndef CSCENEGAMEBOSS_H
#define CSCENEGAMEBOSS_H
#include "CScene.h"

/*
�Q�[���̃V�[��
*/
//CScene�N���X���p������
class CSceneGameBoss : public CScene {
public:

	char buf[10];

	float mFadeout;
	float mFadein;

	static int mBossCount;

	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

	EScene GetNextScene();
	//�f�X�g���N�^�̐錾
	~CSceneGameBoss();

};

#endif
