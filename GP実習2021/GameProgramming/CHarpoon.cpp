#include "CHarpoon.h"
#include "CPlayer.h"
#include "CKey.h"
#include "SampleProperty.h"
#include "TaskManager.h"
#include "DrawTaskManager.h"
#include "CEnemy.h"

#define INITIALIZE 0;	//初期化
#define EXIST_TIME 30	//攻撃判定の存在時間
#define ATTACKRANGE 300	//攻撃射程
#define ATTACKPOSITION 100	//攻撃判定出現場所
#define ACCUMULATE 40
#define INVINCIBLETIME 60	//無敵時間
#define INVINCIBLETIME_DASH 3	//ダッシュ回避時間
#define DIE 60
#define ANICNT 40
#define DASHANICNT 120


//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture TextureChara2;
extern CTexture TextureChara2Attack;

int CHarpoon::mAttackCount;
CHarpoon*CHarpoon::spInstance = 0;
bool CHarpoon::mJumping;

CHarpoon::CHarpoon()
: mDashPosition(0)
, mJump(0)
, mdflag(false)
, mInvincibleTime(0)
, mAniMoving(0)
, mChara2Die(0)
, mChara2DieFlg(false)
, mAniCnt(0)
{
	//描画タスクに登録
	mDraw.RegistDraw(this, (DrawFunc)&CHarpoon::Render, DrawPriority::Transparent, "Harpoon");
	mTag = EHARPOON;
	mRect.x = -450;
	mRect.y = -200;
	mRect.w = 80;
	mRect.h = 20;
	spInstance = this;
	mAttackCount = INITIALIZE;
}

