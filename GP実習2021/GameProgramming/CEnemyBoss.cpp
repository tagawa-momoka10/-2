#include "CEnemyBoss.h"
#include "CTexture.h"
#include "SampleProperty.h"
#include "CPlayer.h"
#include "CEnemyAttack.h"
#include "CSceneGame.h"
#include "CSceneGameBoss.h"
#include "CScore.h"

#define ATTACKLAG_L 150			//���ɍU���\�ɂȂ�܂ł̎���(200�t���[��)(������)
#define ATTACKSIZE_L_W 20		//�U���̉���(������)
#define ATTACKSIZE_L_H 10		//�U���̏c��(������)

#define ATTACKLAG_S 150			//���ɍU���\�ɂȂ�܂ł̎���(150�t���[��)(�ߋ���)
#define ATTACKSIZE_S_W 100		//�U���̉���(�ߋ���)
#define ATTACKSIZE_S_H 30		//�U���̏c��(�ߋ���)

#define ATTACKLAG_A 200			//���ɍU���\�ɂȂ�܂ł̎���(400�t���[��)(�S�̍U��)
#define ATTACKSIZE_A 70			//�U���̃T�C�Y(�S�̍U��)

#define INVINCIBLETIME 60		//���G����
#define HP 20					//�̗�
#define COMBO 3*60				//�R���{��������2�b

#define ANIATTACK_A 40
#define ANIATTACK_L 30
#define ANIATTACK_S 30

#define SCORE 300


//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
//extern CTexture TextureBoss1;
//extern CTexture TextureBoss2;
//extern CTexture TextureBoss3;
//extern CTexture TextureBoss4;

CEnemyBoss::CEnemyBoss()
:mAttackLag_L(60), mAttackLag_S(ATTACKLAG_S), mAttackLag_A(ATTACKLAG_A)
, mAniAttack_L(-20), mAniAttack_A(0), mAniAttack_S(-30), mAniStopMove(0)
, mInvincibleTime(0), mInvincibleFlag(false)
, mHp(HP)
, mRandom(0), mStopRandom(false)
, mY1(0), mY2(0), mX1(0), mX2(0)
, mDeath(false), mDeathCount(0)
{
	m_Draw.RegistDraw(this, (DrawFunc)&CEnemyBoss::Render, DrawPriority::Transparent, "CEnemyBoss");
	mRect.w = 250;
	mRect.h = 350;
	mTag = EBOSS;
	mAttack_S = false;
	mAttack_L = false;
	mAttack_A = false;
}

