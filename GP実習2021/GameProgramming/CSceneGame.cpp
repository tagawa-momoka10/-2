#include "CSceneGame.h"
#include "CTexture.h"
#include "CMap2.h"
#include "CKey.h"
#include "CRectangle.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CEnemy2.h"
#include "CEnemyBoss.h"
#include "CText.h"
#include "TaskManager.h"
#include "DrawTaskManager.h"
#include "CPlayerHP.h"
#include "CIcon1.h"
#include "CIcon2.h"
#include "TaskInclude.h"
#include "CScore.h"
#include "CItem1.h"
#include "CItem2.h"
#include "CSmg.h"
#include "CHarpoon.h"
#include "CSSearch.h"
//#include "CWakame.h"
#include "CBubble.h"

//#include "CSound.h"

#define INITIALIZE 0	//初期化
#define TIME 200*60

//extern CTexture Texture2; //背景

int CSceneGame::Time = TIME;
int CSceneGame::mCharaHp1store = 0;
int CSceneGame::mCharaHp2store = 0;
int CSceneGame::mSpstore = 0;
int CSceneGame::mCombostore = 0;
int CSceneGame::mScorestore = 0;
//CSound Bgm;

void CSceneGame::Init() {
	//シーンの設定
	mScene = EGAME;

	mFadeout = 0.0;
	mFadein = 1.0;
	Texture2.Load("resource\\kaitei.tga");//背景
	//文字画像の読み込み
	CText::mFont.Load("resource\\font.tga");

/*		BGM再生用
	Bgm.Load();
	Bgm.Repeat();*/

	CSSearch*SSearch = new CSSearch();

	CEnemy *Enemy = new CEnemy();
	Enemy->mRect.x = 300;
	Enemy->mRect.y = -200;
	Enemy->mRect.mEnabled = true;

	//CEnemy *Enemy2 = new CEnemy();
	//Enemy2->mRect.x = 600;
	//Enemy2->mRect.y = -100;
	//Enemy2->mRect.mEnabled = true;

	//CEnemy *Enemy3 = new CEnemy();
	//Enemy3->mRect.x = -900;
	//Enemy3->mRect.y = -100;
	//Enemy3->mRect.mEnabled = true;

	CEnemy2 *Enemy4 = new CEnemy2();
	Enemy4->mRect.x = -900;
	Enemy4->mRect.y = -300;
	Enemy4->mRect.mEnabled = true;

	/*CEnemy2 *Enemy5 = new CEnemy2();
	Enemy5->mRect.x = 900;
	Enemy5->mRect.y = -300;
	Enemy5->mRect.mEnabled = true;*/

	//クラスのメンバ変数への代入
	CPlayer *Player = new CPlayer();
	Player->mRect.mEnabled = true;
	Player->mRect.x = -600;
	Player->mRect.y = 0;

	CHarpoon*Harpoon = new CHarpoon();
	Harpoon->mRect.mEnabled = true;

	CMap2*Map = new CMap2();
	////四角形に値を代入
	Map->m_Rect1.mEnabled = true;
	Map->m_Rect1.x = 3000;
	Map->m_Rect1.y = 0;
	Map->m_Rect1.w = 3600;
	Map->m_Rect1.h = 350;

	int map[6][8] =
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, },
	};

	CSmg*SMg = new CSmg();

	CItem1*Item1 = new CItem1();
	Item1->mRect.x = 0;
	Item1->mRect.y = -300;
	Item1->mRect.w = 25;
	Item1->mRect.h = 50;
	Item1->mRect.mEnabled = true;

	CItem1*Item2 = new CItem1();
	Item2->mRect.x = 200;
	Item2->mRect.y = -300;
	Item2->mRect.w = 25;
	Item2->mRect.h = 50;
	Item2->mRect.mEnabled = true;

	CItem1*Item3 = new CItem1();
	Item3->mRect.x = 400;
	Item3->mRect.y = -300;
	Item3->mRect.w = 25;
	Item3->mRect.h = 50;
	Item3->mRect.mEnabled = true;

	CItem1*Item4 = new CItem1();
	Item4->mRect.x = 600;
	Item4->mRect.y = -300;
	Item4->mRect.w = 25;
	Item4->mRect.h = 50;
	Item4->mRect.mEnabled = true;

	CItem1*Item5 = new CItem1();
	Item5->mRect.x = 800;
	Item5->mRect.y = 0;
	Item5->mRect.w = 25;
	Item5->mRect.h = 50;
	Item5->mRect.mEnabled = true;

	CItem1*Item6 = new CItem1();
	Item6->mRect.x = 1200;
	Item6->mRect.y = 400;
	Item6->mRect.w = 25;
	Item6->mRect.h = 50;
	Item6->mRect.mEnabled = true;

	CItem1*Item7 = new CItem1();
	Item7->mRect.x = 1400;
	Item7->mRect.y = 300;
	Item7->mRect.w = 25;
	Item7->mRect.h = 50;
	Item7->mRect.mEnabled = true;

	CItem1*Item8 = new CItem1();
	Item8->mRect.x = 1800;
	Item8->mRect.y = 0;
	Item8->mRect.w = 25;
	Item8->mRect.h = 50;
	Item8->mRect.mEnabled = true;

	CItem1*Item9 = new CItem1();
	Item9->mRect.x = 2100;
	Item9->mRect.y = 0;
	Item9->mRect.w = 25;
	Item9->mRect.h = 50;
	Item9->mRect.mEnabled = true;

	CItem1*Item10 = new CItem1();
	Item10->mRect.x = 2100;
	Item10->mRect.y = 0;
	Item10->mRect.w = 25;
	Item10->mRect.h = 50;
	Item10->mRect.mEnabled = true;

	///////////////////////////////////////////

	CItem2*Item11 = new CItem2();
	Item11->mRect.x = -200;
	Item11->mRect.y = 0;
	Item11->mRect.mEnabled = true;


	CPlayerHP *PlayerHP = new CPlayerHP();

	CIcon2*Icon2 = new CIcon2();
	CIcon1*Icon1 = new CIcon1();

	//CWakame*Wakame = new CWakame();
	CBubble*Bubble = new CBubble();
	Bubble->mRect.x = -400;
	Bubble->mRect.y = -200;
}

