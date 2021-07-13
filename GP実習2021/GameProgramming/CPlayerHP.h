#ifndef CHPHERO_H
#define CHPHERO_H
#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"
#include "SampleProperty.h"
class CPlayerHP :public CBase
{
private:
	DrawTask mDraw;		//描画タスク操作
	void Update();
	int mAniCnt;	//アニメーションカウント
	int mHPReduCnt; //ＨＰ減らすカウント
	int mAniMoving;	//歩行アニメーション用の変数

public:
	CPlayerHP();
	// コンストラクタで初期化
	CPlayerHP(float max, float min, float pre)

{
	//描画タスクに登録
		mDraw.RegistDraw(this, (DrawFunc)&CPlayerHP::Render, DrawPriority::Transparent, "CPlayerHP");
	mTag = EPLAYERHP;
	mRect.x = -250;
	mRect.y = 600;
	mRect.w = 30;
	mRect.h = 30;
}

	int mPositionY1;	//Y座標記憶
	int mPositionX1;

	int mPositionY2;	//Y座標記憶
	int mPositionX2;
	
	static int mHPReduCnt;

	void Render();
	
	static CPlayerHP*spInstance;

	CRectangle m_Rect1;
	CRectangle m_Rect2;
};


#endif