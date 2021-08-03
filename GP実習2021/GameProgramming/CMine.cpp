#include "CMine.h"
#include "CTexture.h"
#include "SampleProperty.h"
#include "CPlayer.h"
#include "CEnemyAttack.h"
#include "CSceneGame.h"
#include "DrawTaskManager.h"
#include "CScore.h"

#define ATTACKLAG 180		//�U���J�n�܂ł̃��O
#define INVINCIBLETIME 60	//���G����
#define HP 1				//�̗�
#define ANIATTACK 120		//�U���A�j���[�V�����p
#define SCORE 150			//�X�R�A

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture TextureMine;
extern CTexture TextureMine2;

CMine::CMine()
:mAttackLag(ATTACKLAG)
, mHp(HP)
, mInvincibleTime(0), mInvincibleFlag(false)
, mAniAttack(0)
, mAttack(false)
, mMoving(false)
, mAniMoving(0)
, mDeath(false)
, mDeathCount(0)
, ReduCnt(180)

{
	m_Draw.RegistDraw(this, (DrawFunc)&CMine::Render, DrawPriority::Transparent, "CMine");
	mRect.x = 250;
	mRect.y = 250;
	mRect.w = 125;
	mRect.h = 125;

	mTag = EMINE;
	spInstance = this;
}

void CMine::Update() {

	if (mRect.y > CPlayer::spInstance->mRect.y){
		DrawTaskManager::GetInstance()->ChangePriority(&m_Draw);
	}

	//HP��0��؂�Ǝ��S�t���O������
	if (mHp <= 0 && mDeath == false){
		mDeath = true;
		mDeathCount = 60;
		CScore::mScore += SCORE;
	}

	if (mDeath == true && mDeathCount > 0){
		mDeathCount--;
		if (mDeathCount == 30){
			if (mRect.x > CPlayer::spInstance->mRect.x){
				mRect.x += 30;
			}
			else{
				mRect.x -= 30;
			}
			mRect.y -= 30;
			mRect.w = 80;
			mRect.h = 55;
		}
		if (mDeathCount == 0){
			//���S
			Kill();
		}
	}
	//���S�t���O�����ƃ��^�[��
	if (mDeath)return;

	if (mRect.y == CPlayer::spInstance->mRect.y&&mAttack == false){
		mAttack = true;
		mMoving = false;
		//�U���t���O��������120�t���[����ɍU�����邽�߂̒l��ݒ�
		mAttackLag = ATTACKLAG;
	}

	//0�ɂȂ�܂Ō��炷
	if (mAttackLag > 0){
		mAttackLag--;
	}

	//�U��
	if (mAttack == true && mAttackLag == 0){
		if (mRect.x < CPlayer::spInstance->mRect.x){
			CEnemyAttack *EnemyAttack = new CEnemyAttack();
			EnemyAttack->mRect.x = mRect.x + 20;
			mAniAttack = ANIATTACK;
			//�U���t���O��������180�t���[����ɍU�����邽�߂̒l��ݒ�
			mAttackLag = ATTACKLAG;
		}
		else{
			CEnemyAttack *EnemyAttack = new CEnemyAttack();
			EnemyAttack->mRect.x = mRect.x - 20;
			mAniAttack = ANIATTACK;
			//�U���t���O��������180�t���[����ɍU�����邽�߂̒l��ݒ�
			mAttackLag = ATTACKLAG;
		}
	}

	if (mAniAttack > 0){
		mAniAttack--;
		if (mAniAttack == 0){
			//�U���t���O��false�ɂ���
			mAttack = false;
		}
	}


	if (mAttack == false){
		mMoving = true;
		mAniMoving++;

	}

}

void CMine::Render() {

	//���S�t���O�������Ă��Ȃ��Ƃ�
	if (mDeath == false){
		//���G�t���O�������Ă��Ȃ��Ƃ�
		if (mInvincibleFlag == false){
			if (mMoving == false){
				if (mAniAttack == 0){
					mRect.Render(TextureMine, 0, 800, 800, 0);
				}
				//�U�����̃A�j���[�V����
				if (mAniAttack > 180){
					mRect.Render(TextureMine2, 0, 800, 800, 0);
				}
				else if (mAniAttack > 0){
					mRect.Render(TextureMine2, 0, 800, 800, 0);
				}
			}

			else{
				if (mAniMoving % 180 < 60){
					mRect.Render(TextureMine2, 0, 800, 800, 0);
				}
				else if (mAniMoving % 180 < 90){
					mRect.Render(TextureMine2, 0, 800, 800, 0);
				}
				else if (mAniMoving % 180 < 180){
					mRect.Render(TextureMine2, 0, 800, 800, 0);
				}

			}

		}
	}
}

void CMine::Collision(CBase *i, CBase *y) {
	//if (mRect.y - CPlayer::spInstance->mRect.y < 20){
	//}
	////�v���C���[�̍U���ɓ��������Ƃ�
	//if (y->mTag == EPLAYERATTACK){
	//	if (mRect.Collision(y->mRect)){
	//		//���G��ԂŖ������
	//		if (mInvincibleFlag == false){
	//			//�̗͂�����
	//			mHp -= 1;
	//		}
	//		return;
	//	}
	//}

	//�v���C���[�ɓ��������Ƃ�
	if (y->mTag == EPLAYER){
		if (mRect.Collision(y->mRect)){

			if (ReduCnt > 0){
				ReduCnt--;
				mMoving == false;
				if (ReduCnt < 0){
					ReduCnt++;
					if (mAttackLag = ATTACKLAG){
						Kill();
					}
				}
			}

		}
		return;
	}
}


CMine*CMine::spInstance = 0;