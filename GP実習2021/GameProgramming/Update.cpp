#include "glut.h"
#include "CKey.h"
#include "CRectangle.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CText.h"
#include "CSceneManager.h"

// �e�N�X�`���N���X�̃C���N���[�h
#include "CTexture.h"
CTexture TextureChara1; //��l���摜
CTexture TextureChara1Attack;	//��l���摜2
CTexture Texture2; //�}�b�v�̉摜
CTexture TextureChara2;	//�q���C���摜
CTexture TextureChara2Attack;	//�q���C���摜2

CTexture TextureEnemy; //�G�摜
CTexture TextureEnemy1; //�G�摜1

CTexture TextureMine; //�G
CTexture TextureMine2; //�G


CTexture TexturePlayerHP;//��l��HP
CTexture TexturePlayerHPb;//HP�o�b�N

CTexture Texturech_icon1;	//��l���A�C�R��

CTexture TextureTitleLogo;	//�^�C�g�����S
CTexture TextureTitlebg;	//�^�C�g���w�i
CTexture TextureGameOver;	//�Q�[���I�[�o�[���
CTexture TextureResult;		//���U���g���

CTexture Textureitem1;//�A�C�e��1
CTexture Textureitem2;//�A�C�e��2
CTexture Textureitem3;//�A�C�e��3
CTexture Textureitem4;//�A�C�e��4


CTexture Texturekihou;//�C�A
CTexture TextureBuki;//����
CTexture Texturewa;//���J��

//�V�[���}�l�[�W���̃C���X�^���X
CSceneManager SceneManager;



//Init�֐�
//�ŏ��Ɉ�x�����Ă΂��֐�
void Init() {
	TextureChara1.Load("resource\\hasiri.tga");
	TextureChara1Attack.Load("resource\\ch102.tga");

	TextureChara2.Load("resource\\ch201.tga");
	TextureChara2Attack.Load("resource\\ch202.tga");

	TextureEnemy.Load("resource\\same.tga");//�T��

	TextureMine.Load("resource\\mine.png");//�@���@
	TextureMine2.Load("resource\\mine2.png");//�@���@����

	Texturewa.Load("resource\\wakame.tga"); //���J��

	TexturePlayerHP.Load("resource\\HP.jpg");//��l��HP max
	TexturePlayerHPb.Load("resource\\HPg.jpg");//��l��HP�o�b�N

	Texturech_icon1.Load("resource\\ch_icon1.tga");//��l��

	TextureTitleLogo.Load("resource\\title logo3.tga");
	TextureTitlebg.Load("resource\\title bg.tga");

	TextureGameOver.Load("resource\\GameOver.tga");
	TextureResult.Load("resource\\result.tga");


	Textureitem1.Load("resource\\akikan.png");
	Textureitem2.Load("resource\\item2.tga");
	Textureitem3.Load("resource\\item3.tga");
	Textureitem4.Load("resource\\item4.tga");

	Texturekihou.Load("resource\\kihou.png");
	TextureBuki.Load("resource\\mori.jpg");

	//�V�[���}�l�[�W���̏�����
	SceneManager.Init();
}
//Update�֐�
//�v���O�����̎��s���A�J��Ԃ��Ă΂��֐�
void Update() {

	

	//�V�[���}�l�[�W���̍X�V
	SceneManager.Update();
}
