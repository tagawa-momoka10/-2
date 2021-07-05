#ifndef CWAKAME_H
#define CWAKAME_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"

class CWakame : public CBase {
private:
	DrawTask mDraw;		//描画タスク操作
	int mAniCnt;	//アニメーションカウント
	void Collision(CBase *i, CBase *y);		//衝突判定
	int mAniMoving;	//歩行アニメーション用の変数
	void Update();
	void Render();
	static bool mMoving;	//true(歩行中)	false(静止状態)
public:
	CWakame();
	CRectangle m_RectW;
};
#endif 
