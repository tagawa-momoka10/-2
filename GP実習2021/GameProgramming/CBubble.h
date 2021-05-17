#ifndef CBUBBLE_H
#define CBUBBLE_H

#include "TaskInclude.h"
#include "CBase.h"

class CBubble : public CBase{
private:
	void Update();
	void Render();
	void Collision(CBase *i, CBase *y);		//衝突判定
	DrawTask mDraw;		//描画タスク操作
	int mAniMoving;	//歩行アニメーション用の変数

public:
	CBubble();
};


#endif