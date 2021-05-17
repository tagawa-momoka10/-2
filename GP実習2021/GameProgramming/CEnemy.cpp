#include "CEnemy.h"
#include "CTexture.h"
#include "SampleProperty.h"
#include "CPlayer.h"
#include "CEnemyAttack.h"
#include "CSceneGame.h"
#include "DrawTaskManager.h"
#include "CScore.h"

#define SPEED 1				//�ړ����x
#define COMBO 3*60			//�R���{��������2�b
#define INVINCIBLETIME 60	//���G����
#define ATTACKSIZE 55		//�U������̑傫��
#define HP 2				//�̗�
#define ANIATTACK 20		//�U���A�j���[�V�����p
#define SCORE 100			//�����G���j���̃X�R�A

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture TextureEnemy1;

CEnemy::CEnemy()
:mAttackLag(90)
, mHp(HP)
, mAttack(false)
, mInvincibleTime(0)
, mInvincibleFlag(false)
, mMoving(true)
, mAniAttack(-10)
, mAniMoving(0)
, mDeath(false)
, mDeathCount(0)
{
	m_Draw.RegistDraw(this, (DrawFunc)&CEnemy::Render, DrawPriority::Transparent, "CEnemy");
	mRect.w = 50;
	mRect.h = 80;
	mTag = EENEMY_F;
	spInstance = this;
}

void CEnemy::Update() {

	//HP��0��؂�Ǝ��S�t���O�����A�X�R�A���Z
	if (mHp <= 0 && mDeath == false){
		mDeath = true;
		mDeathCount = 60;
		//CScore::mScore += SCORE;
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
			mRect.h = 50;
		}
		if (mDeathCount == 0){
			//���S
			Kill();
		}
	}

	//���S�t���O�����ƃ��^�[��
	if (mDeath)return;

	//���G���Ԃ�0�ɂȂ�܂ŃJ�E���g�_�E��
	if (mInvincibleTime > 0){
		mInvincibleTime--;
	}
	//���G���Ԃ�0�ɂȂ�Ɩ��G��ԉ���
	if (mInvincibleTime <= 0){
		mInvincibleFlag = false;
	}

	//0�ɂȂ�܂Ō��炷
	if (mAttackLag > 0){
		mAttackLag--;
		if (mAttackLag == 20){
			mAniAttack = ANIATTACK;
		}
	}

	//�U��
	if (mAttack == true && mAttackLag == 0){
		if (mRect.x < CPlayer::spInstance->mRect.x){
			CEnemyAttack *EnemyAttack = new CEnemyAttack();
			EnemyAttack->mRect.x = mRect.x + 30;
			EnemyAttack->mRect.y = mRect.y;
			EnemyAttack->mRect.w = ATTACKSIZE;
			EnemyAttack->mRect.h = 60;
			EnemyAttack->mAttackTime = 10;
			EnemyAttack->mTag = EENEMYATTACK_F;
		}
		else{
			CEnemyAttack *EnemyAttack = new CEnemyAttack();
			EnemyAttack->mRect.x = mRect.x - 30;
			EnemyAttack->mRect.y = mRect.y;
			EnemyAttack->mRect.w = ATTACKSIZE;
			EnemyAttack->mRect.h = 60;
			EnemyAttack->mAttackTime = 10;
			EnemyAttack->mTag = EENEMYATTACK_F;
		}
		//�U���t���O��false�ɂ���
		mAttack = false;
	}

	if (mAniAttack > -10){
		mAniAttack--;
	}

	if (mAttack == false){
		mMoving = true;
		mAniMoving++;
		//�v���C���[�ɒǔ����Ĉړ�����
		if (mRect.x < CPlayer::spInstance->mRect.x){
			mRect.x += SPEED;
		}
		else if (CPlayer::spInstance->mRect.x < mRect.x){
			mRect.x -= SPEED;
		}

		if (mRect.y < CPlayer::spInstance->mRect.y){
			mRect.y += SPEED;
			if (mRect.y > -140){
				mRect.y -= SPEED;
			}
		}
		else if (CPlayer::spInstance->mRect.y < mRect.y){
			mRect.y -= SPEED;
		}
	}


	if (mRect.y>CPlayer::spInstance->mRect.y){
		DrawTaskManager::GetInstance()->ChangePriority(&m_Draw);
	}

	//�U���t���O�������Ă���Ԃ̓��^�[��
	if (mAttack)return;

	//�U���t���O��������90�t���[����ɍU�����邽�߂̒l��ݒ�
	mAttackLag = 90;
}

