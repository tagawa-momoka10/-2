#include "CEnemy2.h"
#include "CTexture.h"
#include "SampleProperty.h"
#include "CPlayer.h"
#include "CEnemyAttack.h"
#include "CSceneGame.h"
#include "DrawTaskManager.h"
#include "CScore.h"

#define SPEED 0				//�ړ����x
#define ATTACKLAG 60		//�U���J�n�܂ł̃��O
#define INVINCIBLETIME 60	//���G����
#define COMBO 3*60			//�R���{��������2�b
#define HP 2				//�̗�
#define ANIATTACK 120		//�U���A�j���[�V�����p
#define SCORE 150			//�X�R�A

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture TextureEnemy2;

CEnemy2::CEnemy2()
:mAttackLag(ATTACKLAG)
, mHp(HP)
, mInvincibleTime(0), mInvincibleFlag(false)
, mAniAttack(0)
, mAttack(false)
, mMoving(false)
, mAniMoving(0)
, mDeath(false)
, mDeathCount(0)
{
	m_Draw.RegistDraw(this, (DrawFunc)&CEnemy2::Render, DrawPriority::Transparent, "CEnemy2");
	mRect.w = 45;
	mRect.h = 45;
	mTag = EENEMY_F;
	spInstance = this;
}

void CEnemy2::Update() {

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

	//���G���Ԃ�0�ɂȂ�܂ŃJ�E���g�_�E��
	if (mInvincibleTime > 0){
		mInvincibleTime--;
	}
	//���G���Ԃ�0�ɂȂ�Ɩ��G��ԉ���
	if (mInvincibleTime <= 0){
		mInvincibleFlag = false;
	}

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
			//�U���t���O��������120�t���[����ɍU�����邽�߂̒l��ݒ�
			mAttackLag = ATTACKLAG;
		}
		else{
			CEnemyAttack *EnemyAttack = new CEnemyAttack();
			EnemyAttack->mRect.x = mRect.x - 20;
			mAniAttack = ANIATTACK;
			//�U���t���O��������120�t���[����ɍU�����邽�߂̒l��ݒ�
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
		//�v���C���[�ɒǔ����Ĉړ�����
		/*	if (mRect.x < CPlayer::spInstance->mRect.x){
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
				*/
	}

}