void CEnemyBoss::Update() {
	//HP��0��؂�Ǝ��S�t���O�����A�R���{���Z�A�K�E�Z�J�E���g���Z
	if (mHp <= 0 && mDeath == false){
		mDeath = true;
		mDeathCount = 300;
		CScore::mScore += SCORE;
	}

	if (mDeath == true && mDeathCount > 0){
		mDeathCount--;
		if (mDeathCount == 0){
			//���S
			Kill();
			CSceneGameBoss::mBossCount -= 1;
		}
	}

	//���S�t���O�����ƃ��^�[��
	if (mDeath)return;



	mAniStopMove++;

	if (mStopRandom == false){
		mRandom = rand() % 3;
	}

	/////////////////////////////////////////////////////////////////////

	//���G���Ԃ�0�ɂȂ�܂ŃJ�E���g�_�E��
	if (mInvincibleTime > 0){
		mInvincibleTime--;
	}
	//���G���Ԃ�0�ɂȂ�Ɩ��G��ԉ���
	if (mInvincibleTime <= 0){
		mInvincibleFlag = false;
	}

	/////////////////////////////////////////////////////////////////////

	if (mRandom == 0){
		//�̗͂�������؂�ƑS�̍U���t���O������
		if (mHp <= 10){
			if (mAttackLag_A >= 0){
				mAttackLag_A--;
				if (mAttackLag_A == ANIATTACK_A){
					mAniAttack_A = ANIATTACK_A;
					mStopRandom = true;
				}
				if (mAttackLag_A == 0){
					mAttack_A = true;
				}
			}
			if (mAniAttack_A > 0){
				mAniAttack_A--;
			}
		}
		//�U��(�S�̍U��)
		if (mAttack_A == true && mAttackLag_A == 0){
			CEnemyAttack *EnemyAttack_A_1 = new CEnemyAttack();
			EnemyAttack_A_1->mRect.x = 200;
			EnemyAttack_A_1->mRect.y = 610;
			EnemyAttack_A_1->mRect.w = ATTACKSIZE_A;
			EnemyAttack_A_1->mRect.h = ATTACKSIZE_A;
			EnemyAttack_A_1->mTag = EBOSSATTACK_A;

			CEnemyAttack *EnemyAttack_A_2 = new CEnemyAttack();
			EnemyAttack_A_2->mRect.x = 0;
			EnemyAttack_A_2->mRect.y = 610;
			EnemyAttack_A_2->mRect.w = ATTACKSIZE_A;
			EnemyAttack_A_2->mRect.h = ATTACKSIZE_A;
			EnemyAttack_A_2->mTag = EBOSSATTACK_A;

			CEnemyAttack *EnemyAttack_A_3 = new CEnemyAttack();
			EnemyAttack_A_3->mRect.x = -200;
			EnemyAttack_A_3->mRect.y = 610;
			EnemyAttack_A_3->mRect.w = ATTACKSIZE_A;
			EnemyAttack_A_3->mRect.h = ATTACKSIZE_A;
			EnemyAttack_A_3->mTag = EBOSSATTACK_A;

			CEnemyAttack *EnemyAttack_A_4 = new CEnemyAttack();
			EnemyAttack_A_4->mRect.x = -400;
			EnemyAttack_A_4->mRect.y = 610;
			EnemyAttack_A_4->mRect.w = ATTACKSIZE_A;
			EnemyAttack_A_4->mRect.h = ATTACKSIZE_A;
			EnemyAttack_A_4->mTag = EBOSSATTACK_A;

			CEnemyAttack *EnemyAttack_A_5 = new CEnemyAttack();
			EnemyAttack_A_5->mRect.x = -600;
			EnemyAttack_A_5->mRect.y = 610;
			EnemyAttack_A_5->mRect.w = ATTACKSIZE_A;
			EnemyAttack_A_5->mRect.h = ATTACKSIZE_A;
			EnemyAttack_A_5->mTag = EBOSSATTACK_A;

			CEnemyAttack *EnemyAttack_A_6 = new CEnemyAttack();
			EnemyAttack_A_6->mRect.x = -800;
			EnemyAttack_A_6->mRect.y = 610;
			EnemyAttack_A_6->mRect.w = ATTACKSIZE_A;
			EnemyAttack_A_6->mRect.h = ATTACKSIZE_A;
			EnemyAttack_A_6->mTag = EBOSSATTACK_A;

			mAttackLag_A = ATTACKLAG_A;
			mAttack_A = false;
		}
		if (mAniAttack_A == 0){
			mStopRandom = false;
		}
	}

	///////////////////////////////////////////////////////////////////

	if (mRandom == 1){
		//0�ɂȂ�܂Ō��炷
		if (mAttackLag_S >= 0){
			mAttackLag_S--;
			if (mAttackLag_S == ANIATTACK_S){
				mAniAttack_S = ANIATTACK_S;
				mStopRandom = true;
			}
			if (mAttackLag_S == 0){
				mAttack_S = true;
			}
		}

		if (mAniAttack_S > -30){
			mAniAttack_S--;
		}

		//�U��(�ߋ���)
		if (mAttack_S == true && mAttackLag_S == 0){
			CEnemyAttack *EnemyAttack_S = new CEnemyAttack();
			EnemyAttack_S->mRect.x = mRect.x - 140;
			EnemyAttack_S->mRect.y = mRect.y - 190;
			EnemyAttack_S->mRect.w = ATTACKSIZE_S_W;
			EnemyAttack_S->mRect.h = ATTACKSIZE_S_H;
			EnemyAttack_S->mAttackTime = 10; //��ʂ�10�t���[���c��
			EnemyAttack_S->mTag = EBOSSATTACK_S;
			mAttackLag_S = ATTACKLAG_S;
			//�U���t���O��false�ɂ���
			mAttack_S = false;
		}
		if (mAniAttack_S == -30){
			mStopRandom = false;
		}
	}

	////////////////////////////////////////////////////////////////////

	if (mRandom == 2){
		//0�ɂȂ�܂Ō��炷
		if (mAttackLag_L > 0){
			mAttackLag_L--;
			if (mAttackLag_L == ANIATTACK_L){
				mAniAttack_L = ANIATTACK_L;
				mStopRandom = true;
			}
			if (mAttackLag_L){
				mAttack_L = true;
			}
		}

		if (mAniAttack_L > -20){
			mAniAttack_L--;
		}

		//�U��(������)
		if (mAttack_L == true && mAttackLag_L == 0){
			CEnemyAttack *EnemyAttack_L = new CEnemyAttack();
			EnemyAttack_L->mRect.x = mRect.x - 200;
			EnemyAttack_L->mRect.y = mRect.y - 160;
			EnemyAttack_L->mRect.w = ATTACKSIZE_L_W;
			EnemyAttack_L->mRect.h = ATTACKSIZE_L_H;
			mAttackLag_L = ATTACKLAG_L;
			mAttack_L = false;
		}
		if (mAniAttack_L == -20){
			mStopRandom = false;
		}
	}

	////////////////////////////////////////////////////////////////////
}

