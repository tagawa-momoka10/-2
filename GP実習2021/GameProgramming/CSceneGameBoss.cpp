#include "CSceneGame.h"
#include "CSceneGame2.h"
#include "CSceneGameBoss.h"
#include "CTexture.h"
#include "CMap.h"
#include "CKey.h"
#include "CRectangle.h"
#include "CPlayer.h"
#include "CEnemyBoss.h"
#include "CText.h"
#include "TaskManager.h"
#include "DrawTaskManager.h"
#include "CPlayerHP.h"
#include "CIcon1.h"
#include "CIcon2.h"
#include "TaskInclude.h"
#include "CScore.h"
#include "CSound.h"
#include "CItem1.h"
#include "CItem2.h"
#include "CItem3.h"
#include "CItem4.h"
#include "CSmg.h"
#include "CEnemy.h"
#include "CEnemy2.h"

#define INITIALIZE 0	//������
#define TIME 200*60
int CSceneGameBoss::mBossCount = 0;

extern CTexture TextureChara1;
//extern CTexture TextureBos_background;//�{�X�w�i

//CSound Bgm;


void CSceneGameBoss::Init() {
	//�V�[���̐ݒ�
	mScene = EGAMEBOSS;

	mFadeout = 0.0;
	mFadein = 1.0;

	TextureChara1.Load("resource\\ch101.tga");
	//TextureBos_background.Load("resource\\Bos_background.tga");//�w�i

	//Bgm.Load("resource\\mario.wav");
	//Bgm.Repeat();

	//�����摜�̓ǂݍ���
	CText::mFont.Load("resource\\font.tga");
	//�N���X�̃����o�ϐ��ւ̑��
	CPlayer *Player = new CPlayer();
	Player->mRect.x = -800;
	Player->mChara1Hp = CSceneGame::mCharaHp1store;
	Player->mRect.mEnabled = true;

	//�N���X�̃����o�ϐ��ւ̑��

	CEnemy *Enemy = new CEnemy();
	Enemy->mRect.x = 300;
	Enemy->mRect.y = -100;
	Enemy->mRect.mEnabled = true;

	CEnemy *Enemy1 = new CEnemy();
	Enemy1->mRect.x = 300;
	Enemy1->mRect.y = -300;
	Enemy1->mRect.mEnabled = true;

	CEnemy2 *Enemy2 = new CEnemy2();
	Enemy2->mRect.x = 500;
	Enemy2->mRect.y = -300;
	Enemy2->mRect.mEnabled = true;

	CEnemy2 *Enemy3 = new CEnemy2();
	Enemy3->mRect.x = 500;
	Enemy3->mRect.y = -100;
	Enemy3->mRect.mEnabled = true;

	CEnemyBoss *Boss = new CEnemyBoss();
	Boss->mRect.x = 650;
	Boss->mRect.y = -100;
	Boss->mRect.mEnabled = true;
	mBossCount += 1;

	CMap*Map = new CMap();
	//�l�p�`�ɒl����
	Map->m_Rect1.mEnabled = true;
	Map->m_Rect1.x = 0;
	Map->m_Rect1.y = 0;
	Map->m_Rect1.w = 990;
	Map->m_Rect1.h = 540;

	int map[6][8] =
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
	};

	

	CSmg*SMg = new CSmg();

	CItem1*Item1 = new CItem1();
	CItem2*Item2 = new CItem2();
	CItem3*Item3 = new CItem3();
	CItem4*Item4 = new CItem4();

	CPlayerHP *PlayerHP = new CPlayerHP();

	CIcon2*Icon2 = new CIcon2();
	CIcon1*Icon1 = new CIcon1();
}