void CHarpoon::Update() {
	CPlayer::mMoving = false;
	if (CPlayer::mChara1Hp > 0){
		if (CPlayer::mAttackCount <= 0 && mAttackCount <= 0){

			if (CKey::Push('A')) {
				CPlayer::mMoving = true;
				if (CPlayer::mCharaSwitch == true){
					CPlayer::spInstance->mRect.x = mRect.x + CPlayer::mPlayerPosition;
					CPlayer::mMoving = true;
				}
			}
			if (CKey::Push('D')) {
				CPlayer::mMoving = true;
				if (CPlayer::mCharaSwitch == true){
					CPlayer::spInstance->mRect.x = mRect.x + CPlayer::mPlayerPosition;
					CPlayer::mMoving = true;
				}
			}
			if (CKey::Push('W')){
				CPlayer::mMoving = true;
				if (CPlayer::mCharaSwitch == true){
					CPlayer::spInstance->mRect.y = mRect.y + CPlayer::mPlayerPosition;
					CPlayer::mMoving = true;
				}
			}
			if (CKey::Push('S')){
				CPlayer::mMoving = true;
				if (CPlayer::mCharaSwitch == true){
					CPlayer::spInstance->mRect.y = mRect.y + CPlayer::mPlayerPosition;
					CPlayer::mMoving = true;
				}
			}
		}
		if (CPlayer::mMoving == true){
			mAniMoving++;
		}
		if (CPlayer::mMoving == false){
			CPlayer::mMoving = INITIALIZE;
		}

		if (CKey::Once('J') /*&& mJflag == false*/){
			CPlayer::spInstance->mRect.y = mRect.y + CPlayer::mPlayerPosition;
			CPlayer::spInstance->mRect.x = mRect.x + CPlayer::mPlayerPosition;
			CPlayer::mMoving = true;
		}
		mRect.y += mj;

		if (CKey::Push(VK_SPACE) && mdflag == false){
			mDashPosition = mRect.y;
			mdflag = true;
			mAniDash = DASHANICNT;
		}
	/*	mRect.y += md;
		if {
			mj = INITIALIZE;
			mDashPosition = INITIALIZE;
			mdflag = false;
			mAniDash = INITIALIZE;
		}*/
		if (mdflag == true){
			mInvincibleTime = INVINCIBLETIME_DASH;
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

		if (CPlayer::mCharaSwitch == true){
			if (mAttackCount <= 0){
				if (mdflag == false){
					if (CKey::Once('K')){
						if (CPlayer::mAttackFlag == false){
							/*if (mFx >= 0){
							attack->mRect.x = mRect.x + ATTACKRANGE;
							}
							else{
							attack->mRect.x = mRect.x - ATTACKRANGE;
							}
							attack->mRect.y = mRect.y - ATTACKPOSITION;
							attack->mExistCount = EXIST_TIME;
							mAttackCount = EXIST_TIME;
							CPlayer::mAttackFlag = true;*/
							}
					}
				}



				if (mdflag == false){

					if (CPlayer::mAttackFlag == false){
						/*if (mFx >= 0){
							attack->mRect.x = mRect.x + ATTACKRANGE;
						}
						else{
							attack->mRect.x = mRect.x - ATTACKRANGE;
						}
						attack->mRect.y = mRect.y - ATTACKPOSITION;
						attack->mExistCount = EXIST_TIME;
						CPlayer::mAttackFlag = true;*/
					}

				}

			}
		}
		if (mInvincibleTime > 0){
			mInvincibleTime--;
		}
		mAttackCount--;
		if (mAttackCount <= 0){
			CPlayer::mAttackFlag = false;
		}
	}
	if (mRect.y < CEnemy::spInstance->mRect.y){
		DrawTaskManager::GetInstance()->ChangePriority(&mDraw);
	}
}

void CHarpoon::Render() {
	if (mChara2DieFlg == false){
		if (CPlayer::mMoving == false && mAttackCount <= 0 && mInvincibleTime == 0 && mdflag == false){
				if (CBase::mFx >= 0){
					mRect.Render(TextureChara2, 11, 115, 252, 54);
					}
					else{
					mRect.Render(TextureChara2, 115, 11, 252, 54);
					}
		}
		if (mInvincibleTime != 0 && mAttackCount <= 0 && mdflag == false){
			mAniCnt++;
			mAniCnt %= ANICNT;
			if (mAniCnt < ANICNT / 2){
				if (CBase::mFx >= 0){
					mRect.Render(TextureChara2, 7, 117, 1018, 826);
				}
				else{
					mRect.Render(TextureChara2, 117, 7, 1018, 826);
				}
			}
		}
		if (CPlayer::mCharaSwitch == true && mdflag == false){
			if (mAttackCount > 0){
				mAniCnt++;
				mAniCnt %= ANICNT;
				if (mAniCnt < ANICNT / 2){
					if (CBase::mFx >= 0){
						mRect.Render(TextureChara2Attack, 10, 114, 252, 57);
					}
					else{
						mRect.Render(TextureChara2Attack, 114, 10, 252, 57);
					}
				}
				else{
					if (CBase::mFx >= 0){
						mRect.Render(TextureChara2Attack, 139, 248, 252, 57);
					}
					else{
						mRect.Render(TextureChara2Attack, 248, 139, 252, 57);
					}
				}
			}

		}
		if (CPlayer::mMoving == true && mInvincibleTime <= 0 && mdflag == false){
			if (CBase::mFx >= 0){
				if (mAniMoving % 40 < 10){
					mRect.Render(TextureChara2, 138, 241, 507, 311);
				}
				else if (mAniMoving % 40 < 20){
					mRect.Render(TextureChara2, 10, 113, 507, 311);
				}
				else if (mAniMoving % 40 < 30){
					mRect.Render(TextureChara2, 138, 241, 507, 311);
				}
				else if (mAniMoving % 40 < 40){
					mRect.Render(TextureChara2, 266, 370, 510, 314);
				}
			}
			else{
				if (mAniMoving % 40 < 10){
					mRect.Render(TextureChara2, 241, 138, 507, 311);
				}
				else if (mAniMoving % 40 < 20){
					mRect.Render(TextureChara2, 113, 10, 507, 311);
				}
				else if (mAniMoving % 40 < 30){
					mRect.Render(TextureChara2, 241, 138, 507, 311);
				}
				else if (mAniMoving % 40 < 40){
					mRect.Render(TextureChara2, 370, 266, 510, 314);
				}
			}
		}
	}
}

void CHarpoon::Collision(CBase *i, CBase *y){
	if (CPlayer::mCharaSwitch == true){
		if (mRect.Collision(y->mRect)){
			if (y->mTag == EITEM1){
				return;
			}
			if (y->mTag == EITEM2){
				return;
			}
			if (y->mTag == EITEM2){
				return;
			}
			if (y->mTag == EITEM2){
				return;
			}
		}
		if (mRect.y == CEnemy::spInstance->mRect.y){
			if (mInvincibleTime <= 0){
				if (y->mEnabled){
					if (mRect.Collision(y->mRect)){
						if (y->mTag == EENEMYATTACK_F){
							mInvincibleTime = INVINCIBLETIME;
							if (CBase::mFx >= 0){
								mRect.x -= 30;
								CPlayer::spInstance->mRect.x -= 30;
							}
							else{
								mRect.x += 30;
								CPlayer::spInstance->mRect.x += 30;
							}
							return;
						}
						if (y->mTag == EENEMYATTACK_S){
							mInvincibleTime = INVINCIBLETIME;
							if (CBase::mFx >= 0){
								mRect.x -= 30;
								CPlayer::spInstance->mRect.x -= 30;
							}
							else{
								mRect.x += 30;
								CPlayer::spInstance->mRect.x += 30;
							}
							return;
						}
						if (y->mTag == EBOSSATTACK_S){
							mInvincibleTime = INVINCIBLETIME;
							if (CBase::mFx >= 0){
								mRect.x -= 30;
								CPlayer::spInstance->mRect.x -= 30;
							}
							else{
								mRect.x += 30;
								CPlayer::spInstance->mRect.x += 30;
							}
							return;
						}

						if (y->mTag == EBOSSATTACK_A){
							mInvincibleTime = INVINCIBLETIME;
							if (CBase::mFx >= 0){
								mRect.x -= 30;
								CPlayer::spInstance->mRect.x -= 30;
							}
							else{
								mRect.x += 30;
								CPlayer::spInstance->mRect.x += 30;
							}
							return;
						}
					}
				}
			}
		}
	}
}