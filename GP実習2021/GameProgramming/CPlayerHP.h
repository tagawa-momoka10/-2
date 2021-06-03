#ifndef CHPHERO_H
#define CHPHERO_H
#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"
#include "SampleProperty.h"
class CPlayerHP :public CBase
{
private:
	float m_Max; // 最大値
	float m_Min; // 最小値
	DrawTask mDraw;		//描画タスク操作
	void Update();
	int mAniCnt;	//アニメーションカウント
	int mAniMoving;	//歩行アニメーション用の変数

public:
	CPlayerHP();
	// コンストラクタで初期化
	CPlayerHP(float max, float min, float pre)
		:m_Max(max), m_Min(min)
{
	//描画タスクに登録
		mDraw.RegistDraw(this, (DrawFunc)&CPlayerHP::Render, DrawPriority::Transparent, "CPlayerHP");
	mTag = EPLAYERHP;
	mRect.x = -250;
	mRect.y = 600;
	mRect.w = 30;
	mRect.h = 30;
}


	int max;
	int min;
	int mPositionY1;	//Y座標記憶
	int mPositionX1;

	int mPositionY2;	//Y座標記憶
	int mPositionX2;



	float getMax();
	float getMin();
	float get();

	float add(float value);
	float addMax(float value);
	float addMin(float value);

	float CPlayerHP::hp();
	float CPlayerHP::rate();


	void setMax(float value);
	void setMin(float value);
	void set(float value);


	bool CPlayerHP::isEmpty();
	bool CPlayerHP::isFull();

	void Render();
	
	static CPlayerHP*spInstance;

	CRectangle m_Rect1;
	CRectangle m_Rect2;
};


#endif