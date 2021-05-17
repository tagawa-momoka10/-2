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

#define INITIALIZE 0	//初期化
#define TIME 200*60
int CSceneGameBoss::mBossCount = 0;

extern CTexture TextureChara1;
//extern CTexture TextureBos_background;//ボス背景

//CSound Bgm;


void CSceneGameBoss::Init() {
	//シーンの設定
	mScene = EGAMEBOSS;

	mFadeout = 0.0;
	mFadein = 1.0;

	TextureChara1.Load("resource\\ch101.tga");
	//TextureBos_background.Load("resource\\Bos_background.tga");//背景

	//Bgm.Load("resource\\mario.wav");
	//Bgm.Repeat();

	//文字画像の読み込み
	CText::mFont.Load("resource\\font.tga");
	//クラスのメンバ変数への代入
	CPlayer *Player = new CPlayer();
	Player->mRect.x = -800;
	Player->mChara1Hp = CSceneGame::mCharaHp1store;
	Player->mRect.mEnabled = true;

	//クラスのメンバ変数への代入

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
	//四角形に値を代入
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

	//文字列の描画
	CText::DrawString("Score", 500, 450, 20, 20);
	sprintf(buf, "%d", CScore::mScore);
	CText::DrawString(buf, 800, 450, 20, 20);
	CText::DrawString("Time", 500, 400, 20, 20);

	if (CSceneGame::Time > 0){
		CSceneGame::Time--;
	}

	//整数を文字列に変換する
	char buf[10];//9文字までOK

	sprintf(buf, "%d", CSceneGame::Time / 60);
	CText::DrawString(buf, 830, 400, 20, 20);

	if (mBossCount <= 0){
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
			mScene = ERESULT;
			CScore::mResultScore = CScore::mScore;
			CScore::mScore = INITIALIZE;
			CSceneGame::Time = TIME;
			TaskManager::ReleaseInstance();
		}
	}

	if (CPlayer::mChara1Hp <= 0){
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
			CScore::mScore = INITIALIZE;
			mScene = EGAMEOVER;
			mFadeout = INITIALIZE;
			CSceneGame::Time = TIME;
			TaskManager::ReleaseInstance();
		}
	}
	if (CSceneGame::Time <= 0){
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
			CScore::mScore = INITIALIZE;
			mScene = EGAMEOVER;
			mFadeout = INITIALIZE;
			CSceneGame::Time = TIME;
			TaskManager::ReleaseInstance();
		}
	}

	if (mFadein > 0.0){
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

		glColor4f(0.0f, 0.0f, 0.0f, mFadein);
		rect.Render();

		//アルファブレンドを無効
		glDisable(GL_BLEND);

		mFadein -= 0.01;
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	}
	return;
	/*
	配列の要素分繰り返す
	配列名.size()
	配列の要素数を取得する
	*/
	for (int i = 0; i < VectorRect.size(); i++) {
		/*
		配列の参照
		配列名[添え字]
		通常の配列同様に添え字で要素にアクセスできる
		*/
		//更新処理
		VectorRect[i]->Update();
	}
	for (int i = 0; i < VectorRect.size() - 1; i++) {
		//衝突処理
		for (int j = i + 1; j < VectorRect.size(); j++) {
			VectorRect[i]->Collision(VectorRect[i], VectorRect[j]);
			VectorRect[j]->Collision(VectorRect[j], VectorRect[i]);
		}
	}

	//リストから削除する
	//イテレータの生成
	std::vector<CRectangle*>::iterator itr;
	//イテレータを先頭
	itr = VectorRect.begin();
	//最後まで繰り返し
	while (itr != VectorRect.end()) {
		if ((*itr)->mEnabled) {
			//次へ
			itr++;
		}
		else {
			//falseのインスタンスを削除
			delete *itr;
			//リストからも削除
			itr = VectorRect.erase(itr);
		}
	}

	//画面スクロール処理(縦1080,横1920,横にスクロールの設定)
	//描画範囲変数の作成　範囲下:-300　範囲上:300　固定
	double mLeft = -960, mRight = 960, mBottom = -540.0, mTop = 540.0;
	//画面範囲左の設定
	mLeft = CPlayer::spInstance->mRect.x - 540.0;
	//画面範囲右の設定
	mRight = mLeft + 1920.0f;
	/*画面の投影変更開始*/
	//行列(設定)をプロジェクションモードへ変更
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();//行列(設定)を初期化
	//2Dの投影範囲を設定
	gluOrtho2D(mLeft, mRight, mBottom, mTop);
	for (int i = 0; i < VectorRect.size(); i++){
		//画面処理
		VectorRect[i]->Render();
	}

	glLoadIdentity();//行列(設定)を初期化
	//2Dの投影範囲を初期化
	gluOrtho2D(-400, 400, -540, 540);




}

//次のシーンの取得
CScene::EScene CSceneGameBoss::GetNextScene() {
	return mScene;
}
//デストラクタ
CSceneGameBoss::~CSceneGameBoss() {
	//全てのインスタンスを削除します
	for (int i = 0; i < VectorRect.size(); i++) {
		//インスタンスの削除
		delete VectorRect[i];
	}
	//可変長配列のクリア
	VectorRect.clear();
}
