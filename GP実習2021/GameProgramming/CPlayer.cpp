#include "CPlayer.h"
#include "CKey.h"
#include "SampleProperty.h"
#include "TaskManager.h"
#include "DrawTaskManager.h"
#include "CPlayerAttack.h"
#include "CEnemy.h"
#include "CHarpoon.h"
#include "CMine.h"

#define G -0.1	//重力
#define VJ0 4	//ジャンプ力
#define INITIALIZE 0	//初期化
#define EXIST_TIME 30	//攻撃判定の存在時間
#define ANICNT 40		//アニメーション
#define ATTACKRANGE 20	//攻撃射程
#define POSITION 100		//プレイヤー位置
#define INVINCIBLETIME 60	//無敵時間
#define INVINCIBLETIME_DASH 3	//ダッシュ回避時間
#define SPCOUNT 105
#define DASHANICNT 120
#define DIE 60

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture TextureChara1;
extern CTexture TextureChara1Attack;
bool CPlayer::mAttackFlag;
bool CPlayer::mHpSwitch;
int CPlayer::mAttackCount;
int CPlayer::mDashCount;
bool CPlayer::mCharaSwitch;
int CPlayer::mPlayerPosition;
int CPlayer::mHp;
bool CPlayer::mMoving;
bool CPlayer::mJumping;
int  mDashCount= 0;

CPlayer*CPlayer::spInstance = 0;

CPlayer::CPlayer()
: mDash(0)
, mDflag(false)
, mJump(0)
, mAniCnt(0)
, mInvincibleTime(0)
, mAniDash(0)
, mChara1Die(0)
, mChara1Dieflg(false)
{
	//描画タスクに登録
	mDraw.RegistDraw(this, (DrawFunc)&CPlayer::Render, DrawPriority::Transparent, "Player");
	mHp = 200;
	mTag = EPLAYER;
	spInstance = this;
	mRect.x = -200;
	mRect.y = 100;
	mRect.w = 55;
	mRect.h = 80;
	mJumping = false;
	mAttackFlag = true;
	mHpSwitch = false;
	mMoving = false;
	mAttackCount = INITIALIZE;
	mCharaSwitch = false;
	mPlayerPosition = POSITION;
	mAniMoving = INITIALIZE;
}

