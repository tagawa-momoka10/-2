#include "CSceneResult.h"
#include "CKey.h"
#include <stdio.h>
#include "CPlayer.h"
#include "TaskManager.h"
#include "CScore.h""

#define INITIALIZE 0	//初期化
extern CTexture TextureResult;

CSceneResult::CSceneResult()
:mFadein(1.0)
{
}

void CSceneResult::Init(){
	CText::mFont.Load("resource\\font.tga");
	mScene = ERESULT;
}

void CSceneResult::Update(){
	CSceneResult * Result = new CSceneResult();
	Result->mRect.x = 0;
	Result->mRect.y = 0;
	Result->mRect.w = 1920 / 2;
	Result->mRect.h = 1080 / 2;
	Result->mRect.Render(TextureResult, 0, TextureResult.mHeader.width, TextureResult.mHeader.height, 0);

	CText::DrawString("Result", -400, 200, 40, 40);
	CText::DrawString("Score", -400, -100, 20, 20);
	CText::DrawString(buf, 200, 0, 20, 20);
	sprintf(buf, "%d", CScore::mResultScore);
	CText::DrawString(buf, 200, -100, 20, 20);
	//フェードイン処理
	CRectangle rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = 1920 / 2;
	rect.h = 1080 / 2;
	//アルファブレンドを有効にする
	glEnable(GL_BLEND);
	//ブレンド方法を指定
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4f(0.0f, 0.0f, 0.0f, mFadein);
	rect.Render();

	//アルファブレンドを無効
	glDisable(GL_BLEND);

	mFadein -= 0.01;

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	if (CKey::Once(VK_RETURN)){
		CScore::mTotalScore += CScore::mResultScore;
		CScore::mResultScore = INITIALIZE;
		mScene = ETITLE;
		mFadein = 1.0;
	}
}

CScene::EScene CSceneResult::GetNextScene(){
	return mScene;
}