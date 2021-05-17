#include "CSceneGameOver.h"
#include "CKey.h"
#include "TaskManager.h"
#include "CRectangle.h"
extern CTexture TextureGameOver;

CSceneGameOver::CSceneGameOver()
:mFadein(1.0)
{
	mRect.x = 0;
	mRect.y = 0;
	mRect.w = 1920 / 2;
	mRect.h = 1080 / 2;
}

void CSceneGameOver::Init(){
	CText::mFont.Load("resource\\font.tga");
	mScene = EGAMEOVER;
}

void CSceneGameOver::Update(){
	CSceneGameOver *GameOver = new CSceneGameOver();
	GameOver->mRect.Render(TextureGameOver, 0, TextureGameOver.mHeader.width, TextureGameOver.mHeader.height, 0);

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

	if (CKey::Once(VK_RETURN)){
		mScene = ETITLE;
		mFadein = 1.0;
	}
}
CScene::EScene CSceneGameOver::GetNextScene(){
	return mScene;
}