void CPlayer::Update() {
	mRect.y -= 1;
	if (mHp <= 0 && mChara1Dieflg == false){
		mChara1Die = DIE;
		mChara1Dieflg = true;
	}
	if (mChara1Die>0 && mChara1Dieflg == true){
		mChara1Die--;
		if (mChara1Die == 30){
			mRect.w = 80;
			mRect.h = 55;
		}
	}
	//画面外から出ないように調整
	if (mRect.x + mRect.w > 3600) {
		mRect.x = 3600 - mRect.w;
	}
	if (mRect.x - mRect.w < -600) {
		mRect.x = -600 + mRect.w;
	}
	if (mRect.y - mRect.h > 350){
		mRect.y = 350 + mRect.h;
	}
	if (mRect.y - mRect.h < -350){
		mRect.y = -350 + mRect.h;
	}
	mMoving = false;
	if (mHp > 0){
		if (mAttackCount <= 0){
			if (CKey::Push('A')) {
				mRect.x -= 4;
				mMoving = true;

				//if (mCharaSwitch == false){
				//	CHarpoon::spInstance->mRect.x = mRect.x + mPlayerPosition;
				//}
			}
			if (CKey::Push('D')) {
				mRect.x += 4;
				mMoving = true;
				//if (mCharaSwitch == false){
				//	CHarpoon::spInstance->mRect.x = mRect.x + mPlayerPosition;
				//}
			}

			if (CKey::Push('S')){
				mRect.y -= 4;
				mMoving = true;
				//if (mCharaSwitch == false){
				//	CHarpoon::spInstance->mRect.x = mRect.x + mPlayerPosition;
				//}
			}
		}
		if (mMoving == true){
			mAniMoving++;
		}
		if (mMoving == false){
			mAniMoving = INITIALIZE;
		}

		if (CKey::Once('J')){
			mJump = mRect.y;
			mj = VJ0;
			mJumping = true;
			mAniJump = DASHANICNT;
		}

		mRect.y += mj;
		if (mRect.y > mJump){
			mj += G;
		}
		else {
			mj = INITIALIZE;
			mJump = INITIALIZE;
			mJumping = false;
			mAniJump = INITIALIZE;
		}
		if (mDashCount > 0){
			mDashCount--;
		}
	}

	if (mDashCount <= 0 && CKey::Once(VK_SPACE)){
		mDflag = true;
		mAniDash = DASHANICNT;
	}
		if (mDflag == true){
			mInvincibleTime = INVINCIBLETIME_DASH;

				if (mDashCount <= 0 && CKey::Push('A')) {
					mRect.x -= 16;
					mMoving = true;
					mDashCount--;
				}
				if (mDashCount <= 0 && CKey::Push('D')) {
					mRect.x += 16;
					mMoving = true;
					mDashCount--;
				}

				if (mDashCount <= 0 && CKey::Push('S')){
					mRect.y -= 16;
					mMoving = true;
					mDashCount--;
				}

				if (mDashCount > -20)
				{
					mDashCount--;
				}
				else
				{
					mDflag = false;
					mDashCount = 60;
				}
		}
		if (mAniDash > 0){
			mAniDash--;
		}

		if (mAttackFlag == false){
			if (mAttackCount <= 0){
				if (mDflag == false){
					if (CKey::Once('K') && mAttackCount <= 0){
						mAttackFlag = false;
						CPlayerAttack *attack = new CPlayerAttack();
						if (mFx >= 0){
							attack->mRect.x = mRect.x + ATTACKRANGE;
						}
						else{
							attack->mRect.x = mRect.x - ATTACKRANGE;
						}
						attack->mRect.y = mRect.y;
						attack->mTag = EPLAYERATTACK;
						attack->mExistCount = EXIST_TIME;
						mAttackCount = EXIST_TIME;
						mAttackFlag = true;
					}
				}
			}
		}
		mAttackCount--;

		if (mInvincibleTime > 0){
			mInvincibleTime--;
		}
		if (mAttackCount <= 0){
			mAttackFlag = false;
		}

	
	if (mRect.y<CEnemy::spInstance->mRect.y){
		DrawTaskManager::GetInstance()->ChangePriority(&mDraw);
	}
}

