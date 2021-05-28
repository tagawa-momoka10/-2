#include "CSSearch.h"
#include "CTexture.h"
#include "SampleProperty.h"
#include "CPlayer.h"
#include "CEnemyAttack.h"
#include "CSceneGame.h"
#include "DrawTaskManager.h"
#include "CScore.h"
#include "CEnemy.h"

#define ANIATTACK 20		//�U���A�j���[�V�����p

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture TextureEnemy1;

CSSearch::CSSearch()
: mMoving(true)
, mAniAttack(-10)
, mAniMoving(0)
{
	m_Draw.RegistDraw(this, (DrawFunc)&CSSearch::Render, DrawPriority::Transparent, "CSSearch");
	mRect.w = 300;
	mRect.h = 100;

	mTag = EENEMMY_SS;
	spInstance = this;
}

void CSSearch::Update() {

	if (mAniAttack > -10){
		mAniAttack--;
	}

	if (mAttack == false){
		mMoving = true;
		mAniMoving++;
		//�v���C���[�ɒǔ����Ĉړ�����
		if (mRect.x < CEnemy::spInstance->mRect.x){
		}
		else if (CEnemy::spInstance->mRect.x < mRect.x){
		}

		if (mRect.y < CEnemy::spInstance->mRect.y){
			if (mRect.y > -140){
			}
		}
		else if (CEnemy::spInstance->mRect.y < mRect.y){
		}

	}


	if (mRect.y>CEnemy::spInstance->mRect.y){
		DrawTaskManager::GetInstance()->ChangePriority(&m_Draw);
	}


}

void CSSearch::Render() {
	//������
	if (mRect.x > CEnemy::spInstance->mRect.x){


		//�ړ����Ă��Ȃ��Ƃ�
		if (mMoving == false){
			if (mAniAttack == -10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
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
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniMoving % 60 < 60){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
		}

		//���G�t���O�������Ă��Ȃ��Ƃ�

		//�ړ����Ă��Ȃ��Ƃ�
		if (mMoving == false){
			if (mAniAttack == -10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniAttack > 10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniAttack > 0){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniAttack > -10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
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

	

	//�E����
	else{
		//���G�t���O�������Ă��Ȃ��Ƃ�
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


void CSSearch::Collision(CBase *i, CBase *y) {
	//�v���C���[1�Ɠ��������Ƃ�

	if (y->mTag == EPLAYER){
		if (y->mEnabled){
			if (mRect.Collision(y->mRect)){
				//�v���C���[�ƐڐG����ƍU���t���O������
				mAttack = true;
				mMoving = false;
				//�v���C���[�ɒǔ����Ĉړ�����
				if (mRect.x < CEnemy::spInstance->mRect.x){

				}
				else if (CEnemy::spInstance->mRect.x < mRect.x){
				}

				if (mRect.y < CEnemy::spInstance->mRect.y){
					if (mRect.y > -140){
					}
				}
				else if (CEnemy::spInstance->mRect.y < mRect.y){
				}
				return;

			}
		}
	}

	if (mRect.y - CEnemy::spInstance->mRect.y < 20){
		if (y->mTag == EPLAYERATTACK){
			if (mRect.Collision(y->mRect)){
				//���G��ԂŖ������

				return;
			}
		}
	}
}
CSSearch*CSSearch::spInstance = 0;
