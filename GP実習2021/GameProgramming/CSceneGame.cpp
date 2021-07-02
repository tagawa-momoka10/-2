#include "CSceneGame.h"
#include "CSceneGame2.h"
#include "CTexture.h"
#include "CMap2.h"
#include "CKey.h"
#include "CRectangle.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CEnemy2.h"
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
#include "CWakame.h"
#include "CBubble.h"

//#include "CSound.h"

#define INITIALIZE 0	//初期化
#define TIME 200*60


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


	CEnemy *Enemy = new CEnemy();
	Enemy->mRect.x = 300;
	Enemy->mRect.y = -200;
	Enemy->mRect.mEnabled = true;

	CEnemy *Enemy2 = new CEnemy();
	Enemy2->mRect.x = 2000;
	Enemy2->mRect.y = 300;
	Enemy2->mRect.mEnabled = true;

	//CEnemy *Enemy3 = new CEnemy();
	//Enemy3->mRect.x = 2000;
	//Enemy3->mRect.y = -100;
	//Enemy3->mRect.mEnabled = true;

	CEnemy2 *Enemy4 = new CEnemy2();
	Enemy4->mRect.x = -900;
	Enemy4->mRect.y = -300;
	Enemy4->mRect.mEnabled = true;

	CEnemy2 *Enemy5 = new CEnemy2();
	Enemy5->mRect.x = 900;
	Enemy5->mRect.y = -300;
	Enemy5->mRect.mEnabled = true;

	CEnemy2 *Enemy6 = new CEnemy2();
	Enemy6->mRect.x = 1050;
	Enemy6->mRect.y = -100;
	Enemy6->mRect.mEnabled = true;

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
	Item11->mRect.w = 40;
	Item11->mRect.h = 5;
	Item11->mRect.mEnabled = true;


	CWakame*Wakame1 = new CWakame();
	Wakame1->mRect.x = 100;
	Wakame1->mRect.y = -200;

	CWakame*Wakame2 = new CWakame();
	Wakame2->mRect.x = 150;
	Wakame2->mRect.y = -200;

	CWakame*Wakame3 = new CWakame();
	Wakame3->mRect.x = 900;
	Wakame3->mRect.y = -200;


	CBubble*Bubble1 = new CBubble();
	Bubble1->mRect.x = -100;
	Bubble1->mRect.y = -200;

	CBubble*Bubble2 = new CBubble();
	Bubble2->mRect.x = 400;
	Bubble2->mRect.y = 200;


	CPlayerHP *PlayerHP = new CPlayerHP();


	//CIcon2*Icon2 = new CIcon2();
	//CIcon1*Icon1 = new CIcon1();

}

void CSceneGame::Update() {
	TaskManager::GetInstance()->Update();
	TaskManager::GetInstance()->Collision();
	DrawTaskManager::GetInstance()->Draw();




	//整数を文字列に変換する
	char buf[10];//9文字までOK

	//画面スクロール処理(H 700,W 1200,横にスクロール)
	//描画範囲変数の作成　範囲下:-300　範囲上:300　固定
	double mLeft = -600 , mRight = 600, mBottom = -350, mTop = 350;

	//画面範囲左の設定
	mLeft = CPlayer::spInstance->mRect.x -550.0f;

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

	//文字列の描画
	CText::DrawString("Score", mLeft+100, mRight-100, mBottom+100, mTop-100);
	sprintf(buf, "%d", CScore::mScore);
	CText::DrawString(buf, mLeft+50, mRight-50, mBottom+50, mTop-50);

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
