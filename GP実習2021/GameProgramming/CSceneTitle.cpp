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
	//テクスチャファイルを読み込む
	//フォントの設定
	CText::mFont.Load("resource\\font.tga");
	//シーンの設定
	mScene = ETITLE;
}

//更新処理のオーバーライド
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


	//カーソル
	if (m_Line == 1){
		CText::DrawString(">",
			-125, -200, 16, 16);
	}
	//else if (m_Line == 2){
	//	CText::DrawString(">",
	//		-175, -400, 16, 16);
	//}



	////↓を押した時
	//if (CKey::Once(VK_DOWN)){
	//	if (m_Line == 1){
	//		m_Line = 2;
	//	}

	//	else if (m_Line == 2){
	//		m_Line = 3;
	//	}
	//}

	////↑を押した時
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
		//	//次のシーンはチュートリアル
		//	mScene = ETUTORIAL;
		//}
	}
	if (mGame == true){
		//フェードアウト処理
		CRectangle rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = 1920 / 2;
		rect.h = 1080 / 2;
		//アルファブレンドを有効にする
		glEnable(GL_BLEND);
		//ブレンド方法を指定
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glColor4f(0.0f, 0.0f, 0.0f, mFadeout);
		rect.Render();

		//アルファブレンドを無効
		glDisable(GL_BLEND);

		mFadeout += 0.01;

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		if (mFadeout >= 1.0){
			mScene = EGAME;
			mFadeout = 0.0;
		}
	}
}


//次のシーンの取得
CScene::EScene CSceneTitle::GetNextScene() {
	return mScene;
}