void CEnemy::Render() {
	//������
	if (mRect.x > CPlayer::spInstance->mRect.x){
		//���S�t���O�������Ă��Ȃ��Ƃ�
		if (mDeath == false){
			if (mInvincibleFlag == false){
				//�ړ����Ă��Ȃ��Ƃ�
				if (mMoving == false){
					if (mAniAttack == -10){
						mRect.Render(TextureEnemy1, 10, 117, 252, 8);
					}
					else if (mAniAttack > 10){
						mRect.Render(TextureEnemy1, 137, 254, 764, 520);
					}
					else if (mAniAttack > 0){
						mRect.Render(TextureEnemy1, 12, 120, 764, 520);
					}
					else if (mAniAttack > -10){
						mRect.Render(TextureEnemy1, 137, 254, 764, 520);
					}
				}
				//�ړ����Ă���Ƃ�
				else{
					if (mAniMoving % 60 < 30){
						mRect.Render(TextureEnemy1, 10, 117, 508, 264);
					}
					else if (mAniMoving % 60 < 60){
						mRect.Render(TextureEnemy1, 266, 373, 508, 264);
					}
				}
			}
			//���G�t���O�������Ă��Ȃ��Ƃ�
			else{
				//�_�ł���
				if (mInvincibleTime % 10 < 5){
					mRect.Render(TextureEnemy1, 0, 0, 0, 0);
				}
				else{
					//�ړ����Ă��Ȃ��Ƃ�
					if (mMoving == false){
						if (mAniAttack == -10){
							mRect.Render(TextureEnemy1, 10, 117, 252, 8);
						}
						else if (mAniAttack > 10){
							mRect.Render(TextureEnemy1, 137, 254, 764, 520);
						}
						else if (mAniAttack > 0){
							mRect.Render(TextureEnemy1, 12, 120, 764, 520);
						}
						else if (mAniAttack > -10){
							mRect.Render(TextureEnemy1, 137, 254, 764, 520);
						}
					}
					//�ړ����Ă���Ƃ�
					else{
						if (mAniMoving % 60 < 30){
							mRect.Render(TextureEnemy1, 10, 117, 508, 264);
						}
						else if (mAniMoving % 60 < 60){
							mRect.Render(TextureEnemy1, 266, 373, 508, 264);
						}
					}
				}
			}
		}
		//���S�t���O����������
		else{
			if (mDeathCount > 30){
				mRect.Render(TextureEnemy1, 12, 120, 1020, 776);
			}
			else{
				mRect.Render(TextureEnemy1, 169, 413, 976, 866);
			}
		}
	}

	//�E����
	else{
		//���S�t���O�������Ă��Ȃ��Ƃ�
		if (mDeath == false){
			//���G�t���O�������Ă��Ȃ��Ƃ�
			if (mInvincibleFlag == false){
				//�ړ����Ă��Ȃ��Ƃ�
				if (mMoving == false){
					if (mAniAttack == -10){
						mRect.Render(TextureEnemy1, 117, 10, 252, 8);
					}
					//�U���A�j���[�V����
					else if (mAniAttack > 10){
						mRect.Render(TextureEnemy1, 254, 137, 764, 520);
					}
					else if (mAniAttack > 0){
						mRect.Render(TextureEnemy1, 120, 13, 764, 520);
					}
					else if (mAniAttack >= -10){
						mRect.Render(TextureEnemy1, 254, 137, 764, 520);
					}
				}
				//�ړ����Ă���Ƃ�
				else{
					//�ړ��A�j���[�V����
					if (mAniMoving % 60 < 30){
						mRect.Render(TextureEnemy1, 117, 10, 508, 264);
					}
					else if (mAniMoving % 60 < 60){
						mRect.Render(TextureEnemy1, 373, 266, 508, 264);
					}
				}
			}

			//���G��ԃt���O�������Ă���Ƃ�
			else{
				//�_�ł���
				if (mInvincibleTime % 10 < 5){
					mRect.Render(TextureEnemy1, 0, 0, 0, 0);
				}
				else{
					//�ړ����Ă��Ȃ��Ƃ�
					if (mMoving == false){
						if (mAniAttack == -10){
							mRect.Render(TextureEnemy1, 117, 10, 252, 8);
						}
						//�U���A�j���[�V����
						else if (mAniAttack > 10){
							mRect.Render(TextureEnemy1, 254, 137, 764, 520);
						}
						else if (mAniAttack > 0){
							mRect.Render(TextureEnemy1, 120, 13, 764, 520);
						}
						else if (mAniAttack >= -10){
							mRect.Render(TextureEnemy1, 254, 137, 764, 520);
						}
					}
					//�ړ����Ă���Ƃ�
					else{
						//�ړ��A�j���[�V����
						if (mAniMoving % 60 < 30){
							mRect.Render(TextureEnemy1, 117, 10, 508, 264);
						}
						else if (mAniMoving % 60 < 60){
							mRect.Render(TextureEnemy1, 373, 266, 508, 264);
						}
					}
				}
			}
		}

		//���S�t���O����������
		else{
			if (mDeathCount > 30){
				mRect.Render(TextureEnemy1, 120, 12, 1020, 776);
			}
			else{
				mRect.Render(TextureEnemy1, 413, 169, 976, 866);
			}
		}
	}

}

void CEnemy::Collision(CBase *i, CBase *y) {
	//�v���C���[1�Ɠ��������Ƃ�
	
		if (y->mTag == EPLAYER){
			if (y->mEnabled){
				if (mRect.Collision(y->mRect)){
					//�v���C���[�ƐڐG����ƍU���t���O������
					mAttack = true;
					mMoving = false;
					return;
				}
			}
		}


	if (mRect.y - CPlayer::spInstance->mRect.y < 20){
		if (y->mTag == EPLAYERATTACK){
			if (mRect.Collision(y->mRect)){
				//���G��ԂŖ������
				if (mInvincibleFlag == false){
					//�̗͂�����
					mHp -= 1;
					//���G��Ԃ�
					mInvincibleFlag = true;
					mInvincibleTime = INVINCIBLETIME;
				}
				return;
			}
		}
	}

}

CEnemy*CEnemy::spInstance = 0;
