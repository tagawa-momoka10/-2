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

CTexture TextureEnemy2; //�G�摜2

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

CTexture TextureSp_MG;//�K�E�Z�Q�[�W��
CTexture TextureSp_MG2;//�K�E�Z�Q�[�W��
CTexture TextureSp_MG3;//�K�E�Z�Q�[�W���S
CTexture TextureSp_MGg;//�Q�[�W

CTexture Texturekihou;//�C�A
CTexture TextureBuki;//����

//�V�[���}�l�[�W���̃C���X�^���X
CSceneManager SceneManager;



//Init�֐�
//�ŏ��Ɉ�x�����Ă΂��֐�
void Init() {
	TextureChara1.Load("resource\\hasiri.tga");
	TextureChara1Attack.Load("resource\\ch102.tga");

	TextureChara2.Load("resource\\ch201.tga");
	TextureChara2Attack.Load("resource\\ch202.tga");

	TextureEnemy.Load("resource\\same.tga");
	TextureEnemy1.Load("resource\\same s.tga");

	//TextureEnemy2.Load("resource\\em201.tga"); 


	TexturePlayerHP.Load("resource\\HP.tga");//��l��HP max
	TexturePlayerHPb.Load("resource\\HPg.tga");//��l��HP�o�b�N



	Texturech_icon1.Load("resource\\ch_icon1.tga");//��l��

	TextureTitleLogo.Load("resource\\title logo3.tga");
	TextureTitlebg.Load("resource\\title bg.tga");

	TextureGameOver.Load("resource\\GameOver.tga");
	TextureResult.Load("resource\\result.tga");


	Textureitem1.Load("resource\\akikan.tga");
	Textureitem2.Load("resource\\item2.tga");
	Textureitem3.Load("resource\\item3.tga");
	Textureitem4.Load("resource\\item4.tga");

	TextureSp_MG.Load("resource\\Sp_MG.tga");
	TextureSp_MG2.Load("resource\\Sp_MG2.tga");
	TextureSp_MG3.Load("resource\\Sp_MG3.tga");
	TextureSp_MGg.Load("resource\\Sp_MGg.tga");

	Texturekihou.Load("resource\\kihou.tga");
	TextureBuki.Load("resource\\mori.tga");

	//�V�[���}�l�[�W���̏�����
	SceneManager.Init();
}
//Update�֐�
//�v���O�����̎��s���A�J��Ԃ��Ă΂��֐�
void Update() {

	

	//�V�[���}�l�[�W���̍X�V
	SceneManager.Update();
}
