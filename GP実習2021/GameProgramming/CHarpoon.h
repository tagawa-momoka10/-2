#ifndef CHARPOON_H
#define CHARPOON_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"


class CHarpoon : public CBase {
private:
	float md;		//ダッシュ用変数
	int mDashPosition;		//ダッシュ位置記憶
	float mj;		//ジャンプ用変数
	int mJump;		//ジャンプ位置記憶
	bool mdflag;	//ダッシュフラグ(falseなら可能,trueなら不可)
	bool mJflag;	//ジャンプフラグ(falseなら可能,trueなら不可)

	void Update();
	void Render();
	int mInvincibleTime;
	int mAniMoving;	//歩行アニメーション用の変数
	int mChara2Die;	//プレイヤー死亡時の銛アニメーション
	bool mChara2DieFlg;	//銛死亡判定フラグ
	int mAniCnt;
	int mAniDash;
	int mAniJump;	//ジャンプアニメーション用の変数

public:
	CHarpoon();
	DrawTask mDraw;		//描画タスク操作
	void Collision(CBase *i, CBase *y);
	static CHarpoon*spInstance;
	static int mAttackCount;
	static bool CHarpoon::mJumping;	//プレイヤージャンプ中フラグ

};

#endif