void CSceneGame::Update() {
	TaskManager::GetInstance()->Update();
	TaskManager::GetInstance()->Collision();
	DrawTaskManager::GetInstance()->Draw();

	//文字列の描画
	/*CText::DrawString("Score", 500, 200, 20, 20);
	sprintf(buf, "%d", CScore::mScore);
	CText::DrawString(buf, 800, 450, 20, 20);
	CText::DrawString("Time", 500, 400, 20, 20);*/

	//if (Time > 0){
	//	Time--;
	//}

	//整数を文字列に変換する
	char buf[10];//9文字までOK

	//if (CPlayer::spInstance->mRect.x >= 800){
	//	//フェードアウト処理
	//	CRectangle rect;
	//	rect.x = 0;
	//	rect.y = 0;
	//	rect.w = 1920 / 2;
	//	rect.h = 1080 / 2;
	//	//アルファブレンドを有効にする
	//	glEnable(GL_BLEND);
	//	//ブレンド方法を指定
	//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//	glColor4f(0.0f, 0.0f, 0.0f, mFadeout);
	//	rect.Render();

	//	//アルファブレンドを無効
	//	glDisable(GL_BLEND);

	//	mFadeout += 0.01;

	//	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	//	if (mFadeout >= 1.0){
	//		mScene = EGAME2;
	//		mCharaHp1store = CPlayer::mChara1Hp;
	//		mScorestore = CScore::mScore;
	//		TaskManager::ReleaseInstance();
	//	}
	//}
	//if (CPlayer::mChara1Hp <= 0 ){
	//	//フェードアウト処理
	//	CRectangle rect;
	//	rect.x = 0;
	//	rect.y = 0;
	//	rect.w = 1920 / 2;
	//	rect.h = 1080 / 2;
	//	//アルファブレンドを有効にする
	//	glEnable(GL_BLEND);
	//	//ブレンド方法を指定
	//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//	glColor4f(0.0f, 0.0f, 0.0f, mFadeout);
	//	rect.Render();

	//	//アルファブレンドを無効
	//	glDisable(GL_BLEND);

	//	mFadeout += 0.01;

	//	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);


	//	if (mFadeout >= 1.0){
	//		CScore::mScore = INITIALIZE;
	//		mScene = EGAMEOVER;
	//		mFadeout = INITIALIZE;
	//		Time = TIME;
	//		TaskManager::ReleaseInstance();
	//	}
	//}
	//if (Time <= 0){
	//	//フェードアウト処理
	//	CRectangle rect;
	//	rect.x = 0;
	//	rect.y = 0;
	//	rect.w = 1920 / 2;
	//	rect.h = 1080 / 2;
	//	//アルファブレンドを有効にする
	//	glEnable(GL_BLEND);
	//	//ブレンド方法を指定
	//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//	glColor4f(0.0f, 0.0f, 0.0f, mFadeout);
	//	rect.Render();

	//	//アルファブレンドを無効
	//	glDisable(GL_BLEND);

	//	mFadeout += 0.01;

	//	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);


	//	if (mFadeout >= 1.0){
	//		CScore::mScore = INITIALIZE;
	//		mScene = EGAMEOVER;
	//		mFadeout = INITIALIZE;
	//		Time = TIME;
	//		TaskManager::ReleaseInstance();
	//	}
	//}

	//if (mFadein > 0.0){
	//	//フェードアウト処理
	//	CRectangle rect;
	//	rect.x = 0;
	//	rect.y = 0;
	//	rect.w = 1920 / 2;
	//	rect.h = 1080 / 2;
	//	//アルファブレンドを有効にする
	//	glEnable(GL_BLEND);
	//	//ブレンド方法を指定
	//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//	glColor4f(0.0f, 0.0f, 0.0f, mFadein);
	//	rect.Render();

	//	//アルファブレンドを無効
	//	glDisable(GL_BLEND);

	//	mFadein -= 0.01;
	//	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	//}
	//return;
	///*
	//配列の要素分繰り返す
	//配列名.size()
	//配列の要素数を取得する
	//*/
	//for (int i = 0; i < VectorRect.size(); i++) {
	//	/*
	//	配列の参照
	//	配列名[添え字]
	//	通常の配列同様に添え字で要素にアクセスできる
	//	*/
	//	//更新処理
	//	VectorRect[i]->Update();
	//}
	//for (int i = 0; i < VectorRect.size() - 1; i++) {
	//	//衝突処理
	//	for (int j = i + 1; j < VectorRect.size(); j++) {
	//		VectorRect[i]->Collision(VectorRect[i], VectorRect[j]);
	//		VectorRect[j]->Collision(VectorRect[j], VectorRect[i]);
	//	}
	//}

	////リストから削除する
	////イテレータの生成
	//std::vector<CRectangle*>::iterator itr;
	////イテレータを先頭
	//itr = VectorRect.begin();
	////最後まで繰り返し
	//while (itr != VectorRect.end()) {
	//	if ((*itr)->mEnabled) {
	//		//次へ
	//		itr++;
	//	}
	//	else {
	//		//falseのインスタンスを削除
	//		delete *itr;
	//		//リストからも削除
	//		itr = VectorRect.erase(itr);
	//	}
	//}

	//画面スクロール処理(H 700,W 1200,横にスクロール)
	//描画範囲変数の作成　範囲下:-300　範囲上:300　固定
	double mLeft = -600 , mRight = 600, mBottom = -350, mTop = 350;
	//画面範囲左の設定
	mLeft = CPlayer::spInstance->mRect.x - 600.0f;

	//画面範囲右の設定
	mRight = mLeft + 1200.0f;

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

}


//次のシーンの取得
CScene::EScene CSceneGame::GetNextScene() {
	return mScene;
}
//デストラクタ
CSceneGame::~CSceneGame() {
	//全てのインスタンスを削除します
	for (int i = 0; i < VectorRect.size(); i++) {
		//インスタンスの削除
		delete VectorRect[i];
	}
	//可変長配列のクリア
	VectorRect.clear();
}
