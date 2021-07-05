#ifndef CPLAYER_H
#define CPLAYER_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"

class CPlayer : public CBase {
private:
	float mj;		//ジャンプ用変数
	int mJump;		//ジャンプ位置記憶
	int mDash;		//ダッシュ位置記憶
	int mAniCnt;	//アニメーションカウント
	bool mJflag;	//ジャンプフラグ(falseなら可能,trueなら不可)
	bool mDflag;	//ダッシュフラグ(falseなら可能,trueなら不可)
	void Update();
	void Render();
	DrawTask mDraw;		//描画タスク操作
	void Collision(CBase *i, CBase *y);		//衝突判定
	int mInvincibleTime;		//無敵時間

	int mAniMoving;	//歩行アニメーション用の変数
	int mAniDash;	//ダッシュアニメーション用の変数
	int mAniJump;	//ジャンプアニメーション用の変数
	int mChara1Die;	//キャラクター死亡時アニメーション
	bool mChara1Dieflg;	//キャラクター死亡判定フラグ
public:
	CPlayer();
	static bool mCharaSwitch;		//モードチェンジ判定
	static CPlayer*spInstance;		//プレイヤー現在位置取得インスタンス
	static bool mAttackFlag;		//攻撃判定フラグ
	static bool mHpSwitch;			//HPのUI切り替えフラグ
	static int mAttackCount;		//攻撃時間
	static int mDashCount;			//ダッシュ時間
	static int mPlayerPosition;		//プレイヤー位置
	static int mHp;	//主人公HP
	static bool mMoving;	//true(歩行中)	false(静止状態)
	static bool CPlayer::mJumping;	//プレイヤージャンプ中フラグ

};

#endif