void CEnemyBoss::Render() {
	////���S�t���O�������Ă��Ȃ��Ƃ�
	//if (mDeath == false){
	//	//�Î~���Ă���Ƃ�
	//	if (mAniAttack_L == -20 && mAniAttack_S == -30 && mAniAttack_A == 0){
	//		//���G��ԂłȂ��Ƃ�
	//		if (mInvincibleFlag == false){
	//			if (mAniStopMove % 40 < 20){
	//				mRect.Render(TextureBoss1, 0, 499, 699, 0);
	//			}
	//			else{
	//				mRect.Render(TextureBoss1, 500, 999, 699, 0);
	//			}
	//		}
	//		//���G��Ԃ̎�
	//		else{
	//			//�_�ł���
	//			if (mInvincibleTime % 10 < 5){
	//				mRect.Render(TextureBoss1, 0, 0, 0, 0);
	//			}
	//			else{
	//				if (mAniStopMove % 40 < 20){
	//					mRect.Render(TextureBoss1, 0, 499, 699, 0);
	//				}
	//				else{
	//					mRect.Render(TextureBoss1, 500, 999, 699, 0);
	//				}
	//			}
	//		}
	//	}
	//	else{
	//		if (mAniAttack_S > -30){
	//			//���G��ԂłȂ��Ƃ�
	//			if (mInvincibleFlag == false){
	//				if (mAniAttack_S > 0){
	//					mRect.Render(TextureBoss1, 0, 499, 1398, 699);
	//				}
	//				else if (mAniAttack_S > -15){
	//					mRect.Render(TextureBoss1, 500, 999, 1400, 701);
	//				}
	//				else if (mAniAttack_S >= -30){
	//					mRect.Render(TextureBoss2, 0, 499, 695, -4);
	//				}
	//			}
	//			//���G��Ԃ̎�
	//			else{
	//				//�_�ł���
	//				if (mInvincibleTime % 10 < 5){
	//					mRect.Render(TextureBoss1, 0, 0, 0, 0);
	//				}
	//				else{
	//					if (mAniAttack_S > 0){
	//						mRect.Render(TextureBoss1, 0, 499, 1398, 699);
	//					}
	//					else if (mAniAttack_S > -15){
	//						mRect.Render(TextureBoss1, 500, 999, 1400, 701);
	//					}
	//					else if (mAniAttack_S >= -30){
	//						mRect.Render(TextureBoss2, 0, 499, 695, -4);
	//					}
	//				}
	//			}
	//		}

	//		if (mAniAttack_L > -20){
	//			//���G��ԂłȂ��Ƃ�
	//			if (mInvincibleFlag == false){
	//				if (mAniAttack_L >= 20){
	//					mRect.Render(TextureBoss2, 0, 499, 695, -4);
	//				}
	//				else if (mAniAttack_L > 10){
	//					mRect.Render(TextureBoss2, 499, 998, 698, -1);
	//				}
	//				else if (mAniAttack_L > 0){
	//					mRect.Render(TextureBoss2, 0, 499, 1395, 696);
	//				}
	//				else if (mAniAttack_L > -10){
	//					mRect.Render(TextureBoss2, 499, 998, 698, -1);
	//				}
	//				else if (mAniAttack_L >= -20){
	//					mRect.Render(TextureBoss2, 0, 499, 695, -4);
	//				}
	//			}
	//			//���G��Ԃ̂Ƃ�
	//			else{
	//				//�_�ł���
	//				if (mInvincibleTime % 10 < 5){
	//					mRect.Render(TextureBoss1, 0, 0, 0, 0);
	//				}
	//				else{
	//					if (mAniAttack_L >= 20){
	//						mRect.Render(TextureBoss2, 0, 499, 695, -4);
	//					}
	//					else if (mAniAttack_L > 10){
	//						mRect.Render(TextureBoss2, 499, 998, 698, -1);
	//					}
	//					else if (mAniAttack_L > 0){
	//						mRect.Render(TextureBoss2, 0, 499, 1395, 696);
	//					}
	//					else if (mAniAttack_L > -10){
	//						mRect.Render(TextureBoss2, 499, 998, 698, -1);
	//					}
	//					else if (mAniAttack_L >= -20){
	//						mRect.Render(TextureBoss2, 0, 499, 695, -4);
	//					}
	//				}
	//			}
	//		}

	//		if (mAniAttack_A > 0){
	//			if (mInvincibleFlag == false){
	//				if (mAniAttack_A > 30){
	//					mRect.Render(TextureBoss3, 0, 499, 699, 0);
	//				}
	//				else if (mAniAttack_A > 20){
	//					mRect.Render(TextureBoss3, 500, 999, 699, 0);
	//				}
	//				else if (mAniAttack_A > 10){
	//					mRect.Render(TextureBoss3, 0, 499, 699, 0);
	//				}
	//				else if (mAniAttack_A >= 0){
	//					mRect.Render(TextureBoss3, 500, 999, 699, 0);
	//				}
	//			}
	//			else{
	//				//�_�ł���
	//				if (mInvincibleTime % 10 < 5){
	//					mRect.Render(TextureBoss1, 0, 0, 0, 0);
	//				}
	//				else{
	//					if (mAniAttack_A > 30){
	//						mRect.Render(TextureBoss3, 0, 499, 699, 0);
	//					}
	//					else if (mAniAttack_A > 20){
	//						mRect.Render(TextureBoss3, 500, 999, 699, 0);
	//					}
	//					else if (mAniAttack_A > 10){
	//						mRect.Render(TextureBoss3, 0, 499, 699, 0);
	//					}
	//					else if (mAniAttack_A >= 0){
	//						mRect.Render(TextureBoss3, 500, 999, 699, 0);
	//					}
	//				}
	//			}
	//		}
	//	}
	//}
	//���S�t���O�������Ă���Ƃ�
	/*else{
		if (mDeathCount > 180){
			mRect.Render(TextureBoss4, 499, 998, 697, -2);
		}
		else if (mDeathCount > 120){
			mRect.Render(TextureBoss4, -1, 498, 697, -2);
		}
		else if (mDeathCount > 0){
			if (mDeathCount % 10 < 5){
				mRect.Render(TextureBoss4, 0, 0, 0, 0);
			}
			else{
				mRect.Render(TextureBoss4, -1, 498, 697, -2);
			}
		}
	}*/

	/*if (mInvincibleTime % 10 < 5){
	mRect.Render(TextureBoss2, 25, 475, 697, 26);
	}
	else{
	mRect.Render();
	}*/
}

void CEnemyBoss::Collision(CBase *i, CBase *y) {

	//�v���C���[1�Ɠ��������Ƃ�
		if (y->mTag == EPLAYER){
			if (y->mEnabled){
				if (mRect.Collision(y->mRect)){
					//�ߋ����U���̃t���O������
					//mAttack_S = true;
					return;
				}
			}
		}


	}
