#ifndef CSCENEGAME2_H
#define CSCENEGAME2_H
#include "CScene.h"

/*
�Q�[���̃V�[��
*/
//CScene�N���X���p������
class CSceneGame2 : public CScene {
public:

	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

	EScene GetNextScene();
	//�f�X�g���N�^�̐錾
	~CSceneGame2();

	static int Time;
	char buf[10];

	static int mCharaHp1store;
	static int mCharaHp2store;
	static int mSpstore;
	static int mCombostore;
	static int mScorestore;
	float mFadeout;	//�t�F�[�h�A�E�g
	float mFadein;	//�t�F�[�h�C��
};

#endif
