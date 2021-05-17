#include "CSceneTitle.h"
#include "CScore.h"
#include "CKey.h"
#include "SampleProperty.h"
//extern CTexture TextureTitleLogo;
//extern CTexture TextureTitlebg;

CSceneTitle::CSceneTitle()
:m_Line(1), m_Score(0)
, mGame(false)
, mFadeout(0)
{
	mRect.x = 0;
	mRect.y = 300;
	mRect.w = 500;
	mRect.h = 200;
}

void CSceneTitle::Init() {
	//�e�N�X�`���t�@�C����ǂݍ���
	//�t�H���g�̐ݒ�
	CText::mFont.Load("resource\\font.tga");
	//�V�[���̐ݒ�
	mScene = ETITLE;
}

//�X�V�����̃I�[�o�[���C�h
void CSceneTitle::Update() {

	CSceneTitle *Titlebg = new CSceneTitle();
	Titlebg->mRect.x = 0;
	Titlebg->mRect.y = 0;
	Titlebg->mRect.w = 1920 / 2;
	Titlebg->mRect.h = 1080 / 2;
	//Titlebg->mRect.Render(TextureTitlebg, 0, TextureTitlebg.mHeader.width, TextureTitlebg.mHeader.height, 0);

	CSceneTitle *Title = new CSceneTitle();
	//Title->mRect.Render(TextureTitleLogo, 0, TextureTitleLogo.mHeader.width, TextureTitleLogo.mHeader.height, 0);


	CText::DrawString("Push ENTER Key",
		-200, -150, 16, 16);

	//1
	CText::DrawString("Start",
		-75, -200, 16, 16);

	CText::DrawString("Total Score",
		-800, 400, 16, 16);

	sprintf(buf, "%d", CScore::mTotalScore);
	CText::DrawString(buf, -800, 350, 16, 16);


	//�J�[�\��
	if (m_Line == 1){
		CText::DrawString(">",
			-125, -200, 16, 16);
	}
	//else if (m_Line == 2){
	//	CText::DrawString(">",
	//		-175, -400, 16, 16);
	//}



	////������������
	//if (CKey::Once(VK_DOWN)){
	//	if (m_Line == 1){
	//		m_Line = 2;
	//	}

	//	else if (m_Line == 2){
	//		m_Line = 3;
	//	}
	//}

	////������������
	//if (CKey::Once(VK_UP)){
	//	if (m_Line == 2){
	//		m_Line = 1;
	//	}

	//	else if (m_Line == 1){
	//		m_Line = 4;
	//	}
	//}


	//1
	if (CKey::Once(VK_RETURN)) {
		if (m_Line == 1){
			mGame = true;
		}
		//if (m_Line == 2){
		//	//���̃V�[���̓`���[�g���A��
		//	mScene = ETUTORIAL;
		//}
	}
	if (mGame == true){
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
			mScene = EGAME;
			mFadeout = 0.0;
		}
	}
}


//���̃V�[���̎擾
CScene::EScene CSceneTitle::GetNextScene() {
	return mScene;
}
