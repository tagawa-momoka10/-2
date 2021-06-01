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
		//�{�̂ɒǔ����Ĉړ�����
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
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniMoving % 60 < 60){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
		}
	}

	

	//�E����
	else{
		//���G�t���O�������Ă��Ȃ��Ƃ�
		//�ړ����Ă��Ȃ��Ƃ�
		if (mMoving == false){
			if (mAniAttack == -10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			//�U���A�j���[�V����
			else if (mAniAttack > 10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniAttack > 0){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniAttack >= -10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
		}
		//�ړ����Ă���Ƃ�
		else{
			//�ړ��A�j���[�V����
			if (mAniMoving % 60 < 30){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniMoving % 60 < 60){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
		}
	}

	//���G��ԃt���O�������Ă���Ƃ�

	//�ړ����Ă��Ȃ��Ƃ�
	if (mMoving == false){
		if (mAniAttack == -10){
			mRect.Render(TextureEnemy1, 0, 600, 200, 0);
		}
		//�U���A�j���[�V����
		else if (mAniAttack > 10){
			mRect.Render(TextureEnemy1, 0, 600, 200, 0);
		}
		else if (mAniAttack > 0){
			mRect.Render(TextureEnemy1, 0, 600, 200, 0);
		}
		else if (mAniAttack >= -10){
			mRect.Render(TextureEnemy1, 0, 600, 200, 0);
		}
	}
	//�ړ����Ă���Ƃ�
	else{
		//�ړ��A�j���[�V����
		if (mAniMoving % 60 < 30){
			mRect.Render(TextureEnemy1, 0, 600, 200, 0);
		}
		else if (mAniMoving % 60 < 60){
			mRect.Render(TextureEnemy1, 0, 600, 200, 0);
		}

	}

}


void CSSearch::Collision(CBase *i, CBase *y) {
	//�v���C���[1�Ɠ��������Ƃ�
	if (y->mTag == EPLAYER){
		if (y->mEnabled){
			if (mRect.Collision(y->mRect)){
				if (mAttack == true && mAttackLag == 0){
					mEnabled = false;


				}
			}
		}
	}

}
CSSearch*CSSearch::spInstance = 0;