void CSceneGameBoss::Update() {
	TaskManager::GetInstance()->Update();
	TaskManager::GetInstance()->Collision();
	DrawTaskManager::GetInstance()->Draw();

	//������̕`��
	CText::DrawString("Score", 500, 450, 20, 20);
	sprintf(buf, "%d", CScore::mScore);
	CText::DrawString(buf, 800, 450, 20, 20);
	CText::DrawString("Time", 500, 400, 20, 20);

	if (CSceneGame::Time > 0){
		CSceneGame::Time--;
	}

	//�����𕶎���ɕϊ�����
	char buf[10];//9�����܂�OK

	sprintf(buf, "%d", CSceneGame::Time / 60);
	CText::DrawString(buf, 830, 400, 20, 20);

	if (mBossCount <= 0){
		//�t�F�[�h�A�E�g����
		CRectangle rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = 1920 / 2;
		rect.h = 1080 / 2;
		//�A���t�@�u�����h��L���ɂ���
		glEnable(GL_BLEND);
		//�u�����h���@���w��
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glColor4f(0.0f, 0.0f, 0.0f, mFadeout);
		rect.Render();

		//�A���t�@�u�����h�𖳌�
		glDisable(GL_BLEND);

		mFadeout += 0.01;

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		if (mFadeout >= 1.0){
			mScene = ERESULT;
			CScore::mResultScore = CScore::mScore;
			CScore::mScore = INITIALIZE;
			CSceneGame::Time = TIME;
			TaskManager::ReleaseInstance();
		}
	}

	if (CPlayer::mChara1Hp <= 0){
		//�t�F�[�h�A�E�g����
		CRectangle rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = 1920 / 2;
		rect.h = 1080 / 2;
		//�A���t�@�u�����h��L���ɂ���
		glEnable(GL_BLEND);
		//�u�����h���@���w��
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glColor4f(0.0f, 0.0f, 0.0f, mFadeout);
		rect.Render();

		//�A���t�@�u�����h�𖳌�
		glDisable(GL_BLEND);

		mFadeout += 0.01;

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);


		if (mFadeout >= 1.0){
			CScore::mScore = INITIALIZE;
			mScene = EGAMEOVER;
			mFadeout = INITIALIZE;
			CSceneGame::Time = TIME;
			TaskManager::ReleaseInstance();
		}
	}
	if (CSceneGame::Time <= 0){
		//�t�F�[�h�A�E�g����
		CRectangle rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = 1920 / 2;
		rect.h = 1080 / 2;
		//�A���t�@�u�����h��L���ɂ���
		glEnable(GL_BLEND);
		//�u�����h���@���w��
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glColor4f(0.0f, 0.0f, 0.0f, mFadeout);
		rect.Render();

		//�A���t�@�u�����h�𖳌�
		glDisable(GL_BLEND);

		mFadeout += 0.01;

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);


		if (mFadeout >= 1.0){
			CScore::mScore = INITIALIZE;
			mScene = EGAMEOVER;
			mFadeout = INITIALIZE;
			CSceneGame::Time = TIME;
			TaskManager::ReleaseInstance();
		}
	}

	if (mFadein > 0.0){
		//�t�F�[�h�A�E�g����
		CRectangle rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = 1920 / 2;
		rect.h = 1080 / 2;
		//�A���t�@�u�����h��L���ɂ���
		glEnable(GL_BLEND);
		//�u�����h���@���w��
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glColor4f(0.0f, 0.0f, 0.0f, mFadein);
		rect.Render();

		//�A���t�@�u�����h�𖳌�
		glDisable(GL_BLEND);

		mFadein -= 0.01;
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	}
	return;
	/*
	�z��̗v�f���J��Ԃ�
	�z��.size()
	�z��̗v�f�����擾����
	*/
	for (int i = 0; i < VectorRect.size(); i++) {
		/*
		�z��̎Q��
		�z��[�Y����]
		�ʏ�̔z�񓯗l�ɓY�����ŗv�f�ɃA�N�Z�X�ł���
		*/
		//�X�V����
		VectorRect[i]->Update();
	}
	for (int i = 0; i < VectorRect.size() - 1; i++) {
		//�Փˏ���
		for (int j = i + 1; j < VectorRect.size(); j++) {
			VectorRect[i]->Collision(VectorRect[i], VectorRect[j]);
			VectorRect[j]->Collision(VectorRect[j], VectorRect[i]);
		}
	}

	//���X�g����폜����
	//�C�e���[�^�̐���
	std::vector<CRectangle*>::iterator itr;
	//�C�e���[�^��擪
	itr = VectorRect.begin();
	//�Ō�܂ŌJ��Ԃ�
	while (itr != VectorRect.end()) {
		if ((*itr)->mEnabled) {
			//����
			itr++;
		}
		else {
			//false�̃C���X�^���X���폜
			delete *itr;
			//���X�g������폜
			itr = VectorRect.erase(itr);
		}
	}

	//��ʃX�N���[������(�c1080,��1920,���ɃX�N���[���̐ݒ�)
	//�`��͈͕ϐ��̍쐬�@�͈͉�:-300�@�͈͏�:300�@�Œ�
	double mLeft = -960, mRight = 960, mBottom = -540.0, mTop = 540.0;
	//��ʔ͈͍��̐ݒ�
	mLeft = CPlayer::spInstance->mRect.x - 540.0;
	//��ʔ͈͉E�̐ݒ�
	mRight = mLeft + 1920.0f;
	/*��ʂ̓��e�ύX�J�n*/
	//�s��(�ݒ�)���v���W�F�N�V�������[�h�֕ύX
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();//�s��(�ݒ�)��������
	//2D�̓��e�͈͂�ݒ�
	gluOrtho2D(mLeft, mRight, mBottom, mTop);
	for (int i = 0; i < VectorRect.size(); i++){
		//��ʏ���
		VectorRect[i]->Render();
	}

	glLoadIdentity();//�s��(�ݒ�)��������
	//2D�̓��e�͈͂�������
	gluOrtho2D(-400, 400, -540, 540);




}

//���̃V�[���̎擾
CScene::EScene CSceneGameBoss::GetNextScene() {
	return mScene;
}
//�f�X�g���N�^
CSceneGameBoss::~CSceneGameBoss() {
	//�S�ẴC���X�^���X���폜���܂�
	for (int i = 0; i < VectorRect.size(); i++) {
		//�C���X�^���X�̍폜
		delete VectorRect[i];
	}
	//�ϒ��z��̃N���A
	VectorRect.clear();
}