void CEnemy2::Render() {
	//�E����
	if (mRect.x < CPlayer::spInstance->mRect.x){
		//���S�t���O�������Ă��Ȃ��Ƃ�
		if (mDeath == false){
			//���G�t���O�������Ă��Ȃ��Ƃ�
			if (mInvincibleFlag == false){
				//�ړ����Ă��Ȃ��Ƃ�
				if (mMoving == false){
					if (mAniAttack == 0){
						mRect.Render(TextureEnemy2, 254, 130, 510, 313);
					}
					//�U�����̃A�j���[�V����
					if (mAniAttack > 60){
						mRect.Render(TextureEnemy2, 127, 3, 766, 568);
					}
					else if (mAniAttack > 0){
						mRect.Render(TextureEnemy2, 255, 131, 766, 568);
					}
				}
				//�ړ����Ă���Ƃ�
				else{
					if (mAniMoving % 80 < 20){
						mRect.Render(TextureEnemy2, 126, 2, 510, 313);
					}
					else if (mAniMoving % 80 < 40){
						mRect.Render(TextureEnemy2, 254, 130, 510, 313);
					}
					else if (mAniMoving % 80 < 60){
						mRect.Render(TextureEnemy2, 383, 259, 510, 313);
					}
					else if (mAniMoving % 80 < 80){
						mRect.Render(TextureEnemy2, 254, 130, 510, 313);
					}
				}
			}
			//���G�t���O�������Ă��Ȃ��Ƃ�
			else{
				//�_�ł���
				if (mInvincibleTime % 10 < 5){
					mRect.Render(TextureEnemy2, 0, 0, 0, 0);
				}
				else{
					//�ړ����Ă��Ȃ��Ƃ�
					if (mMoving == false){
						if (mAniAttack == 0){
							mRect.Render(TextureEnemy2, 254, 130, 510, 313);
						}
						//�U�����̃A�j���[�V����
						if (mAniAttack > 60){
							mRect.Render(TextureEnemy2, 127, 3, 766, 568);
						}
						else if (mAniAttack > 0){
							mRect.Render(TextureEnemy2, 255, 131, 766, 568);
						}
					}
					//�ړ����Ă���Ƃ�
					else{
						if (mAniMoving % 80 < 20){
							mRect.Render(TextureEnemy2, 126, 2, 510, 313);
						}
						else if (mAniMoving % 80 < 40){
							mRect.Render(TextureEnemy2, 254, 130, 510, 313);
						}
						else if (mAniMoving % 80 < 60){
							mRect.Render(TextureEnemy2, 383, 259, 510, 313);
						}
						else if (mAniMoving % 80 < 80){
							mRect.Render(TextureEnemy2, 254, 130, 510, 313);
						}
					}
				}
			}
		}
		//���S�t���O�������Ă���Ƃ�
		else{
			if (mDeathCount > 30){
				mRect.Render(TextureEnemy2, 252, 128, 1013, 816);
			}
			else{
				mRect.Render(TextureEnemy2, 477, 280, 980, 856);
			}
		}
	}
	//������
	else{
		//���S�t���O�������Ă��Ȃ��Ƃ�
		if (mDeath == false){
			//���G�t���O�������Ă��Ȃ��Ƃ�
			if (mInvincibleFlag == false){
				if (mMoving == false){
					if (mAniAttack == 0){
						mRect.Render(TextureEnemy2, 130, 254, 510, 313);
					}
					//�U�����̃A�j���[�V����
					if (mAniAttack > 60){
						mRect.Render(TextureEnemy2, 3, 127, 766, 568);
					}
					else if (mAniAttack > 0){
						mRect.Render(TextureEnemy2, 131, 255, 766, 568);
					}
				}
				else{
					if (mAniMoving % 80 < 20){
						mRect.Render(TextureEnemy2, 2, 126, 510, 313);
					}
					else if (mAniMoving % 80 < 40){
						mRect.Render(TextureEnemy2, 130, 254, 510, 313);
					}
					else if (mAniMoving % 80 < 60){
						mRect.Render(TextureEnemy2, 259, 383, 510, 313);
					}
					else if (mAniMoving % 80 < 80){
						mRect.Render(TextureEnemy2, 130, 254, 510, 313);
					}
				}
			}
			//���G�t���O�������Ă���Ƃ�
			else{
				//�_�ł���
				if (mInvincibleTime % 10 < 5){
					mRect.Render(TextureEnemy2, 0, 0, 0, 0);
				}
				else{
					if (mMoving == false){
						if (mAniAttack == 0){
							mRect.Render(TextureEnemy2, 130, 254, 510, 313);
						}
						//�U�����̃A�j���[�V����
						if (mAniAttack > 60){
							mRect.Render(TextureEnemy2, 3, 127, 766, 568);
						}
						else if (mAniAttack > 0){
							mRect.Render(TextureEnemy2, 131, 255, 766, 568);
						}
					}
					else{
						if (mAniMoving % 80 < 20){
							mRect.Render(TextureEnemy2, 2, 126, 510, 313);
						}
						else if (mAniMoving % 80 < 40){
							mRect.Render(TextureEnemy2, 130, 254, 510, 313);
						}
						else if (mAniMoving % 80 < 60){
							mRect.Render(TextureEnemy2, 259, 383, 510, 313);
						}
						else if (mAniMoving % 80 < 80){
							mRect.Render(TextureEnemy2, 130, 254, 510, 313);
						}
					}
				}
			}
		}
		//���S�t���O�������Ă���Ƃ�
		else{
			if (mDeathCount > 30){
				mRect.Render(TextureEnemy2, 128, 252, 1013, 816);
			}
			else{
				mRect.Render(TextureEnemy2, 280, 477, 980, 856);
			}
		}
	}
}

void CEnemy2::Collision(CBase *i, CBase *y) {
	if (mRect.y - CPlayer::spInstance->mRect.y < 20){
		//�v���C���[�̍U���ɓ��������Ƃ�
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

CEnemy2*CEnemy2::spInstance = 0;