void CPlayer::Render() {
	if (mChara1Dieflg == false){
		if (mAttackCount <= 0  && mInvincibleTime == 0
			&& mMoving == false && mDflag == false && mHp > 0){
			if (CBase::mFx >= 0){
				mRect.Render(TextureChara1, 200, 0, 200, 0);
			}
			else{
				mRect.Render(TextureChara1, 0, 200, 200, 0);
			}
		}
		if (mInvincibleTime != 0 && mAttackCount <= 0 && mDflag == false && mHp > 0){
			mAniCnt++;
			mAniCnt %= ANICNT;
			if (mAniCnt < ANICNT / 2){
				if (CBase::mFx >= 0){
					mRect.Render(TextureChara1, 10, 220, 1020, 773);
				}
				else{
					mRect.Render(TextureChara1, 220, 10, 1020, 773);
				}
			}
		}
		if (mDflag == false){
			if (mAttackCount > 0){
				mAniCnt++;
				mAniCnt %= ANICNT;
				if (mAniCnt < ANICNT / 2){
					if (CBase::mFx >= 0){
						mRect.Render(TextureChara1Attack, 0, 200, 200, 0);
					}
					else{
						mRect.Render(TextureChara1Attack, 200, 0, 254, 14);
					}
				}
				else{
					if (CBase::mFx >= 0){
						mRect.Render(TextureChara1Attack, 280, 468, 254, 14);
					}
					else{
						mRect.Render(TextureChara1Attack, 468, 280, 254, 14);
					}
				}
			}
			if (mMoving == true && mInvincibleTime <= 0 && mDflag == false){
				if (CBase::mFx >= 0){
					if (mAniMoving % 60 < 10){
						mRect.Render(TextureChara1, 200, 0, 400, 200);
					}
					else if (mAniMoving % 60 < 20){
						mRect.Render(TextureChara1, 400, 200, 400, 200);
					}
					else if (mAniMoving % 60 < 30){
						mRect.Render(TextureChara1, 600, 400, 400, 200);
					}
					else if (mAniMoving % 60 < 40){
						mRect.Render(TextureChara1, 200, 0, 600, 400);
					}
					else if (mAniMoving % 60 < 50){
						mRect.Render(TextureChara1, 400, 200, 600, 400);
					}
					else if (mAniMoving % 60 < 60){
						mRect.Render(TextureChara1, 600, 400, 600, 400);
					}

				}


				else{
					if (mAniMoving % 60 < 10){
						mRect.Render(TextureChara1, 0, 200, 400, 200);
					}
					else if (mAniMoving % 60 < 20){
						mRect.Render(TextureChara1, 200, 400, 400, 200);
					}
					else if (mAniMoving % 60 < 30){
						mRect.Render(TextureChara1, 400, 600, 400, 200);
					}
					else if (mAniMoving % 60 < 40){
						mRect.Render(TextureChara1, 0, 200, 600, 400);
					}
					else if (mAniMoving % 60 < 50){
						mRect.Render(TextureChara1, 200, 400, 600, 400);
					}
					else if (mAniMoving % 60 < 60){
						mRect.Render(TextureChara1, 400, 600, 600, 400);
					}
				}


			}
			if (mAniDash > 0){
				if (CBase::mFx >= 0){
					if (mAniDash == DASHANICNT){
						mRect.Render(TextureChara1, 7, 185, 764, 537);
					}
					else if (mAniDash > 0){
						mRect.Render(TextureChara1, 266, 461, 762, 520);
					}
					else if (mAniDash == 0){
						mRect.Render(TextureChara1, 522, 694, 767, 525);
					}
				}


				else{
					if (mAniDash == DASHANICNT){
						mRect.Render(TextureChara1, 7, 185, 764, 537);
					}
					else if (mAniDash > 0){
						mRect.Render(TextureChara1, 461, 266, 762, 520);
					}
					else if (mAniDash == 0){
						mRect.Render(TextureChara1, 694, 522, 767, 525);
					}
				}


			}


		}
		else if (mChara1Die > 30){
			if (CBase::mFx >= 0){
				mRect.Render(TextureChara1Attack, 17, 237, 728, 553);
			}
			else {
				mRect.Render(TextureChara1Attack, 237, 17, 728, 553);
			}
		}
		else {
			if (CBase::mFx >= 0){
				mRect.Render(TextureChara1Attack, 256, 510, 759, 621);
			}
			else {
				mRect.Render(TextureChara1Attack, 510, 256, 759, 621);
			}
		}
	}
}

void CPlayer::Collision(CBase *i, CBase *y){
	if (mRect.Collision(y->mRect)){
		if (y->mTag == EITEM1){
			mHp += 10;
			return;
		}
		if (y->mTag == EITEM2){
			mHp += 30;
			return;
		}
		if (y->mTag == EITEM3){
			mHp += 50;
			return;
		}
		if (y->mTag == EITEM4){
			mHp += 100;
			return;
		}

		if (y->mTag == EKIHOU){
			mHp += 10;
			return;
		}


		if (y->mTag == EWAKAME){
			if (CKey::Push('A')) {
				mRect.x += 1.5;
				mMoving = true;
				//mDashCount--;

			}
			if (CKey::Push('D')) {
				mRect.x -= 0.5;
				mMoving = true;
				//mDashCount--;

			}

			if (CKey::Push('S')){
				mRect.y += 0.5;
				mMoving = true;
				//mDashCount--;

			}
		}



		if (y->mEnabled){
			if (y->mTag == EENEMYATTACK_S){
					mHp -= 60;
					return;
			}
		}
	}


	if (mRect.y == CEnemy::spInstance->mRect.y){
		if (mInvincibleTime <= 0){
			if (y->mEnabled){
				if (mRect.Collision(y->mRect)){
					if (y->mTag == EENEMYATTACK_S){
						mHp -= 10;
						mInvincibleTime = INVINCIBLETIME;
						if (CBase::mFx >= 0){
							mRect.x -= 30;
						}
						else{
							mRect.x += 30;
						}
						return;
					}

					if (mTag == EENEMYATTACK_F){
						mHp -= 80;
						mInvincibleTime = INVINCIBLETIME;

					}
				}
			}
		}
	}


	if (mRect.y == CEnemy::spInstance->mRect.y){
		if (mInvincibleTime <= 0){
			if (y->mEnabled){
				if (mRect.Collision(y->mRect)){
					if (y->mTag == EMINE){
						//if (mAttack == true){
						//	mHp-=50;
						//}

						return;
					}
				}
			}
		}
	}
}


