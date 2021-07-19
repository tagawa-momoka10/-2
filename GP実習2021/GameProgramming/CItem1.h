#ifndef CITEM1_H
#define CITEM1_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"
#include "SampleProperty.h"
#include "CPlayerHP.h"


class CItem1:public CBase
{
private:
	int mJump1;
	int	mj1;
	int	mJumping1;
	int JumCnt; //ジャンプカウント


	DrawTask mDraw;		//描画タスク操作
	void Collision(CBase *i, CBase *y);		//衝突判定

public:	
	CItem1();

	void Update();
	void Render();
};

#endif